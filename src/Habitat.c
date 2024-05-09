#include "../include/Habitat.h"
#include <stdio.h>
#include <stdlib.h>

#include "../include/Canli.h"
#include "../include/Bitki.h"
#include "../include/Pire.h"
#include "../include/Bocek.h"
#include "../include/Sinek.h"

#define INITIAL_CAPACITY 10

Habitat habitatOlustur()
{
    Habitat this = (Habitat)malloc(sizeof(struct HABITAT));
    if (this == NULL)
    {
        return NULL;
    }

    this->Canlilar = (Canli *)malloc(INITIAL_CAPACITY * sizeof(Canli));
    if (this->Canlilar == NULL)
    {
        free(this);
        return NULL;
    }

    this->canliSayisi = 0;
    this->kapasite = INITIAL_CAPACITY;

    return this;
}

void habitatYokEt(Habitat this)
{
    if (this == NULL)
    {
        return;
    }

    for (int i = 0; i < this->canliSayisi; ++i)
    {
        if (this->Canlilar[i] != NULL)
        {
            free(this->Canlilar[i]);
        }
    }

    free(this->Canlilar);
    free(this);
}

void dinamikDiziGenislet(Habitat this)
{
    if (this->canliSayisi >= this->kapasite)
    {
        this->kapasite *= 2;
        this->Canlilar = (Canli *)realloc(this->Canlilar, this->kapasite * sizeof(Canli));
        if (this->Canlilar == NULL)
        {
            exit(EXIT_FAILURE);
        }
    }
}

void dosyaOku(Habitat this)
{
    FILE *dosya;
    int sayi;

    dosya = fopen("dosya.txt", "r");
    if (dosya == NULL)
    {
        printf("Dosya acilmadi!");
        return;
    }

    int xIndex = 0, yIndex = 0;
    char tur;

    while (fscanf(dosya, "%d", &sayi) != EOF)
    {
        dinamikDiziGenislet(this);

        char deger = turBelirle(sayi);
        if (deger == 'B')
        {
            Bitki b = bitkiOlustur(sayi, xIndex, yIndex, deger);
            this->Canlilar[this->canliSayisi++] = b->super;
        }
        else if (deger == 'C')
        {
            Bocek c = bocekOlustur(sayi, xIndex, yIndex, deger);
            this->Canlilar[this->canliSayisi++] = c->super;
        }
        else if (deger == 'S')
        {
            Sinek s = sinekOlustur(sayi, xIndex, yIndex, deger);
            this->Canlilar[this->canliSayisi++] = s->super->super;
        }
        else if (deger == 'P')
        {
            Pire p = pireOlustur(sayi, xIndex, yIndex, deger);
            this->Canlilar[this->canliSayisi++] = p->super->super;
        }

        if (fgetc(dosya) == '\n')
        {
            ++yIndex;
            xIndex = 0;
        }
        else
        {
            ++xIndex;
        }
    }

    fclose(dosya);
}

char turBelirle(int sayi)
{
    if (sayi >= 1 && sayi <= 9)
    {
        return 'B';
    }
    else if (sayi >= 10 && sayi <= 20)
    {
        return 'C';
    }
    else if (sayi >= 21 && sayi <= 50)
    {
        return 'S';
    }
    else if (sayi >= 51 && sayi <= 99)
    {
        return 'P';
    }
    else
    {
        printf("Sayi Dogru Aralikta Degil!");
        return '\0';
    }
}

char kapistirVeYenileniDondur(char ilk, char ikinci)
{
    if (ilk == 'B')
    {
        if (ikinci == 'P' || ikinci == 'S')
        {
            return ikinci;
        }
        if (ikinci == 'C')
        {
            return ilk;
        }
    }
    if (ilk == 'C')
    {
        if (ikinci == 'B' || ikinci == 'P')
        {
            return ikinci;
        }
        if (ikinci == 'S')
        {
            return ilk;
        }
    }
    if (ilk == 'S')
    {
        if (ikinci == 'P' || ikinci == 'C')
        {
            return ikinci;
        }
        if (ikinci == 'B')
        {
            return ilk;
        }
    }
    if (ilk == 'P')
    {
        return ilk;
    }

    return ilk;
}
