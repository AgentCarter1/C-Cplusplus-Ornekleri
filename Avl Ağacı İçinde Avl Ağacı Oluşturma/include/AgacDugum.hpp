/**
* @file AgacDugum.hpp
* @description Bir Iş Yeri Uygulamasi
* @course 1. Öğretim A Grubu
* @assignment 2
* @date 27.12.2020
* @author Mustafa Burak Aydın mustafa.aydin21@ogr.sakarya.edu.tr
*/
#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class AgacDugum {//büyük ağacımızın düğüm sınıfı
private://değişkenlerimiz
	int calismayaBaslama,calismaSenesi,mevcutYil=2020,elemanSayisi;
	string isYeri;
	AgacDugum* sol;
	AgacDugum* sag;
	Calisanlar* calisanlar;
public://fonksiyonlarımız
	AgacDugum(const string&, const string&,const int&);
	string dugumVeriGetir();
	int dugumCalismayaBaslamaGetir();
	AgacDugum*& dugumSolGetir();
	AgacDugum*& dugumSagGetir();
	Calisanlar* calisanlariGetir();
	int elemanSayisiGetir();
	void elemanSayisiAyarla();
	void dugumVeriAyarla(string);
	void dugumSolAyarla(AgacDugum*);
	void dugumSagAyarla(AgacDugum*);
	~AgacDugum();
};
#endif