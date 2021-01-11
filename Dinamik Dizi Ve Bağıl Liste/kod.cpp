#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<Windows.h>
using namespace std;
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Dugum  // listedeki düğümlerin tanımını yapan sınıf
{
private:
    int sayi;  // listedeki düğüm içersindeki veriyi tutacak. veri güvenlik altında ( private )

public:
    Dugum* sonraki; // listedeki düğümde bir sonraki düğümün bellek adresini tutacak.

    Dugum() {};  // kurucu fonksiyon.

    Dugum(int a)  // diğer kurucu fonksiyon. ilk elemanı ekler ve göstericiyi sıfıra eşitler. yani son düğümdür.
    {
        sayi = a;
        sonraki = 0;
    }

    int sayiDondur()  // düğüm içersindeki veriye erişmemizi sağlar. c#'ta get ile yapılır bu işlem.
    {
        return sayi;
    }
};

class Liste  // bağlantılı liste ile ilgili fonksiyonların bulunduğu önemli sınıf.
{
public:
    Dugum* bas; // listedeki ilk düğümün adresini tutar. bütün erişimler bu değişken ile başlar.
    Dugum* son; // son düğümün adresini tutar.
    Liste()
    {
        bas = NULL;  // listede eleman yok baş ve son sıfırı gösteriyor.
        son = NULL;
    }
    Liste(int a) // listeye ilk eleman eklenir.
    {
        Dugum* p = new Dugum(a); // ilk düğüm oluşturulur. bu düğümün verisi a'dır.
        bas = son = p;   // ilk düğüm ve son düğüm p'dir.
    }

    void ekle(int a)
    {
        if (bas == 0) // liste boş ise
        {
            bas = new Dugum(a);  // baş'a eklenen düğüm atanır.
            son = bas;           // ilk düğüm aynı zamanda son düğümdür.
        }
        else // eğer listede düğüm var ise
        {
            Dugum* yeniDugum = new Dugum(a); // yeni düğüm oluşturulur. verisi a olur. sonraki ise sıfırı gösterir. yani son düğümdür.
            (*son).sonraki = yeniDugum;   // önceden son olan düğümün sonraki ile işaret ettiği yer yenidüğüm olur.
            son = yeniDugum;             // son düğüm de tabi ki en son eklenen düğüm olur.
        }
    }

