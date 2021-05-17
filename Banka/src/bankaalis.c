#include <stdio.h>
#include <stdlib.h>
#include "bankaalis.h"



BankaAlis *alisConstructer(char *sembolAlis, int adet, double alisMaliyet)
{
    BankaAlis *newWords = malloc(sizeof(BankaAlis));
    if (NULL != newWords)
    {
        newWords->sembolAlis = sembolAlis;
        newWords->adet = adet;
        newWords->alisMaliyet = alisMaliyet;
    }
    return newWords;
}
BankaAlis *alisEkleme(BankaAlis *wordList, char *sembolAlis, int adet, double alisMaliyet)
{
    BankaAlis *newWords = alisConstructer(sembolAlis, adet, alisMaliyet);
    if (NULL != newWords)
    {
        newWords->next = wordList;
    }
    return newWords;
}

void deleteAlis(BankaAlis *oldWords)
{
    if (NULL != oldWords->next)
    {
        deleteAlis(oldWords->next);
    }
    free(oldWords);
}


