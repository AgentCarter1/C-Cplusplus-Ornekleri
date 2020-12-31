#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
int genel_numara = 100;
int genel_sinif_sayi = 0;

class DosyaYonetim
{
public:
	string isim_ver() //isimler.txt dosyasýndan rastgele isim getirir
	{
		isim_oku.open("isimler.txt");//isimler.txt acýyorzu
		string temp;
		int randum = rand() % 1000 + 1;
		for (int i = 0; i < randum; i++)//isimlerden randum isimi getirir
		{
			isim_oku >> temp;
		}
		isim_oku.close();//isimler.txt kapatýyoruz
		return temp;

	}
	string soyisim_ver() // rastgele bir soyisim caðrýyoruz soyisimler.txt den
	{
		soyisim_oku.open("soyisimler.txt");
		int randum = rand() % 100 + 1;// sýfýr deðerini girmesin diye +1 ekledik
		string temp;
		for (int i = 0; i < randum; i++)
		{
			soyisim_oku >> temp;
		}
		soyisim_oku.close();
		return temp;
	}

private:
	ifstream isim_oku;
	ifstream soyisim_oku;
};

class Ogreci:public DosyaYonetim
{
public:
	Ogreci()
	{//ogrenci nesnesi kurucusu eðer deðerleri biz girmezsek kendisi rasgele txt dosyalarýndan kendisi alýyor
		
		ogrenci_ismi = isim_ver();
		ogrenci_soyisim = soyisim_ver();
		ogrenci_numara = genel_numara++;
	}
	Ogreci(string is, string sois, int num) 
	{// burasý ogrenci nesnesini neðer alan kurucu fonksoynu degerleri biz giriyoruz kayýtlar.txt okurken kullanýcaz
		ogrenci_ismi = is;
		ogrenci_soyisim = sois;
		ogrenci_numara = num;
	}
	string getir_ogr_isim()
	{//öðrenci ismi private old icin burdan eriþiyoruz
		return ogrenci_ismi;
	}
	string getir_ogr_soyisim() 
	{//öðrenci soyisimleri private old icin burdan eriþiyoruz
		return ogrenci_soyisim;
	}
	int getir_ogr_num()
	{//öðrenci numarasý private old icin burdan eriþiyoruz
		return ogrenci_numara;
	}
private:
	string ogrenci_ismi;
	string ogrenci_soyisim;
	int ogrenci_numara;
};
class Sinif
{
public:
	Sinif(string ism) 
	{//sinif sýnýfýný parametreli kurucu fonksyoun
		sinif_isim = ism;
		genel_sinif_sayi++;
		ogrenci_sayisi = 0;
	}
	Sinif() 
	{//sinif sýnýfýn parametresiz kurucu fonksonu rastegele sýnýf ismini içindeki fonksyonla atýyoruz
		sinif_isim = sinif_ismi_ver();//parametresiz old icin sinifýn ismini rastgele verir
		ogrenci_sayisi = 0;
	}
	Ogreci* sinif_ogr_getir(int i) 
	{//sýnýfýn icindeki istedigmiz öðrenciye ulaþýyoruz
		return sinif_ogreci[i];
	}
	void ogr_ekle(string o_isim, string o_soyisim, int o_num)
	{//sinifýn icine öðrenci eklemeyi yapýyoruz deðerleri kayitlar.txt den alýcaz
		sinif_ogreci[ogrenci_sayisi] = new Ogreci(o_isim, o_soyisim, o_num);
		ogrenci_sayisi++;//ögrenci sayisýný her öðrenci ekleyinci artýrmalýyýz 
	}
	void ogr_ekle()
	{//ögreci rasgele ekliðceksek, bilgilerini rastgele atmak icin bu fonksonu kullanýyoruz 
		sinif_ogreci[ogrenci_sayisi] = new Ogreci();
		ogrenci_sayisi++;
	}
	int getir_ogr_sayisi()
	{//öðrenci sayasi private old icin burdan ulaþýyoruz
		return ogrenci_sayisi;
	}
	string getri_sinif_isim()
	{//sýnýf ismi private old icin burdan ulaþýyoruz
		return sinif_isim;
	}
	void sinif_ogr_degistir(int i) 
	{//ögrenci degistirmek icin burda iþlem yapýyoruz, olan öðrencinin old yere yeniden rastgele öðrenci veriyoruz 
		sinif_ogreci[i] = new Ogreci;
	}
	void sinif_ogr_sil(int x)
	{ //öðrenci silmeyi bu fonksyonla yapýyoruz öðrencini üzerine ondan sonraki öðrencini bilgilerini giriyoruz  
		for (int i = x; i < ogrenci_sayisi - x; i++)
		{
			sinif_ogreci[i] = sinif_ogreci[i + 1];//silmek istediðmiz öðrencini yerine ondan sonra gelen öðrencini bilgilerini veriyoruz 
													//döngü yapýyoruz çünkü siliceðmiz öðrenciden sonraki elemanlarýn yerlerini degiþtiriyoruz
		}
		ogrenci_sayisi--;//öðrenci sayisini bir azaltýyouz 
	}

private:
	Ogreci* sinif_ogreci[100];//sinifýn icinde 100 adet  ögrenci yeri ayýrýyoruz iclerinine bilgileri ogr ekle fonksoyu caðýrdýgmýz zaman doldurucaz
	string sinif_isim;
	int ogrenci_sayisi;
	string sinif_ismi_ver()
	{
		string sinif_i;
		char temp = rand() % 25 + 65;//charýn icin 65-90 arasýnda bir deðer veriyoruz ascý karakterelrin karþýlýðý A-Z arasýnda old için
		sinif_i = to_string(genel_sinif_sayi + 1);//sýnýf sayisini int old için onu string e cevirmek icin to_string kullanýyoruz
		genel_sinif_sayi++;
		sinif_i += temp;//char olan harfi string icine atýyoruz


		return sinif_i;//bu string ifadeyi kurucunu fonksyonu içinde sinifýn ismine atýcaz
	}
};
class Okul
{
public:
	Okul() 
	{
		sinif_sayisi = 0;
		kayitlari_oku();//kayitlar.txt icindeki verileri okur
	}

