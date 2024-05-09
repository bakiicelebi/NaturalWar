#ifndef BOCEK_H
#define BOCEK_H

#include "stdio.h"
#include "stdlib.h"

#include "Canli.h"

struct BOCEK
{
    Canli super;

    void (*yokEt)(struct BOCEK *);
};

typedef struct BOCEK *Bocek;

Bocek bocekOlustur(int, int, int, char);
void bocekYokEt(const Bocek);

#endif
