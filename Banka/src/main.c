#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dosyaoku.h"
#include "cJSON.h"
#include "hisseler.h"
#include "portfoy.h"
#include "emirler.h"
#include "bankaalis.h"
#include "bankasatis.h"
#include "guncelPortfoy.h"
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
    Hisseler *hisselerReferans = createHisselerConstructer("", "", 0);
    for (int i = 0; i < count; i++)
    {
        cJSON *hisse = cJSON_GetArrayItem(hisseler, i);
        char *id = cJSON_GetObjectItem(hisse, "_id")->valuestring;
        char *sembol = cJSON_GetObjectItem(hisse, "Sembol")->valuestring;
        char *ad = cJSON_GetObjectItem(hisse, "Ad")->valuestring;
        double fiyat = cJSON_GetObjectItem(hisse, "Fiyat")->valuedouble;
        hisselerReferans = addHisseler(hisselerReferans, ad, sembol, fiyat);
    }

    cJSON *root1 = cJSON_Parse(oku("doc/portfoy.json"));
    cJSON *portfoyler = cJSON_GetObjectItem(root1, "Portfoy");
    cJSON *portfoylerCount = NULL;
    int countPortfoy = 0;
    cJSON_ArrayForEach(portfoylerCount, portfoyler)
    {
        countPortfoy++;
    }
    Portfoy *portfoyReferans = createConstructerPortfoy("", 0, 0);
    for (int i = 0; i < countPortfoy; i++)
    {
        cJSON *portfoy = cJSON_GetArrayItem(portfoyler, i);
        char *id = cJSON_GetObjectItem(portfoy, "_id")->valuestring;
        char *sembol = cJSON_GetObjectItem(portfoy, "Sembol")->valuestring;
        double maliyet = cJSON_GetObjectItem(portfoy, "Maliyet")->valuedouble;
        double adet = cJSON_GetObjectItem(portfoy, "Adet")->valuedouble;
        portfoyReferans = addPortfoy(portfoyReferans, sembol, maliyet, adet);
    }

    cJSON *root2 = cJSON_Parse(oku("doc/emirler.json"));
    cJSON *emirler = cJSON_GetObjectItem(root2, "Emirler");
    cJSON *emirlerCount = NULL;
    int countEmirler = 0;
    cJSON_ArrayForEach(emirlerCount, emirler)
    {
        countEmirler++;
    }
    Emirler *EmirlerReferans = emirlerConstructer("", "", 0);
    for (int i = 0; i < countEmirler; i++)
    {
        cJSON *emir = cJSON_GetArrayItem(emirler, i);
        char *id = cJSON_GetObjectItem(emir, "_id")->valuestring;
        char *sembol = cJSON_GetObjectItem(emir, "Sembol")->valuestring;
        char *islem = cJSON_GetObjectItem(emir, "Islem")->valuestring;
        int adet = cJSON_GetObjectItem(emir, "Adet")->valueint;
        EmirlerReferans = addEmirler(EmirlerReferans, sembol, islem, adet);
    }
    BankaAlis *BankaAlisReferans = alisConstructer("", 0, 0.0);
    BankaSatis *BankaSatisReferans = satisConsturcter("", 0, "");
    Emirler *emirIter;
    Portfoy *portfoyIter;
    Hisseler *hisseIter;
    BankaAlis *alisIter;
    BankaSatis *satisIter;
    int bankaAlisSayac = 0, bankaSatisSayac = 0, guncelPortfoySayac = 0;
    for (portfoyIter = portfoyReferans; portfoyIter->next != NULL; portfoyIter = portfoyIter->next)
    {
        insertFirst(portfoyIter->sembol, portfoyIter->maliyet, portfoyIter->adet);
        guncelPortfoySayac++;
    }
    int emirlerSatis = 0;
    for (emirIter = EmirlerReferans; NULL != emirIter; emirIter = emirIter->next)
    {
        if (strcmp(emirIter->islem, "SATIS") == 0)
        {
            emirlerSatis++;
        }
    }
    if (emirlerSatis > countPortfoy)
    {
        printf("Satis Kadar Portfoy Olmalidir");
    }
    else
    {

        for (emirIter = EmirlerReferans; NULL != emirIter; emirIter = emirIter->next)
        {
            double maliyetPortfoy;
            int maliyetAdetPortfoy;
            double hisseFiyati = 0;
            char *hisseSembol;
            int flag = 0;
            if (strcmp(emirIter->islem, "SATIS") == 0)
            {
                for (portfoyIter = portfoyReferans; NULL != portfoyIter->next; portfoyIter = portfoyIter->next)
                {
                    if (strcmp(emirIter->sembol, portfoyIter->sembol) == 0)
                    {
                        for (hisseIter = hisselerReferans; NULL != hisseIter->next; hisseIter = hisseIter->next)
                        {
                            if (strcmp(emirIter->sembol, hisseIter->sembol) == 0)
                            {
                                double guncelFiyat = emirIter->adet * hisseIter->fiyat;
                                double maliyet = emirIter->adet * portfoyIter->maliyet;
                                if (guncelFiyat > maliyet)
                                {

                                    double gonder = guncelFiyat - maliyet;
                                    BankaSatisReferans = satisEkleme(BankaSatisReferans, emirIter->sembol, gonder, "Kar");
                                    struct node *foundLink = find(emirIter->sembol);
                                    delete (emirIter->sembol);
                                    bankaSatisSayac++;
                                    guncelPortfoySayac--;
                                }
                                else
                                {
                                    double gonder = maliyet - guncelFiyat;
                                    BankaSatisReferans = satisEkleme(BankaSatisReferans, emirIter->sembol, gonder, "Zarar");
                                    struct node *foundLink = find(emirIter->sembol);
                                    delete (emirIter->sembol);
                                    bankaSatisSayac++;
                                    guncelPortfoySayac--;
                                }
                            }
                        }
                    }
                }
            }
            if (strcmp(emirIter->islem, "ALIS") == 0)
            {
                for (portfoyIter = portfoyReferans; NULL != portfoyIter; portfoyIter = portfoyIter->next)
                {
                    if (strcmp(emirIter->sembol, portfoyIter->sembol) == 0)
                    {
                        maliyetPortfoy = portfoyIter->maliyet;
                        maliyetAdetPortfoy = portfoyIter->adet;
                        flag = 1;
                    }
                }
                for (hisseIter = hisselerReferans; NULL != hisseIter; hisseIter = hisseIter->next)
                {
                    if (strcmp(emirIter->sembol, hisseIter->sembol) == 0)
                    {
                        hisseFiyati = hisseIter->fiyat;
                        hisseSembol = hisseIter->sembol;
                    }
                }
                if (flag == 1)
                {
                    double guncelFiyat = emirIter->adet * hisseFiyati;
                    double maliyetHesabi = maliyetAdetPortfoy * maliyetPortfoy;
                    double yeniMaliyet = (guncelFiyat + maliyetHesabi) / (emirIter->adet + maliyetAdetPortfoy);
                    double a = emirIter->adet + maliyetAdetPortfoy;
                    BankaAlisReferans = alisEkleme(BankaAlisReferans, hisseSembol, a, yeniMaliyet);
                    struct node *foundLink = find(emirIter->sembol);
                    delete (emirIter->sembol);
                    bankaAlisSayac++;
                }
                else
                {
                    BankaAlisReferans = alisEkleme(BankaAlisReferans, hisseSembol, emirIter->adet, hisseFiyati);
                    bankaAlisSayac++;
                }
            }
        }
    }
    double karPara = 0;
    double zararPara = 0;
    double satisSayisi = 0;
    double karZararPara = 0;
    int tutan = 0;
    printf("Satislar Kar/Zarar:\n");
    for (satisIter = BankaSatisReferans; NULL != satisIter->next && bankaSatisSayac != tutan; satisIter = satisIter->next, tutan++)
    {
        printf("%s: %g TL %s\n", satisIter->sembolSatis, satisIter->satisTutar, satisIter->karZarar);
        if (strcmp(satisIter->karZarar, "Kar") == 0)
        {
            karPara += satisIter->satisTutar;
        }
        else
        {
            zararPara += satisIter->satisTutar;
        }
        satisSayisi++;
        if (satisIter->next->next == NULL)
        {
            if (karPara > zararPara)
            {
                karZararPara = karPara - zararPara;
                printf("Toplam Kar/Zarar: + %g TL\n", karZararPara);
            }
            else
            {
                karZararPara = karPara - zararPara;
                printf("Toplam Kar/Zarar: - %g TL\n", karZararPara);
            }
        }
    }
    tutan = 0;
    printf("\n");
    printf("Guncel Portfoy:\n");
    for (alisIter = BankaAlisReferans; NULL != alisIter->next && bankaSatisSayac != tutan; alisIter = alisIter->next, tutan++)
    {
        printf("Hisse: %s\nAdet: %d\nMaliyet: %g TL\n", alisIter->sembolAlis, alisIter->adet, alisIter->alisMaliyet);
    }
    printf("-------------------\n");
    printList();
    free(alisIter);
    free(emirIter);
    free(hisseIter);
    free(satisIter);
    free(portfoyIter);
    deleteAlis(BankaAlisReferans);
    deleteSatis(BankaSatisReferans);
    deleteEmirler(EmirlerReferans);
    deletePortfoy(portfoyReferans);
    deleteHisseler(hisselerReferans);
    return 0;
}
