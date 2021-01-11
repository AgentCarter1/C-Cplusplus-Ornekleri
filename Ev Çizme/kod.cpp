#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>
using namespace std;
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Cati {
public:
	void catiCiz(int genislik,int catiyukseklik,int x1,int x2) {
		int yildiz = genislik - 2 * catiyukseklik;
		int bosluk = catiyukseklik;
		srand(time(0));
		char karakter = rand() % (254 - 128 + 1) + 128;
		int m = catiyukseklik / 2;
		int c = (catiyukseklik / 2)+m ;
		for (int i = 0; i < catiyukseklik; i++) {			
			for (int k = 0; k < yildiz; k++) {
				gotoxy(x1+k-i+c , x2+i);
				cout << karakter;
				Sleep(10);
			}
			cout << endl;
			yildiz += 2;
		}
	}
};
class Kat {
public:
	void katiCiz(int genislik,int catiyukseklik,int yukseklik,int x1,int x2) {
		srand(time(0));
		char karakter = rand() % (254 - 128 + 1) + 128;
		for (int i = 0; i < genislik; i++) {
			gotoxy(x1 + i, x2 + catiyukseklik);
			cout << karakter;
			Sleep(10);
		}
		for (int i = 0; i < yukseklik; i++) {
			gotoxy(x1 + genislik - 1, i + catiyukseklik + x2);
			cout << karakter << endl;
			Sleep(10);
		}
		for (int i = 0; i < genislik; i++) {
			gotoxy(genislik - i - 1 + x1, yukseklik - 1 + catiyukseklik + x2);
			cout << karakter;
			Sleep(10);
		}
		for (int i = 0; i < yukseklik; i++) {
			gotoxy(0 + x1, yukseklik - i - 1 + catiyukseklik + x2);
			cout << karakter << endl;
			Sleep(10);
		}
	}
};
class Kapi {
public:
	void kapiCiz(int cati,int genislik,int yukseklik,int x,int y) {
		srand(time(0));
		char karakter = rand() % (254 - 128 + 1) + 128;
		for (int i = 0; i < cati; i++) {
			for (int j = 0; j < cati + 3; j++) {
				gotoxy(((genislik / 2) + (genislik / 2)) + j, yukseklik + y + i);
				cout << karakter;
				Sleep(10);
			}
		}
	}
};
class Ev:public Cati, public Kat, public Kapi {
private:
	int catiYuksekligi, evGenisligi, evYuksekligi, x, y;
public:
	void evCiz() {
		cout << "Genislik: ";
		cin >> evGenisligi;
		cout << "Yukseklik: ";
		cin >> evYuksekligi;
		cout << "Cati Yukseklik: ";
		cin >> catiYuksekligi;
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
		catiCiz(evGenisligi,catiYuksekligi, x, y);
		katiCiz(evGenisligi, catiYuksekligi, evYuksekligi, x, y);
		kapiCiz(catiYuksekligi, evGenisligi, evYuksekligi, x, y);
	}
};
int main() {
	Ev prog;
	prog.evCiz();
	cin.get();
}