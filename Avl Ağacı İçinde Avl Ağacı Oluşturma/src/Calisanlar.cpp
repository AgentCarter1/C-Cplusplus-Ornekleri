/**
* @file calisanlar.cpp
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

	int Calisanlar::height(calisanlarDugum*& yukseklik) {//yüksekliği bulan fonksiyonumuz
		int h = 0;
		if (yukseklik != NULL) {
			int l_height = height(yukseklik->soldakiniGetir());
			int r_height = height(yukseklik->sagdakiniGetir());
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}
		return h;
	}
	int Calisanlar::difference(calisanlarDugum*& Difference) {//bu fonksiyonlar avl ağacını oluşturabilmek için olan fonksiyonlar
		int l_height = height(Difference->soldakiniGetir());
		int r_height = height(Difference->sagdakiniGetir());
		int b_factor = l_height - r_height;
		return b_factor;
	}
	calisanlarDugum* Calisanlar::rr_rotat(calisanlarDugum*& parent) {
		calisanlarDugum* temp;
		temp = parent->sagdakiniGetir();
		parent->sagdakiniGetir() = temp->soldakiniGetir();
		temp->soldakiniGetir() = parent;
		return temp;
	}
	calisanlarDugum* Calisanlar::ll_rotat(calisanlarDugum*& parent) {
		calisanlarDugum* temp;
		temp = parent->soldakiniGetir();
		parent->soldakiniGetir() = temp->sagdakiniGetir();
		temp->sagdakiniGetir() = parent;
		return temp;
	}
	calisanlarDugum* Calisanlar::lr_rotat(calisanlarDugum*& parent) {
		calisanlarDugum* temp;
		temp = parent->soldakiniGetir();
		parent->soldakiniGetir() = rr_rotat(temp);
		return ll_rotat(parent);
	}
	calisanlarDugum* Calisanlar::rl_rotat(calisanlarDugum*& parent) {
		calisanlarDugum* temp;
		temp = parent->sagdakiniGetir();
		parent->sagdakiniGetir() = ll_rotat(temp);
		return rr_rotat(parent);
	}
	calisanlarDugum*& Calisanlar::balance(calisanlarDugum*& t) {//ayar yapan fonksiyonumuz
		int bal_factor = difference(t);
		if (bal_factor > 1) {
			if (difference(t->soldakiniGetir()) > 0)
				t = ll_rotat(t);
			else
				t = lr_rotat(t);
		}
		else if (bal_factor < -1) {
			if (difference(t->sagdakiniGetir()) > 0)
				t = rl_rotat(t);
			else
				t = rr_rotat(t);
		}
		return t;
	}
	calisanlarDugum*& Calisanlar::AraVeEkle(calisanlarDugum*& alt_dugum, const string& AdiSoyadi, const int& calismayaBaslamaTarihi) {
		if (alt_dugum == NULL) {//eğer boşsa eleman ekler ve eleman sayısını bir arttırır
			alt_dugum = new calisanlarDugum(AdiSoyadi, calismayaBaslamaTarihi);
			alt_dugum->calisanSayisiArttir();
			return alt_dugum;
		}
		else if(mevcutYil - calismayaBaslamaTarihi >= alt_dugum->calismaSenesiniGetir()){//çalışma senesi fazla 
			alt_dugum = balance(alt_dugum);//ayarımızı yapıyoruz
			alt_dugum->soldakiniGetir() = AraVeEkle(alt_dugum->soldakiniGetir(), AdiSoyadi, calismayaBaslamaTarihi);//	sola gidiyoruz	
		}
		else if (mevcutYil-calismayaBaslamaTarihi <= alt_dugum->calismaSenesiniGetir()) {//saga gidiyoruz
			alt_dugum = balance(alt_dugum);
			alt_dugum->sagdakiniGetir() = AraVeEkle(alt_dugum->sagdakiniGetir(), AdiSoyadi, calismayaBaslamaTarihi);//saga gidiyoruz
			
		}
		return alt_dugum;
	}
	void Calisanlar::postOrder(calisanlarDugum* alt_dugum) {//postorder şekilde yazdırma
		if (alt_dugum != NULL) {
			postOrder(alt_dugum->sagdakiniGetir());
			postOrder(alt_dugum->soldakiniGetir());			
			cout << alt_dugum->adiSoyadiGetir() << " - " << alt_dugum->calismayaBaslamaYiliniGetir() << " | ";			
		}
	}
	Calisanlar::Calisanlar() {//kurucu fonksiyonumuz
		head = NULL;
	}
	void Calisanlar::ekle(string AdiSoyadi, int calismayaBaslamaYili) {//ekleme fonksiyonumuz
		AraVeEkle(head, AdiSoyadi, calismayaBaslamaYili);
	}
	void Calisanlar::listele() {//yazdırma
		postOrder(head);
	}
	Calisanlar::~Calisanlar() {//yıkıcı
		delete head;
	}
