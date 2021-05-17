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

typedef struct bankaAlis
{
    char *sembolAlis;
    int adet;
    double alisMaliyet;
    struct bankaAlis *next;
} BankaAlis;

BankaAlis *alisConstructer(char *, int, double);
BankaAlis *alisEkleme(BankaAlis *, char *, int, double);

void deleteAlis(BankaAlis *); 
