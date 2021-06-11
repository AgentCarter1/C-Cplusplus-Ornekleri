#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cJSON.h"
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
int main()
{	
    cJSON *root = cJSON_Parse(oku("doc/hisseler.json"));
    cJSON *hisseler = cJSON_GetObjectItem(root, "Hisseler");
    cJSON *hisselerCount = NULL;
    int count = 0;
    cJSON_ArrayForEach(hisselerCount, hisseler)
    {
        count++;
    }   
    for (int i = 0; i < count; i++)
    {
        cJSON *hisse = cJSON_GetArrayItem(hisseler, i);
        char* id = cJSON_GetObjectItem(hisse, "_id")->valuestring;
        char* sembol = cJSON_GetObjectItem(hisse, "Sembol")->valuestring;
        char* ad = cJSON_GetObjectItem(hisse, "Ad")->valuestring;
        double fiyat = cJSON_GetObjectItem(hisse, "Fiyat")->valuedouble;
		printf("Hisse Sembol: %s\nHisse Adi: %s\nHisse Fiyati: %f\n\n",sembol,ad,fiyat);      
    }
  
    return 0;
}
