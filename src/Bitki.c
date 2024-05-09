#include "../include/Bitki.h"

Bitki bitkiOlustur(int sayDeger, int xIndex, int yIndex, char tur)
{
    Bitki this;

    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super = canliOlustur(sayDeger, xIndex, yIndex, tur);

    this->yokEt = &bitkiYokEt;

    return this;
}

void bitkiYokEt(const Bitki this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->yokEt(this->super);
    free(this);
}