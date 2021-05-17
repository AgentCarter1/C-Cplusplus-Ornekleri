#include <stdio.h>
#include <stdlib.h>
#include "emirler.h"

Emirler *emirlerConstructer(char *sembol, char *islem, int adet)
{
    Emirler *newWords = malloc(sizeof(Emirler));
    if (NULL != newWords)
    {
        newWords->sembol = sembol;
        newWords->islem = islem;
        newWords->adet = adet;
        newWords->next = NULL;
    }
    return newWords;
}

void deleteEmirler(Emirler *oldWords)
{
    if (NULL != oldWords->next)
    {
        deleteEmirler(oldWords->next);
    }
    free(oldWords);
}

Emirler *addEmirler(Emirler *wordList, char *sembol,char*islem,int adet)
{
    Emirler *newWords = emirlerConstructer(sembol,islem,adet);
    if (NULL != newWords)
    {
        newWords->next = wordList;
    }
    return newWords;
}

