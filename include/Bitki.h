#ifndef BITKI_H
#define BITKI_H

#include "stdio.h"
#include "stdlib.h"

#include "Canli.h"

struct BITKI
{
    Canli super;
    
    void (*yokEt)(struct BITKI *);
};

typedef struct BITKI *Bitki;

Bitki bitkiOlustur(int, int, int, char);
void bitkiYokEt(const Bitki);

#endif
