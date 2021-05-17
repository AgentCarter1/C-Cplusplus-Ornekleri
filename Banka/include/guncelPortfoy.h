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

struct node
{
    char *sembol;
    double maliyet;
    int adet;
    struct node *next;
};
void printList();
void insertFirst(char *, double, int);
struct node *find(char *);
struct node *delete (char *);