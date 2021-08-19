#ifndef CALISTIR_H
#define CALISTIR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Dosya.h"
struct Calistir
{ 
    void (*run)();
};

typedef struct Calistir *calistir;
calistir CalistirKurucu();
void Run();

#endif