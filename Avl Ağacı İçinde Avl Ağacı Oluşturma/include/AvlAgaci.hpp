/**
* @file AvlAgaci.hpp
* @description Bir Iş Yeri Uygulamasi
* @course 1. Öğretim A Grubu
* @assignment 2
* @date 27.12.2020
* @author Mustafa Burak Aydın mustafa.aydin21@ogr.sakarya.edu.tr
*/
#ifndef AVLAGACI_HPP
#define AVLAGACI_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class AvlAgaci {
private:
	int mevcutYil = 2020, elemanSayisiTutan=0;
	AgacDugum* root;
	int height(AgacDugum*& yukseklik);
	int difference(AgacDugum*& Difference);
	AgacDugum* rr_rotat(AgacDugum*& parent);
	AgacDugum* ll_rotat(AgacDugum*& parent);
	AgacDugum* lr_rotat(AgacDugum*& parent);
	AgacDugum* rl_rotat(AgacDugum*& parent);
	AgacDugum* balance(AgacDugum*& t);
	AgacDugum*& AraVeEkle(AgacDugum*& alt_dugum, const string& isYeri, const string& AdiSoyadi, const int& calismayaBaslamaTarihi);
	void postOrder(AgacDugum* alt_dugum)const;
public:
	AvlAgaci();
	void mevcutYilAyarla(int yil);
	void postOrder()const;
	void ekle(const string& isYeri, const string& AdiSoyadi, const int& CalismayaBaslamaTarihi);
	~AvlAgaci();
};


#endif