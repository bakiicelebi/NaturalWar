#ifndef HABITAT_HPP
#define HABITAT_HPP

#include "Canli.h"

struct HABITAT
{
    Canli *Canlilar;
    int canliSayisi;
    int kapasite; // Kapasite bilgisini ekledik

    void (*dosyaOku)(struct HABITAT *);
    char (*turBelirle)(int);
    void (*yokEt)(struct HABITAT *);
    char (*kapistirVeYenileniDondur)(char, char);
};

typedef struct HABITAT *Habitat;

void dosyaOku(Habitat this);
char turBelirle(int sayi);
Habitat habitatOlustur();
void habitatYokEt(Habitat this);
char kapistirVeYenileniDondur(char ilk, char ikinci);

#endif