/**
* @file calisanlarDugum.cpp
* @description Bir Iş Yeri Uygulamasi
* @course 1. Öğretim A Grubu
* @assignment 2
* @date 27.12.2020
* @author Mustafa Burak Aydın mustafa.aydin21@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include "calisanlarDugum.hpp"
#include "calisanlar.hpp"
#include "AgacDugum.hpp"
#include "AvlAgaci.hpp"
using namespace std;

	calisanlarDugum::calisanlarDugum() {//çalışanlarduğum fonksiyonunun kurucu fonksiyonu
		sag = NULL;
		calismayaBaslamaYili = 0;
		AdiSoyadi="";
		mevcutYil = 2020;
		yukseklik = 0;
	}
	calisanlarDugum::calisanlarDugum(const string& adiSoyadi, const int& calismayabaslamatarihi) {//parametreli kurucu fonksiyonumuz
		sag = NULL;
		sol = NULL;
		AdiSoyadi = adiSoyadi;
		calismayaBaslamaYili = calismayabaslamatarihi;
		calismaSenesi = mevcutYil-calismayabaslamatarihi;
	}
	calisanlarDugum*& calisanlarDugum::sagdakiniGetir() {//sağa ulaşabilmek için fonksiyon
		return sag;
	}
	calisanlarDugum*& calisanlarDugum::soldakiniGetir() {//sola ulaşabilmek için fonksiyon
		return sol;
	}
	string calisanlarDugum::adiSoyadiGetir() {//adi soyadi getiren fonksiyon
		return AdiSoyadi;
	}
	int calisanlarDugum::mevcutYilGetir() {//mevcut yılı getiren fonksiyon
		return mevcutYil;
	}
	void calisanlarDugum::calisanSayisiArttir() {//calisan sayisini arttıran fonksiyon
		calisansayisi++;
	}
	int calisanlarDugum::calisanSayisiniGetir() {//çalışan sayısını getiren fonksiyon
		return calisansayisi;
	}
	int calisanlarDugum::calismayaBaslamaYiliniGetir() {//çalışmaya başlama senesine ulaştığımız fonksiyon
		return calismayaBaslamaYili;
	}
	void calisanlarDugum::adiSoyadaVeriAta(string adsoyad) {//tek tek verileri atayan fonksiyonumuz
		AdiSoyadi = adsoyad;
	}
	int calisanlarDugum::calismaSenesiniAta(int a) {
		return mevcutYil - a;
	}
	int calisanlarDugum::calismaSenesiniGetir() {
		return calismaSenesi;
	}
	int calisanlarDugum::kacSeneCalisti() {
		return calismaSenesi;
	}
	void calisanlarDugum::calismayaBaslamaYiliniAta(int yil) {
		calismayaBaslamaYili = yil;
	}
	void calisanlarDugum::butunBilgileriAta(string& adisoyadi, int& calismayabaslamaSenesi) {//verileri toplu atayan fonksiyonumuz
		AdiSoyadi = AdiSoyadi;
		calismayaBaslamaYili = calismayabaslamaSenesi;
		calismaSenesi = calismaSenesiniAta(calismayabaslamaSenesi);
	}
	calisanlarDugum::~calisanlarDugum() {//yıkıcı fonksiyonumuz
		delete sag,sol;
	}
