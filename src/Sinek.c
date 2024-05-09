#include "../include/Sinek.h"

Sinek sinekOlustur(int sayDeger, int xIndex, int yIndex, char tur)
{
    Sinek this;

    this = (Sinek)malloc(sizeof(struct SINEK));
    this->super = bocekOlustur(sayDeger, xIndex, yIndex, tur);

    this->yokEt = &sinekYokEt;

    return this;
}

void sinekYokEt(const Sinek this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->super->yokEt(this->super->super);
    this->super->yokEt(this->super);
    free(this);
}
