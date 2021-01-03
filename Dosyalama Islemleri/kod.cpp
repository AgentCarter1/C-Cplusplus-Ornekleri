/*
	Dosyalama İşlemleri.
	1-Ekleme
	1-Silme
	1-Güncelleme
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int diziUzunlugu = 0;
class DosyaYonetim {
private:
	ifstream readFile, againRead, writeScreen, updateRead;
	ofstream writeFile, firstWrite, lastWrite;
	string malAdi[100], malStok[100], malFiyat[100];
public:
	DosyaYonetim(){}
	void dosyayailkYaz(string malAdi,string malStoku,string malFiyati) {
		firstWrite.open("Depo.txt");
		firstWrite << malAdi << " " << malStoku << " " << malFiyat << "\n";
		firstWrite.close();
	}
	void dosyayaEkle(string malAdi, string malStoku, string malFiyati) {
		lastWrite.open("Depo.txt", ios::app);
		lastWrite  << malAdi << " " << malStoku << " " << malFiyati << "\n";
		lastWrite.close();
	}
	void dosyadakiVerileriGetir() {
		if (diziUzunlugu == 0)cout << "Dosyada Veri Yoktur ";
		else {
			for (int i = 0; i < diziUzunlugu - 1; i++) {
				cout << malAdi[i] << " " << malStok[i] << " " << malFiyat[i] << endl;
			}
		}
	}
	void dosyadanOku() {
		readFile.open("Depo.txt");
		diziUzunlugu = 0;
		string adi, stok, fiyat;
		while (!readFile.eof()) {
			readFile >> adi;
			readFile >> stok;
			readFile >> fiyat;
			malAdi[diziUzunlugu] = adi;
			malStok[diziUzunlugu] = stok;
			malFiyat[diziUzunlugu] = fiyat;
			diziUzunlugu++;
		}
		diziUzunlugu--;
		readFile.close();
	}
	void dosyadanSil(string aranan) {
		int arananSatir = 0;
		while (!againRead.eof()) {
			if (aranan == malAdi[arananSatir]) {
				for (int i = arananSatir; i < diziUzunlugu - arananSatir; i++) {
					malAdi[i] = malAdi[i + 1];
					malStok[i] = malStok[i + 1];
					malFiyat[i] = malFiyat[i + 1];
				}
				diziUzunlugu = diziUzunlugu - 1;
				againRead.close();
				break;
			}
			if (arananSatir == diziUzunlugu)break;
			arananSatir++;
		}
	}
	void dosyayaYenidenYaz() {
		ofstream writeFile("Depo.txt");
		if (writeFile.is_open()) {
			for (int i = 0; i < diziUzunlugu; i++) {
				writeFile << malAdi[i] << " " << malStok[i] << " " << malFiyat[i] << "\n";
			}
		}
	}
	void verileriGuncelle(string aranan,string guncelStok,string guncelFiyat) {
		int arananSatir = 0;
		while (!updateRead.eof()) {
			if (aranan == malAdi[arananSatir]) {
				malStok[arananSatir] = guncelStok;
				malFiyat[arananSatir] = guncelFiyat;				
				updateRead.close();
				break;
			}
			if (arananSatir == diziUzunlugu)break;
			arananSatir++;
		}
	}
	void calistir() {		
		int secim;
		string malzemeAdi, malzemeFiyati, malzemeStokAdedi;
		do
		{
			system("CLS");
			dosyadanOku();
			cout << "Yapmak Istediginiz Islemi Seciniz: " << endl;
			cout << "1-) Malzeme Ekleme." << endl;
			cout << "2-) Malzeme Silme." << endl;
			cout << "3-) Listeyi Yazdirma." << endl;
			cout << "4-)Guncelleme. " << endl;
			cout << "5-)Cikis." << endl;
			cin >> secim;
			switch (secim)
			{
			case 1:
				cout << "Malzeme Adi:";
				cin >> malzemeAdi;
				cout << "Malzeme Stok Adedi: ";
				cin >> malzemeStokAdedi;
				cout << "Malzeme Fiyatı:";
				cin >> malzemeFiyati;
				if (diziUzunlugu == 0) {
					dosyayailkYaz(malzemeAdi, malzemeStokAdedi, malzemeFiyati);
					cout << "Dosyaya Ilk Veri Eklendi.";
				}
				else {
					dosyayaEkle(malzemeAdi, malzemeStokAdedi, malzemeFiyati);
					cout << "Basariyla Eklendi.";
				}
				cin.get();
				break;
			case 2:
				cout << "Silmek Istediginiz Malzeme Adi:";
				cin >> malzemeAdi;
				dosyadanSil(malzemeAdi);
				dosyayaYenidenYaz();
				cout << "Basariyla Silindi.";
				cin.get();
				break;
			case 3:
				dosyadakiVerileriGetir();
				cin.get();
				break;
			case 4:
				cout << "Guncellemek Istediginiz Malzemenin Adini Girin: ";
				cin >> malzemeAdi;
				cout << endl << "Stok Adedi: ";
				cin >> malzemeStokAdedi;
				cout << endl << "Fiyat: ";
				cin >> malzemeFiyati;
				verileriGuncelle(malzemeAdi, malzemeStokAdedi, malzemeFiyati);
				dosyayaYenidenYaz();
				cout << "Basariyla Guncellendi.";
				cin.get();
			default:
				break;
			}
		} while (secim > 0 && secim < 5);
		
	}
};
int main()
{
	DosyaYonetim prog;
	prog.calistir();
	prog.dosyadakiVerileriGetir();
	cin.get();
	return 0;
}


