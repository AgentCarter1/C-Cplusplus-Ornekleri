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
	string isim_ver() //isimler.txt dosyas�ndan rastgele isim getirir
	{
		isim_oku.open("isimler.txt");//isimler.txt ac�yorzu
		string temp;
		int randum = rand() % 1000 + 1;
		for (int i = 0; i < randum; i++)//isimlerden randum isimi getirir
		{
			isim_oku >> temp;
		}
		isim_oku.close();//isimler.txt kapat�yoruz
		return temp;

	}
	string soyisim_ver() // rastgele bir soyisim ca�r�yoruz soyisimler.txt den
	{
		soyisim_oku.open("soyisimler.txt");
		int randum = rand() % 100 + 1;// s�f�r de�erini girmesin diye +1 ekledik
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
	{//ogrenci nesnesi kurucusu e�er de�erleri biz girmezsek kendisi rasgele txt dosyalar�ndan kendisi al�yor
		
		ogrenci_ismi = isim_ver();
		ogrenci_soyisim = soyisim_ver();
		ogrenci_numara = genel_numara++;
	}
	Ogreci(string is, string sois, int num) 
	{// buras� ogrenci nesnesini ne�er alan kurucu fonksoynu degerleri biz giriyoruz kay�tlar.txt okurken kullan�caz
		ogrenci_ismi = is;
		ogrenci_soyisim = sois;
		ogrenci_numara = num;
	}
	string getir_ogr_isim()
	{//��renci ismi private old icin burdan eri�iyoruz
		return ogrenci_ismi;
	}
	string getir_ogr_soyisim() 
	{//��renci soyisimleri private old icin burdan eri�iyoruz
		return ogrenci_soyisim;
	}
	int getir_ogr_num()
	{//��renci numaras� private old icin burdan eri�iyoruz
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
	{//sinif s�n�f�n� parametreli kurucu fonksyoun
		sinif_isim = ism;
		genel_sinif_sayi++;
		ogrenci_sayisi = 0;
	}
	Sinif() 
	{//sinif s�n�f�n parametresiz kurucu fonksonu rastegele s�n�f ismini i�indeki fonksyonla at�yoruz
		sinif_isim = sinif_ismi_ver();//parametresiz old icin sinif�n ismini rastgele verir
		ogrenci_sayisi = 0;
	}
	Ogreci* sinif_ogr_getir(int i) 
	{//s�n�f�n icindeki istedigmiz ��renciye ula��yoruz
		return sinif_ogreci[i];
	}
	void ogr_ekle(string o_isim, string o_soyisim, int o_num)
	{//sinif�n icine ��renci eklemeyi yap�yoruz de�erleri kayitlar.txt den al�caz
		sinif_ogreci[ogrenci_sayisi] = new Ogreci(o_isim, o_soyisim, o_num);
		ogrenci_sayisi++;//�grenci sayis�n� her ��renci ekleyinci art�rmal�y�z 
	}
	void ogr_ekle()
	{//�greci rasgele ekli�ceksek, bilgilerini rastgele atmak icin bu fonksonu kullan�yoruz 
		sinif_ogreci[ogrenci_sayisi] = new Ogreci();
		ogrenci_sayisi++;
	}
	int getir_ogr_sayisi()
	{//��renci sayasi private old icin burdan ula��yoruz
		return ogrenci_sayisi;
	}
	string getri_sinif_isim()
	{//s�n�f ismi private old icin burdan ula��yoruz
		return sinif_isim;
	}
	void sinif_ogr_degistir(int i) 
	{//�grenci degistirmek icin burda i�lem yap�yoruz, olan ��rencinin old yere yeniden rastgele ��renci veriyoruz 
		sinif_ogreci[i] = new Ogreci;
	}
	void sinif_ogr_sil(int x)
	{ //��renci silmeyi bu fonksyonla yap�yoruz ��rencini �zerine ondan sonraki ��rencini bilgilerini giriyoruz  
		for (int i = x; i < ogrenci_sayisi - x; i++)
		{
			sinif_ogreci[i] = sinif_ogreci[i + 1];//silmek istedi�miz ��rencini yerine ondan sonra gelen ��rencini bilgilerini veriyoruz 
													//d�ng� yap�yoruz ��nk� silice�miz ��renciden sonraki elemanlar�n yerlerini degi�tiriyoruz
		}
		ogrenci_sayisi--;//��renci sayisini bir azalt�youz 
	}

private:
	Ogreci* sinif_ogreci[100];//sinif�n icinde 100 adet  �grenci yeri ay�r�yoruz iclerinine bilgileri ogr ekle fonksoyu ca��rd�gm�z zaman doldurucaz
	string sinif_isim;
	int ogrenci_sayisi;
	string sinif_ismi_ver()
	{
		string sinif_i;
		char temp = rand() % 25 + 65;//char�n icin 65-90 aras�nda bir de�er veriyoruz asc� karakterelrin kar��l��� A-Z aras�nda old i�in
		sinif_i = to_string(genel_sinif_sayi + 1);//s�n�f sayisini int old i�in onu string e cevirmek icin to_string kullan�yoruz
		genel_sinif_sayi++;
		sinif_i += temp;//char olan harfi string icine at�yoruz


		return sinif_i;//bu string ifadeyi kurucunu fonksyonu i�inde sinif�n ismine at�caz
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
		max_ogr_s();//maximum ��renci sayisini bulmaya yarar

		for (int i = 0; i < sinif_sayisi; i++)
			ustYazdir(12);
		cout << endl;

		for (int i = 0; i < sinif_sayisi; i++)
			cout << dikey << "     " << okul_sinif[i]->getri_sinif_isim() << "     " << dikey;//s�n�f isimlerini consol ekran�n� yazar
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
					cout << dikey << setfill(' ') << setw(12) << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_isim() << dikey;//setfill fonksonunu sa�a do�ru yazd�rs�n diye kulland�m
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
					cout << dikey << setfill(' ') << setw(12) << okul_sinif[i]->sinif_ogr_getir(j)->getir_ogr_soyisim() << dikey;//�renci soyisimlerini yazar
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
	{// i�lem yapt�gm�z okul nesnesini kayitlar.txt �zerine yazar 
		ofstream yaz;
		yaz.open("kayitlar.txt");
		for (int i = 0; i < sinif_sayisi; i++)
		{
			yaz << okul_sinif[i]->getri_sinif_isim() << endl;//ilk �nce sinif�n ismini yazar ve a��a�� inier
			yaz << okul_sinif[i]->getir_ogr_sayisi() << endl;//siniftaki ��renci sayisin yazar
			for (int j = 0; j < okul_sinif[i]->getir_ogr_sayisi(); j++)//for kullan�r�z ��nk� sinif�n icindeki ��rencilerin hepsine ula��l�m diye  
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
		okul_sinif[sinif_sayisi] = new Sinif;//okul s�n�f�na yeni s�n�f atarken parametresiz old icin rasgele atamas� icin 
		sinif_sayisi++;
	}
	void okul_sinif_sil(int x)
	{
		for (int i = x; i < sinif_sayisi; i++)
		{
			okul_sinif[i] = okul_sinif[i + 1];//sinif nesnesini silice�miz zaman silmek istedi�miz s�n�f�n �st�ne ondan sonraki s�n�f�lar� koyuyoruz 
		}
		sinif_sayisi--;//s�n�f sayisini bir azalt�yorzu
	}
private:

	int max_ogr_sayisi;
	void max_ogr_s()
	{//s�n�f�flar� icinde maximum kac eleman oldu�nu buluyoruz ekrana yazarken kullan�yor

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
		kayitlar.open("kayitlar.txt");//kay�tlar�.txt dosyas�n� a��yoruz
		string kayit_sinif_isim, kayit_ogr_isim, kayit_ogr_soyisim;
		int kayit_ogr_sayi, kayit_ogr_num;
		while (!kayitlar.eof())//dosyan� sonuna gelene kadar �al��t�rmak icin kullan�yoruz
		{
			kayitlar >> kayit_sinif_isim;//s�n�f�n isimini al�yoruz 
			if (kayitlar.eof())break;//d�ng� bittiten sonra birdef daha cal��mas�n diye  

			okul_sinif[sinif_sayisi] = new Sinif(kayit_sinif_isim);//okudu�muz s�n�f isimi ile s�n�f olu�turuyoruz
			kayitlar >> kayit_ogr_sayi;//s�n�f�n icinde ka� tane ��renci old al�yoruz foru ka�kere cal��t�r�ca�m�z� bilelem diye
			for (int i = 0; i < kayit_ogr_sayi; i++)
			{
				kayitlar >> kayit_ogr_isim;
				kayitlar >> kayit_ogr_soyisim;
				kayitlar >> kayit_ogr_num;
				okul_sinif[sinif_sayisi]->ogr_ekle(kayit_ogr_isim, kayit_ogr_soyisim, kayit_ogr_num);//okud�muz ��renci bilgileri ile yeni bir ��renci olu�turuyoruz s�n�f�n icnde
				genel_numara++;//genel numaray� global verdi�miz icin her ��renci ekledi�mizde artt�royruz
			}
			sinif_sayisi++;//s�n�fla i�imiz bitti zamna s�n�f sayisin bir art�r�yoruz
		}
		kayitlar.close();//kay�tlar.txt kapat�yoruz
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
		genel_okul->ciz();//program ilk cal���� zamna ekrana bilgilerin gelmesi icin 
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
			case 1://��renci eklemek i�in
				ogrenci_ekle();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 2://s�n�f eklemek icin
				sinif_ekle();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 3://��renci degi�tirmek icin
				ogrenci_degistir();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 4://��rinci silmek 
				ogrenci_sil();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;
			case 5://s�n�f silmek icin
				sinif_sil();
				genel_okul->dosya_yaz();
				system("cls");
				genel_okul->ciz();
				break;

			default:break;
			}
		} while (!(karar == 6));//e�er girdi�miz de�ir 6 olursa c�k�� yap�yoruz
	}

private:
	void ogrenci_ekle()
	{
		string temp_sinif;
		cout << "sinifin ismini yazin "; cin >> temp_sinif;
		for (int i = 0; i < genel_okul->getir_sinif_sayi(); i++)
		{
			if (genel_okul->okul_sinif_getir(i)->getri_sinif_isim() == temp_sinif)//hangi s�n�fa eklemek istiyorsak o s�n�f�n icide 
			{																	//ogr ekle fonksonu ca�r�yoruz
				genel_okul->okul_sinif_getir(i)->ogr_ekle();
				break;
			}
		}

	}
	void sinif_ekle()
	{
		genel_okul->okul_sinif_ekle();//okul nesnesini icinde yeni bir s�n�f ekliyoruz
	}
	void ogrenci_degistir()
	{
		int girilen_diger;
		cout << " ogrenci numarasi girin "; cin >> girilen_diger;
		for (int i = 0; i < genel_okul->getir_sinif_sayi(); i++)
		{
			for (int j = 0; j < genel_okul->okul_sinif_getir(i)->getir_ogr_sayisi(); j++)//b�t�n s�n�flar�n i�ine ula�mak icin
			{
				if (genel_okul->okul_sinif_getir(i)->sinif_ogr_getir(j)->getir_ogr_num() == girilen_diger)//girdi�miz s�n�f�n i�inde arama yap�yoruz bulursak o �genciyi degi�tiriyoruz
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
			for (int j = 0; j < genel_okul->okul_sinif_getir(i)->getir_ogr_sayisi(); j++)//s�n�flarn� icinde arama yapmak icin
			{
				if (genel_okul->okul_sinif_getir(i)->sinif_ogr_getir(j)->getir_ogr_num() == girilen_diger)//s�n�flar� ��rencileri icinde arama yapmak icin
				{
					genel_okul->okul_sinif_getir(i)->sinif_ogr_sil(j);//girilen numara ile ayn� ��r numaras� e�le�irse siliyoruz
					break;
				}
			}
		}
	}
	void sinif_sil() 
	{
		string temp_sinif;
		cout << " silinecek sinif gir "; cin >> temp_sinif;
		for (int i = 0; i < genel_okul->getir_sinif_sayi(); i++)//okulun icindek� s�n�f�lara arama yapmak icin
		{
			if (genel_okul->okul_sinif_getir(i)->getri_sinif_isim() == temp_sinif)//s�n�f ismi ile girilen de�er bir ise i�eri girer
			{
				genel_okul->okul_sinif_sil(i);
			}
		}
	}
	Okul* genel_okul;//program s�n�fn� icinde okul nesnesi olu�turuyouz
	int karar;
};

int main() 
{

	Program prog;
	prog.calistir();

	system("pause");
}