	void ciz()
	{
		max_ogr_s();//maximum öðrenci sayisini bulmaya yarar

		for (int i = 0; i < sinif_sayisi; i++)
			ustYazdir(12);
		cout << endl;

		for (int i = 0; i < sinif_sayisi; i++)
			cout << dikey << "     " << okul_sinif[i]->getri_sinif_isim() << "     " << dikey;//sýnýf isimlerini consol ekranýný yazar
		cout << endl;

		for (int i = 0; i < sinif_sayisi; i++)
			altYazdir(12);
		cout << endl;

		for (int j = 0; j < max_ogr_sayisi; j++)
		{
			for (int i = 0; i < sinif_sayisi; i++)
			{
				if (okul_sinif[i]->getir_ogr_sayisi() > j)
				{
					ustYazdir(12);
				}
				else
				{
					cout << "              ";
				}
			}cout << endl;

			for (int i = 0; i < sinif_sayisi; i++)
			{
				if (okul_sinif[i]->getir_ogr_sayisi() > j)
				{
					cout << dikey << setfill(' ') << setw(12) << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_isim() << dikey;//setfill fonksonunu saða doðru yazdýrsýn diye kullandým
				}
				else
				{
					cout << "              ";
				}
			}cout << endl;

			for (int i = 0; i < sinif_sayisi; i++)
			{
				if (okul_sinif[i]->getir_ogr_sayisi() > j)
				{
					cout << dikey << setfill(' ') << setw(12) << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_soyisim() << dikey;//örenci soyisimlerini yazar
				}
				else
				{
					cout << "              ";
				}
			}cout << endl;

			for (int i = 0; i < sinif_sayisi; i++)
			{
				if (okul_sinif[i]->getir_ogr_sayisi() > j)
				{
					cout << dikey << setfill(' ') << setw(12) << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_num() << dikey;
				}
				else
				{
					cout << "              ";
				}
			}cout << endl;

			for (int i = 0; i < sinif_sayisi; i++)
			{
				if (okul_sinif[i]->getir_ogr_sayisi() > j)
				{
					altYazdir(12);
				}
				else
				{
					cout << "              ";
				}
			}cout << endl;

		}
	}
	int getir_sinif_sayi()
	{
		return sinif_sayisi;
	}
	Sinif* okul_sinif_getir(int i)
	{
		return okul_sinif[i];
	}
	void dosya_yaz()
	{// iþlem yaptýgmýz okul nesnesini kayitlar.txt üzerine yazar 
		ofstream yaz;
		yaz.open("kayitlar.txt");
		for (int i = 0; i < sinif_sayisi; i++)
		{
			yaz << okul_sinif[i]->getri_sinif_isim() << endl;//ilk önce sinifýn ismini yazar ve aþþaðý inier
			yaz << okul_sinif[i]->getir_ogr_sayisi() << endl;//siniftaki öðrenci sayisin yazar
			for (int j = 0; j < okul_sinif[i]->getir_ogr_sayisi(); j++)//for kullanýrýz çünkü sinifýn icindeki öðrencilerin hepsine ulaþýlým diye  
			{
				yaz << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_isim() << " ";
				yaz << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_soyisim() << " ";
				yaz << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_num() << endl;
			}
		}
		yaz.close();
	}
	void okul_sinif_ekle()
	{
		okul_sinif[sinif_sayisi] = new Sinif;//okul sýnýfýna yeni sýnýf atarken parametresiz old icin rasgele atamasý icin 
		sinif_sayisi++;
	}
	void okul_sinif_sil(int x)
	{
		for (int i = x; i < sinif_sayisi; i++)
		{
			okul_sinif[i] = okul_sinif[i + 1];//sinif nesnesini siliceðmiz zaman silmek istediðmiz sýnýfýn üstüne ondan sonraki sýnýfýlarý koyuyoruz 
		}
		sinif_sayisi--;//sýnýf sayisini bir azaltýyorzu
	}
private:

