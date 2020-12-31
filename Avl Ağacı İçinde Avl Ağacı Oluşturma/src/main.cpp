/**
* @file main.cpp
* @description Bir Iş Yeri Uygulamasi
* @course 1. Öğretim A Grubu
* @assignment 2
* @date 27.12.2020
* @author Mustafa Burak Aydın mustafa.aydin21@ogr.sakarya.edu.tr
*/
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "calisanlarDugum.hpp"
#include "calisanlar.hpp"
#include "AgacDugum.hpp"
#include "AvlAgaci.hpp"
using namespace std;//gerekli dosyaları ekledik
int main(int argc, char** argv) {
    AvlAgaci* Agac = new AvlAgaci();
	string adiSoyadi,satir,isYeri,calismabasla;
	int calismayaBaslamaYil, sayac=0;
	ifstream readFile("Deneme.txt");
	while (getline(readFile, satir)) {
		stringstream ss(satir);
		getline(ss, isYeri, '#');
		getline(ss, adiSoyadi, '#');
		getline(ss, calismabasla, '#');
		Agac->ekle(isYeri, adiSoyadi, stoi(calismabasla));
	}
	readFile.close();
	Agac->postOrder();
	delete Agac;
	return 0;
}