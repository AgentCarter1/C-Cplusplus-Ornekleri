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

typedef struct bankaSatis
{
    char *sembolSatis;
    double satisTutar;
    char*karZarar;
    struct bankaSatis *next;
} BankaSatis;

BankaSatis *satisConsturcter(char *, double,char*);
BankaSatis *satisEkleme(BankaSatis *, char *, double,char*);
void deleteSatis(BankaSatis *);