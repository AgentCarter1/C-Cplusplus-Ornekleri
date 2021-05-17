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

typedef struct emirler
{
    char *sembol;
    char *islem;
    int adet;
    struct emirler *next;
} Emirler;

Emirler *emirlerConstructer(char *, char *, int);

void deleteEmirler(Emirler *);

Emirler *addEmirler(Emirler *, char *, char *, int);