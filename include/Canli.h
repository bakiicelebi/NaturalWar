#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef enum Bool
{
    false,
    true
} bool;

struct CANLI
{
    int sayDeger;
    int xIndex;
    int yIndex;
    char tur;
    bool yasiyorMu;

    void (*yokEt)(struct CANLI *);
};

typedef struct CANLI *Canli;

Canli canliOlustur(int, int, int, char);
void canliYokEt(const Canli);

#endif
