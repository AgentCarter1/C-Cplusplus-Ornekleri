#include "Calculator.h"

calculator CalculatorKurucu(){
    calculator this;
    this = (calculator)malloc(sizeof(struct Calculator));
    this->basamaklarinaAyir = &BasamaklarinaAyir;
    this->birSayininToplaminiHesapla = &BirSayininToplaminiHesapla;
    this->tumSayininToplamlariniHesapla = &TumSayininToplamlariniHesapla;
    return this;
}
 
void BasamaklarinaAyir(int *gelenSayiBinler, int *gelenSayiYuzler, int *gelenSayiOnlar, int *gelenSayiBirler, int ayrilacakSayi)
{
	*gelenSayiBirler = ayrilacakSayi % 10;
	ayrilacakSayi /= 10;
	*gelenSayiOnlar = ayrilacakSayi % 10;
	ayrilacakSayi /= 10;
	*gelenSayiYuzler = ayrilacakSayi % 10;
	ayrilacakSayi /= 10;
	*gelenSayiBinler = ayrilacakSayi % 10;
	*gelenSayiBinler *= 2;
	*gelenSayiOnlar *= 2;

	if (*gelenSayiBinler > 9)
	{
		int birler = *gelenSayiBinler % 10;
		*gelenSayiBinler /= 10;
		int onlar =* gelenSayiBinler % 10;
		*gelenSayiBinler = birler + onlar;
	}
	if (*gelenSayiOnlar > 9)
	{
		int birler = *gelenSayiOnlar % 10;
		*gelenSayiOnlar /= 10;
		int onlar = *gelenSayiOnlar % 10;
		*gelenSayiOnlar = birler + onlar;
	}
}

void BirSayininToplaminiHesapla(int *binler, int *yuzler, int *onlar, int *birler, int gelenSayi,int *toplam){
	BasamaklarinaAyir(binler,yuzler,onlar,birler,gelenSayi);
	*toplam += *binler+*yuzler+*onlar+*birler;
}
void TumSayininToplamlariniHesapla(int *binler, int *yuzler, int *onlar, int *birler, int ilkSayi,int ikinciSayi,int ucuncuSayi,int dorduncuSayi,int *toplam){
	BirSayininToplaminiHesapla(binler,yuzler,onlar,birler,ilkSayi,toplam);
	BirSayininToplaminiHesapla(binler,yuzler,onlar,birler,ikinciSayi,toplam);
	BirSayininToplaminiHesapla(binler,yuzler,onlar,birler,ucuncuSayi,toplam);
	BirSayininToplaminiHesapla(binler,yuzler,onlar,birler,dorduncuSayi,toplam);
}