    void yazdir() // listeyi yazdırır.
    {
        Dugum* temp; // yazdırma işlemi için geçici bi düğüm oluşturulur. baş düğümden itibaren tek tek bütün düğümleri dolaşacak.
        temp = bas; // yazdirmaya en baştan başlanır.
        int i = 0;
        if (bas != 0)  // listede eleman varsa                     
        {
            while (temp != 0)  // liste bitene kadar
            {
                gotoxy(7, i);
                cout << temp->sayiDondur() << " "; // düğümdeki sayıyı yazdır.
                temp = temp->sonraki;        // sonraki düğüme geç
                i++;
            }

        }
    }
    void Ilerle(const char& secim, const int& diziboyutu, int& x, int& y) {

        if (secim == 'A' || secim == 'a') {//seçim a ise
            y++;//bir arttırıyotuz y eksnini
            if (y == diziboyutu - 1) {//eğer sondaysak başa gelebilmek için
                gotoxy(x, y);
                cout << "---->";
                y = -1;
            }
            else {//değilse direkt ilerleme

                gotoxy(x, y);
                cout << "---->";
            }
        }
        else if (secim == 'D' || secim == 'd') {//secim d ise
            y--;//ekseni düşürdük
            if (y == -1) {//eğer baştaysan sona gitme
                gotoxy(x, diziboyutu - 1);
                cout << "---->";
                y = diziboyutu - 1;
            }
            else {//yoksa direkt geri gitme
                gotoxy(x, y);
                cout << "---->";
            }
        }

    }

};
string** NewTable1(int rows, int columns)//string dinamik dizi oluşturan fonksiyonumuz
{
   string** tablo = new string* [rows];
    for (int i = 0; i < rows; i++)
    {
        tablo[i] = new string[columns];
    }

    return tablo;

}
int** NewTable(int rows, int columns)//int dinamik dizi oluşturan fonksiyonumuz
{
    int** tablo = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        tablo[i] = new int[columns];
    }
    return tablo;
}
int main()
{
    int secim;

    do
    {
        cout << "Assagi Yukari Oyunu Icin 1'e Matris Oyunu Icin 2'ye Basiniz. ";
        cin >> secim;
        switch (secim)
        {
        case 1:
            int** Dizi;//int dizimiz
            string** Dizi2;//karakterleri atacak olduğumuz dizi
            int boyut, kucuk, buyuk;
            cout << "Dizinin Boyutunu Giriniz: ";
            cin >> boyut;
            cout << endl;
            Dizi = NewTable(boyut, boyut);//boyutlarını aynı yapıyoruz
            Dizi2 = NewTable1(boyut, boyut);//boyutlarını aynı yapıyoruz
            srand(time(NULL));//sayı tekrarını önlemek için
            for (int i = 0; i < boyut; i++) {//diziye değerleri atıyoruz
                for (int j = 0; j < boyut; j++) {
                    int a = 0;
                    a = (rand() % 99) + 1;
                    Dizi[i][j] = a;
                }

            }
            for (int i = 0; i < boyut; i++) {//diziyi ekrana yazdırdık
                for (int j = 0; j < boyut; j++) {
                    cout << Dizi[i][j] << " ";
                }
                cout << endl;
            }
            cout << "Lutfen Kucuk Sayiyi Giriniz: ";//büyük küçük değerleri aldık
            cin >> kucuk;
            cout << "Lutfen Buyuk Sayiyi Giriniz: ";
            cin >> buyuk;
            for (int i = 0; i < boyut; i++) {//sayıların büyük küçüklüğüne göre işaretleri atadık
                for (int j = 0; j < boyut; j++) {
                    if (Dizi[i][j] < kucuk) {
                        Dizi2[i][j] = "*";
                    }
                    if (Dizi[i][j] > buyuk) {
                        Dizi2[i][j] = "-";
                    }
                    if (Dizi[i][j] >= kucuk && Dizi[i][j] <= buyuk) {
                        Dizi2[i][j] = "~";
                    }
                }
            }
            cout << endl << "Cevrilmis Hali: " << endl << endl;
            for (int i = 0; i < boyut; i++) {//değiştirilmiş diziyi ekrana yazdırdık
                for (int j = 0; j < boyut; j++) {
                    cout << Dizi2[i][j] << "  ";
                }
                cout << endl;
            }
            break;
        case 2:
            Liste * liste = new Liste();//dinamik liste oluşturuyorz
            char secim;//değişkenlerimiz
            int diziBoyutu;
            int x = 0, y = 0;
            srand(time(NULL));//rastgele sayı için
            cout << "Lutfen Dizinin Boyutunu Giriniz: ";
            cin >> diziBoyutu;
            for (int i = 0; i < diziBoyutu; i++) {//diziye değerleri atıyoruz       
                int a = 0;
                a = (rand() % 99) + 1;
                liste->ekle(a);
            }
            system("CLS");
            gotoxy(0, 0);//satırdaki yerimizi ayarlıyoruz
            cout << "---->";
            liste->yazdir();//listeyi yazdırıyoruz
            cout << endl;
            x = 0, y = 0;
            do
            {
                cout << endl << endl;
                cout << "Asagi Ilerlemek Icin 'A' veya 'a' Tusuna Basiniz. " << endl;
                cout << "Yukari Ilerlemek Icin 'D' veya 'd' Tusuna Basiniz. " << endl;
                cout << "Cikmak Icin 'C' veya 'c' Tusuna Basiniz. " << endl;
                cin >> secim;
                system("CLS");
                if (secim == 'A' || secim == 'a') {//seçimimize göre ilerleme
                    liste->Ilerle(secim, diziBoyutu, x, y);
                }
                else if (secim == 'D' || secim == 'd') {
                    liste->Ilerle(secim, diziBoyutu, x, y);
                }
                liste->yazdir();//tekrardan ekkrana yazdırma
                cout << endl;
                if (secim == 'c' || secim == 'C') {
                    system("CLS");
                    break;
                }

            } while (secim != 'c' || secim != 'C');
            system("CLS");
            break;
        }

    } while (secim!=3||secim>3);
    
    return 0;
}

