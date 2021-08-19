#ifndef DOSYA_H
#define DOSYA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Calculator.h"
struct Dosya
{ 
    void (*dosyaOku)();
};

typedef struct Dosya *dosya;
dosya DosyaKurucu();
void DosyaOku();

#endif