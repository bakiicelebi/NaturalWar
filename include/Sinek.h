#ifndef SINEK_H
#define SINEK_H

#include "stdio.h"
#include "stdlib.h"

#include "Bocek.h"

struct SINEK
{
    Bocek super;

    void (*yokEt)(struct SINEK *);
};

typedef struct SINEK *Sinek;

Sinek sinekOlustur(int, int, int, char);
void sinekYokEt(const Sinek);

#endif
