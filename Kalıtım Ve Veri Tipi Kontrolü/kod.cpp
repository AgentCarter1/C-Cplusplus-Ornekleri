#include <iostream>
#include <ctype.h>
#include <cstring>
using namespace  std;


class Takilar {//kalıtım alacağımız takı sınıfı
protected:
    string takiAdi;//değişkenlerimiz
    string KullanicakCinsiyet;
    int ebatNo;
public:
    Takilar() {//takı kurucu fonksiyonu
        takiAdi = "";
        KullanicakCinsiyet = "";
        ebatNo = 0;
    }
};

class Yuzuk :public Takilar {//yüzük sınıfına takilardan kalıtım aldık
public:
    Yuzuk() {
        takiAdi = "Yuzuk";//yuzuk kurucu methodu
    }
    void print() {//ekrana yazdırma fonksiyonumuz
        cout << "Taki Adi: " << takiAdi << endl << "Kullanacak Cinsiyet: " << KullanicakCinsiyet << endl << "Ebat No: " << ebatNo;
    }
    void kullanicakCinsiyetAta(string ad) {//verileri atayacağımız fonksiyonlar
        this->KullanicakCinsiyet = ad;
    }
    void ebatNoAta(int ebat) {
        this->ebatNo = ebat;
    }  
    bool takiCinsiyetKontrol(const string& str) {//girilen değerin tipini kontrol eden fonksiyonlar
        for (char const& c : str) {

            if (std::isdigit(c) == 0) return true;
        }
        throw "Hatali Giris";      
    }
    
    bool takiEbatKontrol(int gelenData) {
    
        if (cin.good()) {
           return true;
        }
        else {
            throw "Hatali Giris";
        }        
    }
    void calistir() {//çalıştırma fonksiyonumuz
        string kullanacakCinsiyetData = "";//verileri alıyoruz
        int ebatNoData = 0;
        cout << "Kullanacak Cinsiyeti Giriniz: ";
        cin >> kullanacakCinsiyetData;
        cout << "Yuzuk Ebatini Giriniz: ";
        cin >> ebatNoData;
        try {//başlatıyoruz 
            bool tutan = takiCinsiyetKontrol(kullanacakCinsiyetData);//eğer true değeri gelirse ife gireceğiz
            if (tutan) {//ife girdik
                try {//yeniden try catch bloğu
                    bool tutan2 = takiEbatKontrol(ebatNoData);//ebat değeri doğru girilmişse ife girecek
                    if (tutan2) {//eğer her şey doğruysa
                        kullanicakCinsiyetAta(kullanacakCinsiyetData);//verileri atıp ekrana yazdırma
                        ebatNoAta(ebatNoData);
                        print();
                    }
                }
                catch (const char* msg) {
                    cout << msg << endl;
                }
            }
        }
        catch (const char* msg) {
            cout<<msg<<endl;
        }
    }
};

int main()
{
    Yuzuk yuzuk;
    yuzuk.calistir(); 
    return 0;
}
