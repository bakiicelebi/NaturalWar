#include "../include/Habitat.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Habitat h = habitatOlustur();

    dosyaOku(h);

    int canliSayisi = h->canliSayisi;
    int kazananIndex = -1;
    bool kontrol = true;

    system("CLS");
    for (int i = 0; i < canliSayisi; ++i)
    {
        if (h->Canlilar[i]->xIndex == 0 && i != 0)
        {
            printf("\n");
        }

        if (h->Canlilar[i]->yasiyorMu == true)
        {
            printf("%c ", h->Canlilar[i]->tur);
        }
        else
        {
            printf("X ");
        }
    }
    system("Pause");
    system("CLS");
    while (kontrol)
    {
        char ilk = 'N';
        int ilkIndex = 0;
        int ikinciIndex = 0;
        char ikinci = 'N';
        char yenilen = 'N';

        for (int i = 0; i < canliSayisi; i++)
        {
            if (ilk == 'N' || ikinci == 'N')
            {
                if (h->Canlilar[i]->yasiyorMu == true)
                {
                    if (ilk == 'N')
                    {
                        ilk = h->Canlilar[i]->tur;
                        ilkIndex = i;
                    }
                    else
                    {
                        ikinci = h->Canlilar[i]->tur;
                        ikinciIndex = i;
                    }
                }
            }
        }

        if (ikinci == 'N')
        {
            kontrol = false;
            kazananIndex = ilkIndex;
        }
        else
        {

            if (ilk == ikinci)
            {
                if (h->Canlilar[ilkIndex]->sayDeger != h->Canlilar[ikinciIndex]->sayDeger)
                {
                    if (h->Canlilar[ilkIndex]->sayDeger > h->Canlilar[ikinciIndex]->sayDeger)
                    {
                        h->Canlilar[ikinciIndex]->yasiyorMu = false;
                    }
                    else
                    {
                        h->Canlilar[ilkIndex]->yasiyorMu = false;
                    }
                }
                else
                {
                    h->Canlilar[ikinciIndex]->yasiyorMu = false;
                }
            }
            else
            {
                yenilen = kapistirVeYenileniDondur(ilk, ikinci);

                if (ilk == yenilen)
                {
                    h->Canlilar[ilkIndex]->yasiyorMu = false;
                }
                else if (ikinci == yenilen)
                {
                    h->Canlilar[ikinciIndex]->yasiyorMu = false;
                }
            }
        }

        for (int i = 0; i < canliSayisi; ++i)
        {
            if (h->Canlilar[i]->xIndex == 0 && i != 0)
            {
                printf("\n");
            }

            if (h->Canlilar[i]->yasiyorMu == true)
            {
                printf("%c ", h->Canlilar[i]->tur);
            }
            else
            {
                printf("X ");
            }
        }

        printf("\n");
        if (kontrol)
        {
            Sleep(600);
            system("CLS");
        }
        
    }

    printf("Kazanan: %c : (%d, %d) ", h->Canlilar[kazananIndex]->tur, h->Canlilar[kazananIndex]->yIndex, h->Canlilar[kazananIndex]->xIndex);

    habitatYokEt(h);

    return 0;
}