	int max_ogr_sayisi;
	void max_ogr_s()
	{//sýnýfýflarý icinde maximum kac eleman olduðnu buluyoruz ekrana yazarken kullanýyor

		max_ogr_sayisi = okul_sinif[0]->getir_ogr_sayisi();

		for (int i = 0; i < sinif_sayisi; i++)
		{
			if (okul_sinif[i]->getir_ogr_sayisi() > max_ogr_sayisi)
			{
				max_ogr_sayisi = okul_sinif[i]->getir_ogr_sayisi();
			}
		}
	}
	Sinif* okul_sinif[100];
	int sinif_sayisi;
	void kayitlari_oku()
	{
		ifstream kayitlar;
		kayitlar.open("kayitlar.txt");//kayýtlarý.txt dosyasýný açýyoruz
		string kayit_sinif_isim, kayit_ogr_isim, kayit_ogr_soyisim;
		int kayit_ogr_sayi, kayit_ogr_num;
		while (!kayitlar.eof())//dosyaný sonuna gelene kadar çalýþtýrmak icin kullanýyoruz
		{
			kayitlar >> kayit_sinif_isim;//sýnýfýn isimini alýyoruz 
			if (kayitlar.eof())break;//döngü bittiten sonra birdef daha calýþmasýn diye  

			okul_sinif[sinif_sayisi] = new Sinif(kayit_sinif_isim);//okuduðmuz sýnýf isimi ile sýnýf oluþturuyoruz
			kayitlar >> kayit_ogr_sayi;//sýnýfýn icinde kaç tane öðrenci old alýyoruz foru kaçkere calýþtýrýcaðmýzý bilelem diye
			for (int i = 0; i < kayit_ogr_sayi; i++)
			{
				kayitlar >> kayit_ogr_isim;
				kayitlar >> kayit_ogr_soyisim;
				kayitlar >> kayit_ogr_num;
				okul_sinif[sinif_sayisi]->ogr_ekle(kayit_ogr_isim, kayit_ogr_soyisim, kayit_ogr_num);//okudðmuz öðrenci bilgileri ile yeni bir öðrenci oluþturuyoruz sýnýfýn icnde
				genel_numara++;//genel numarayý global verdiðmiz icin her öðrenci eklediðmizde arttýroyruz
			}
			sinif_sayisi++;//sýnýfla iþimiz bitti zamna sýnýf sayisin bir artýrýyoruz
		}
		kayitlar.close();//kayýtlar.txt kapatýyoruz
	}

