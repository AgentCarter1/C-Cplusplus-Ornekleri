#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Calculator
{ 
    void (*basamaklarinaAyir)(int *, int *, int *, int *, int);
    void (*birSayininToplaminiHesapla)(int *, int *, int *, int *, int, int *);
    void (*tumSayininToplamlariniHesapla)(int *, int *, int *, int *, int, int, int, int, int *);
};

typedef struct Calculator *calculator;
calculator CalculatorKurucu();
void BasamaklarinaAyir(int *, int *, int *, int *, int);
void BirSayininToplaminiHesapla(int *, int *, int *, int *, int, int *);
void TumSayininToplamlariniHesapla(int *, int *, int *, int *, int, int, int, int, int *);

#endif