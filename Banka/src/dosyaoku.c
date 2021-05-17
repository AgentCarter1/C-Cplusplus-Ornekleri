#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dosyaoku.h"

char *oku(char *yol)
{
    char *icerik = NULL;
    int boyut = 0;
    FILE *fp;
    fp = fopen(yol, "r");
    if (!fp)
        return NULL;
    fseek(fp, 0, SEEK_END);
    boyut = ftell(fp);
    rewind(fp);
    icerik = (char *)malloc(sizeof(char) * (boyut + 1));
    size_t toplamUzunluk = fread(icerik, 1, boyut, fp);
    icerik[toplamUzunluk] = '\0';
    fclose(fp);
    return icerik;
}