	char solUstKose = 201;
	char duz = 205;
	char sagUstKose = 187;
	char solAltKose = 200;
	char sagAltKose = 188;
	char dikey = 186;
	void ustYazdir(int elemanSayisi)
	{
		cout << solUstKose;
		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}
		cout << sagUstKose;
	}
	void altYazdir(int elemanSayisi)
	{
		cout << solAltKose;
		for (int i = 0; i < elemanSayisi; i++)
		{
			cout << duz;
		}
		cout << sagAltKose;
	}

};
class Program
{
public:
	Program() 
	{
		genel_okul = new Okul;
	}
	void calistir()
	{
		genel_okul->ciz();//program ilk calýþðý zamna ekrana bilgilerin gelmesi icin 
		do
		{
			cout << " 1.Orenci ekle" << endl
				<< " 2.Sinif ekle" << endl
				<< " 3.ogrenci dedistir" << endl
				<< " 4.ogrenci sil" << endl
				<< " 5.sinif sil" << endl
				<< " 6.cikis" << endl;
			cin >> karar;
			switch (karar)
			{
			case 1://öðrenci eklemek için
				ogrenci_ekle();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 2://sýnýf eklemek icin
				sinif_ekle();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 3://öðrenci degiþtirmek icin
				ogrenci_degistir();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 4://öðrinci silmek 
				ogrenci_sil();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 5://sýnýf silmek icin
				sinif_sil();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;

			default:break;
			}
		} while (!(karar == 6));//eðer girdiðmiz deðir 6 olursa cýkýþ yapýyoruz
	}

private:
	void ogrenci_ekle()
	{
		string temp_sinif;
		cout << "sinifin ismini yazin "; cin >> temp_sinif;
		for (int i = 0; i < genel_okul->getir_sinif_sayi(); i++)
		{
			if (genel_okul->okul_sinif_getir(i)->getri_sinif_isim() == temp_sinif)//hangi sýnýfa eklemek istiyorsak o sýnýfýn icide 
			{																	//ogr ekle fonksonu caðrýyoruz
				genel_okul->okul_sinif_getir(i)->ogr_ekle();
				break;
			}
		}

	}
	void sinif_ekle()
	{
		genel_okul->okul_sinif_ekle();//okul nesnesini icinde yeni bir sýnýf ekliyoruz
	}
	void ogrenci_degistir()
	{
		int girilen_diger;
		cout << " ogrenci numarasi girin "; cin >> girilen_diger;
		for (int i = 0; i < genel_okul->getir_sinif_sayi(); i++)
		{
			for (int j = 0; j < genel_okul->okul_sinif_getir(i)->getir_ogr_sayisi(); j++)//bütün sýnýflarýn içine ulaþmak icin
			{
				if (genel_okul->okul_sinif_getir(i)->sinif_ogr_getir(j)->getir_ogr_num() == girilen_diger)//girdiðmiz sýnýfýn içinde arama yapýyoruz bulursak o ögenciyi degiþtiriyoruz
				{
					genel_okul->okul_sinif_getir(i)->sinif_ogr_degistir(j);

				}
			}
		}
	}
	void ogrenci_sil() 
	{
		int girilen_diger;
		cout << " ogrenci numarasi girin "; cin >> girilen_diger;
		for (int i = 0; i < genel_okul->getir_sinif_sayi(); i++)
		{
			for (int j = 0; j < genel_okul->okul_sinif_getir(i)->getir_ogr_sayisi(); j++)//sýnýflarný icinde arama yapmak icin
			{
				if (genel_okul->okul_sinif_getir(i)->sinif_ogr_getir(j)->getir_ogr_num() == girilen_diger)//sýnýflarý öðrencileri icinde arama yapmak icin
				{
					genel_okul->okul_sinif_getir(i)->sinif_ogr_sil(j);//girilen numara ile ayný öðr numarasý eþleþirse siliyoruz
					break;
				}
			}
		}
	}
	void sinif_sil() 
	{
		string temp_sinif;
		cout << " silinecek sinif gir "; cin >> temp_sinif;
		for (int i = 0; i < genel_okul->getir_sinif_sayi(); i++)//okulun icindeký sýnýfýlara arama yapmak icin
		{
			if (genel_okul->okul_sinif_getir(i)->getri_sinif_isim() == temp_sinif)//sýnýf ismi ile girilen deðer bir ise içeri girer
			{
				genel_okul->okul_sinif_sil(i);
			}
		}
	}
	Okul* genel_okul;//program sýnýfný icinde okul nesnesi oluþturuyouz
	int karar;
};

int main() 
{

	Program prog;
	prog.calistir();

	system("pause");
}

