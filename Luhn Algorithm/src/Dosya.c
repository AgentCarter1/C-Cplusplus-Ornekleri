#include "Dosya.h"

dosya DosyaKurucu(){
    dosya this;
    this = (dosya)malloc(sizeof(struct Dosya));
    this->dosyaOku = &DosyaOku;
    return this;
}
void DosyaOku()
{
	calculator calculate;
	calculate = CalculatorKurucu();
	FILE *dosya, *dosyayaYaz;
	int ilkSayi, ikinciSayi, ucuncuSayi, dorduncuSayi,toplam=0;;
	dosya = fopen("Deneme.txt", "r");
	dosyayaYaz = fopen("Sonuc.txt", "w");
	
	if (dosya != NULL)

	{
		while (!feof(dosya))
		{
			toplam =0;
			fscanf(dosya, "%d %d %d %d", &ilkSayi, &ikinciSayi, &ucuncuSayi, &dorduncuSayi);
			int binler,yuzler,onlar,birler;
			calculate->tumSayininToplamlariniHesapla(&binler, &yuzler, &onlar, &birler,ilkSayi,ikinciSayi,ucuncuSayi,dorduncuSayi,&toplam);
			

			if (toplam % 10 == 0)
			{
				printf("%d %d %d %d %s\n", ilkSayi, ikinciSayi, ucuncuSayi, dorduncuSayi, "- gecerli");
				fprintf(dosyayaYaz, "%d %d %d %d %s\n", ilkSayi, ikinciSayi, ucuncuSayi, dorduncuSayi, "- gecerli");
			}
			else
			{
				fprintf(dosyayaYaz, "%d %d %d %d %s\n", ilkSayi, ikinciSayi, ucuncuSayi, dorduncuSayi, "- gecersiz");
				printf("%d %d %d %d %s\n", ilkSayi, ikinciSayi, ucuncuSayi, dorduncuSayi, "- gecersiz");
			}
		}
	}
	else
	{
		printf("Dosya Bulunamadi...");
	}
	fclose(dosya);
	fclose(dosyayaYaz);
	free(dosya);
	free(dosyayaYaz);
}
