/**
* @file           ödev2
* @description    Json Dosyasından Veriler Alınıp Değerler Karşılaştırıldı
* @course         1B
* @assignment     2. Ödev
* @date           15.05.2021
* @author         Mustafa Burak AYDIN    B191210080    mustafa.aydin21@ogr.sakarya.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct portfoy
{
    double maliyet;
    char*sembol;
    int adet;
    struct portfoy *next;
} Portfoy;

Portfoy *createConstructerPortfoy(char*,double,int);

void deletePortfoy(Portfoy *);

Portfoy *addPortfoy(Portfoy *, char*,double,int);
