/**
* @file AgacDugum.cpp
* @description Bir Iş Yeri Uygulamasi
* @course 1. Öğretim A Grubu
* @assignment 2
* @date 27.12.2020
* @author Mustafa Burak Aydın mustafa.aydin21@ogr.sakarya.edu.tr
*/
#include<iostream>
#include<fstream>
#include<string>
#include "calisanlarDugum.hpp"
#include "calisanlar.hpp"
#include "AgacDugum.hpp"
#include "AvlAgaci.hpp"
using namespace std;

	AgacDugum::AgacDugum(const string& isyeri, const string& adiSoyadi,const int& calismayaBaslamaYili) {//kurucu fonksiyonumuz
		isYeri = isyeri;
		calisanlar = new Calisanlar();
		calisanlar->ekle(adiSoyadi, calismayaBaslamaYili);
		sol = NULL;
		sag = NULL;
		calismayaBaslama = calismayaBaslamaYili;
		calismaSenesi = mevcutYil - calismayaBaslamaYili;
	}
	string AgacDugum::dugumVeriGetir() {//verileri tek tek getiren fonksiyonlarımız
		return isYeri;
	}
	int AgacDugum::dugumCalismayaBaslamaGetir() {
		return calismayaBaslama;
	}
	AgacDugum*& AgacDugum::dugumSolGetir() {
		return sol;
	}
	AgacDugum*& AgacDugum::dugumSagGetir() {
		return sag;
	}
	Calisanlar* AgacDugum::calisanlariGetir() {
		return calisanlar;
	}
	int AgacDugum::elemanSayisiGetir() {
		return elemanSayisi;
	}
	void AgacDugum::elemanSayisiAyarla() {//eleman sayısını bir arttırıyoruz
		elemanSayisi = elemanSayisi + 1;
	}
	void AgacDugum::dugumVeriAyarla(string sr) {//verileri atama fonksiyonumuz
		isYeri = sr;
	}
	void AgacDugum::dugumSolAyarla(AgacDugum* s1) {
		sol = s1;
	}
	void AgacDugum::dugumSagAyarla(AgacDugum* sg) {
		sag = sg;
	}
	AgacDugum::~AgacDugum() {//yıkıcı fonksiyonumuz
		delete calisanlar,sol,sag;
	}
