/**
* @file calisanlar.hpp
* @description Bir Iş Yeri Uygulamasi
* @course 1. Öğretim A Grubu
* @assignment 2
* @date 27.12.2020
* @author Mustafa Burak Aydın mustafa.aydin21@ogr.sakarya.edu.tr
*/

#ifndef CALISANLAR_HPP
#define CALISANLAR_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Calisanlar {//çalışanlar fonksiyonu
private://değişkenler
	int mevcutYil = 2020;
	int elemansayisitutan;
	calisanlarDugum* head;
	int height(calisanlarDugum*&);//fonksiyonlar
	int difference(calisanlarDugum*&);
	calisanlarDugum* rr_rotat(calisanlarDugum*&);
	calisanlarDugum* ll_rotat(calisanlarDugum*&);
	calisanlarDugum* lr_rotat(calisanlarDugum*&);
	calisanlarDugum* rl_rotat(calisanlarDugum*&);
	calisanlarDugum*& balance(calisanlarDugum*&);
	calisanlarDugum*& AraVeEkle(calisanlarDugum*&, const string&, const int&);
	void postOrder(calisanlarDugum*);
public://kullanıcının erişebileceği fonksiyonlar
	Calisanlar();
	void ekle(string, int );
	void listele();
	~Calisanlar();
};
#endif