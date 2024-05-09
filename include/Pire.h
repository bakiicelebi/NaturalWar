#ifndef PIRE_H
#define PIRE_H

#include "stdio.h"
#include "stdlib.h"

#include "Bocek.h"

struct PIRE
{
    Bocek super;

    void (*yokEt)(struct PIRE *);
};

typedef struct PIRE *Pire;

Pire pireOlustur(int, int, int, char );
void pireYokEt(const Pire);

#endif
