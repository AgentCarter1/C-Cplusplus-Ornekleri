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

typedef struct hisseler
{
    char *ad;
    char*sembol;
    double fiyat;
    struct hisseler *next;
} Hisseler;

Hisseler *createHisselerConstructer(char *,char*,double);

void deleteHisseler(Hisseler *);

Hisseler *addHisseler(Hisseler *, char *,char*,double);