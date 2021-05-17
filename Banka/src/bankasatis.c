#include <stdio.h>
#include <stdlib.h>
#include "bankasatis.h"

BankaSatis *satisConsturcter(char *alisSembol, double satisTutar,char *karZarar)
{
    BankaSatis *newWords = malloc(sizeof(BankaSatis));
    if (NULL != newWords)
    {
        newWords->sembolSatis = alisSembol;
        newWords->satisTutar = satisTutar;
        newWords->karZarar=karZarar;
    }
    return newWords;
}
BankaSatis *satisEkleme(BankaSatis * wordList, char *satisSembol, double satisTutar,char *karZarar)
{
    BankaSatis *newWords = satisConsturcter(satisSembol, satisTutar,karZarar);
    if (NULL != newWords)
    {
        newWords->next = wordList;
    }
    return newWords;
}

void deleteSatis(BankaSatis *oldWords)
{
    if (NULL != oldWords->next)
    {
        deleteSatis(oldWords->next);
    }
    free(oldWords);
}







