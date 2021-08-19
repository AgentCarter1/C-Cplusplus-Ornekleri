#include "Calistir.h"

calistir CalistirKurucu(){
    calistir this;
    this = (calistir)malloc(sizeof(struct Calistir));
    this->run = &Run;
    return this;
}

void Run(){
    dosya file;
	file = DosyaKurucu();
	file->dosyaOku();
}