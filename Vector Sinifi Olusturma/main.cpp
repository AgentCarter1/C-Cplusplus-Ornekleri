#include <iostream>
using namespace std;

class VectorSinif
{

private:
    int diziBoyutu;
    int diziboyutTutan;
    int *diziVector;

public:
    VectorSinif()
    {
        diziVector = new int[1];
        diziBoyutu = 1;
        diziboyutTutan = 0;
    }
    void elemanEkle(int data)
    {
        diziVector[diziboyutTutan] = data;
        diziboyutTutan++;
        vectorBoyutYazdir();
        vectorKapasitaYazdir();
        if (diziboyutTutan == diziBoyutu)
        {
            dinamikBuyultme();
        }
    }
    void elemanSil()
    {
        diziboyutTutan--;
        int *yenidizi = new int[diziboyutTutan];
        for (int i = 0; i < diziboyutTutan; i++)
        {
            yenidizi[i] = diziVector[i];
        }
        delete[] diziVector;
        diziVector = yenidizi;
        void dinamikKucultme();
    }
    bool diziBosMu()
    {
        if (diziboyutTutan == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void ilkElemanYazdir()
    {
        cout << "Dizinin Ilk Elemani: " << diziVector[0];
    }
    void sonElemanYazdir()
    {
        cout << "Dizinin Son Elemani: " << diziVector[diziboyutTutan];
    }
    void butunElemanlariYazdir()
    {
        if (diziboyutTutan == 0)
        {
            cout << "Dikkata vector bos";
            cout << endl
                 << "Boyut: " << diziboyutTutan << endl
                 << "Kapasite: " << diziBoyutu;
        }
        for (int i = 0; i < diziboyutTutan; i++)
        {
            cout << diziVector[i] << endl;
        }
        cout << endl;
    }
    void dinamikBuyultme()
    {
        diziBoyutu *= 3;
        int *yenidizi = new int[diziBoyutu];
        for (int i = 0; i < diziboyutTutan; i++)
        {
            yenidizi[i] = diziVector[i];
        }
        delete[] diziVector;
        diziVector = yenidizi;
    }
    void dinamikKucultme()
    {
        if (diziboyutTutan < diziBoyutu / 3)
        {
            dinamikKucultme();
        }
        if (diziboyutTutan > diziBoyutu)
        {
            dinamikBuyultme();
        }
        diziBoyutu /= 2;
        int *yenidizi = new int[diziBoyutu];
        for (int i = 0; i < diziboyutTutan; i++)
        {
            yenidizi[i] = diziVector[i];
        }
        delete[] diziVector;
        diziVector = yenidizi;
    }
    void vectorBoyutYazdir()
    {
        cout << "Boyut : " << diziboyutTutan << endl;
    }
    void vectorKapasitaYazdir()
    {
        cout << "Kapasite: " << diziBoyutu << endl;
    }
};

int main()
{
    VectorSinif *vector = new VectorSinif();
    cout << "*******************Vectorun Elemanlari*******************";
    cout << endl
         << "******************************" << endl;
    vector->butunElemanlariYazdir();
    cout << "************************************" << endl;
    vector->elemanEkle(8);
    cout << endl;
    vector->elemanEkle(10);
    cout << endl;
    vector->elemanEkle(12);
    cout << endl;
    vector->elemanEkle(14);
    cout << "************************************" << endl;
    vector->butunElemanlariYazdir();
    return 0;
}