#include "../include/Pire.h"

Pire pireOlustur(int sayDeger, int xIndex, int yIndex, char tur)
{
    Pire this;

    this = (Pire)malloc(sizeof(struct PIRE));
    this->super = bocekOlustur(sayDeger, xIndex, yIndex, tur);

    this->yokEt = &pireYokEt;

    return this;
}

void pireYokEt(const Pire this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->super->yokEt(this->super->super);
    this->super->yokEt(this->super);
    free(this);
}