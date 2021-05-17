#include <stdio.h>
#include <stdlib.h>
#include "hisseler.h"

Hisseler *createHisselerConstructer(char *ad, char *sembol, double fiyat)
{
    Hisseler *newWords = malloc(sizeof(Hisseler));
    if (NULL != newWords)
    {
        newWords->ad = ad;
        newWords->fiyat = fiyat;
        newWords->sembol = sembol;
        newWords->next = NULL;
    }
    return newWords;
}

void deleteHisseler(Hisseler *oldWords)
{
    if (NULL != oldWords->next)
    {
        deleteHisseler(oldWords->next);
    }
    free(oldWords);
}

Hisseler *addHisseler(Hisseler *wordList, char *ad,char*sembol,double fiyat)
{
    Hisseler *newWords = createHisselerConstructer(ad,sembol,fiyat);
    if (NULL != newWords)
    {
        newWords->next = wordList;
    }
    return newWords;
}

