#include <iostream>
using namespace std;

class Yigit
{

private:
    int diziBoyutu;
    int diziboyutTutan;
    int* diziVector;

public:
    Yigit()
    {
        diziVector = new int[1];
        diziBoyutu = 1;
        diziboyutTutan = 0;
    }
    void push(int data)
    {
        diziVector[diziboyutTutan] = data;
        diziboyutTutan++;
        if (diziboyutTutan == diziBoyutu)
        {
            dinamikBuyultme();
        }
    }
    void reverseData(Yigit*& yigit2) {
        if (diziboyutTutan == 0)
        {
            cout << "Dikkata Yigit bos";
            cout << endl
                << "Boyut: " << diziboyutTutan << endl
                << "Kapasite: " << diziBoyutu;
        }
        for (int i = diziboyutTutan-1; i >= 0; i--)
        {
            yigit2->push(diziVector[i]);
        }
        cout << endl;
    }
    void pop()
    {
        diziboyutTutan--;
        int* yenidizi = new int[diziboyutTutan];
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
        diziBoyutu *= 2;
        int* yenidizi = new int[diziBoyutu];
        for (int i = 0; i < diziboyutTutan; i++)
        {
            yenidizi[i] = diziVector[i];
        }
        delete[] diziVector;
        diziVector = yenidizi;
    }
    void dinamikKucultme()
    {
        if (diziboyutTutan < diziBoyutu / 4)
        {
            dinamikKucultme();
        }
        if (diziboyutTutan > diziBoyutu)
        {
            dinamikBuyultme();
        }
        diziBoyutu /= 2;
        int* yenidizi = new int[diziBoyutu];
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
    Yigit* vector = new Yigit();
    cout << "*******************Vectorun Elemanlari*******************";
    cout << endl
        << "******************************" << endl;
    vector->butunElemanlariYazdir();
    cout << "************************************" << endl;
    vector->push(8);
    cout << endl;
    vector->push(10);
    cout << endl;
    vector->push(12);
    cout << endl;
    vector->push(14);
    cout << "************************************" << endl;
    vector->butunElemanlariYazdir();
    Yigit* vector2 = new Yigit();
    cout << "*********************Reverse Data*********************" << endl;
    vector->reverseData(vector2);
    vector2->butunElemanlariYazdir();
    return 0;
}
