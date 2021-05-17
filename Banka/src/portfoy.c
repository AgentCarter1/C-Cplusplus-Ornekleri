#include <stdio.h>
#include <stdlib.h>
#include "portfoy.h"

Portfoy *createConstructerPortfoy(char *sembol, double maliyet, int adet)
{
    Portfoy *newWords = malloc(sizeof(Portfoy));
    if (NULL != newWords)
    {
        newWords->maliyet = maliyet;
        newWords->adet = adet;
        newWords->sembol = sembol;
        newWords->next = NULL;
    }
    return newWords;
}

void deletePortfoy(Portfoy *oldWords)
{
    if (NULL != oldWords->next)
    {
        deletePortfoy(oldWords->next);
    }
    free(oldWords);
}

Portfoy *addPortfoy(Portfoy *wordList, char *sembol, double maliyet, int adet)
{
    Portfoy *newWords = createConstructerPortfoy(sembol, maliyet, adet);
    if (NULL != newWords)
    {
        newWords->next = wordList;
    }
    return newWords;
}


