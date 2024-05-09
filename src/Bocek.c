#include "../include/Bocek.h"

Bocek bocekOlustur(int sayDeger, int xIndex, int yIndex, char tur)
{
    Bocek this;

    this = (Bocek)malloc(sizeof(struct BOCEK));
    this->super = canliOlustur(sayDeger, xIndex, yIndex, tur);

    this->yokEt = &bocekYokEt;

    return this;
}

void bocekYokEt(const Bocek this)
{
    if (this == NULL)
    {
        return;
    }
    this->super->yokEt(this->super);
    free(this);
}