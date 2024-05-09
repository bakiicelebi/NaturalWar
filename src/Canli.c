#include "../include/Canli.h"

Canli canliOlustur(int sayDeger, int xIndex, int yIndex, char tur)
{
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->sayDeger = sayDeger;
    this->xIndex = xIndex;
    this->yIndex = yIndex;
    this->tur = tur;
    this->yasiyorMu = true;

    this->yokEt = &canliYokEt;
    return this;
}

void canliYokEt(const Canli this)
{
    if (this == NULL)
    {
        return;
    }
    free(this);
}