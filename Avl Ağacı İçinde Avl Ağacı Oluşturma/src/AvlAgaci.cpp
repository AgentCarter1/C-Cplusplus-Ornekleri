/**
* @file AvlAgaci.cpp
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

	int AvlAgaci::height(AgacDugum*& yukseklik) {//yüksekliği bulan fonksiyon
		int h = 0;
		if (yukseklik != NULL) {
			int l_height = height(yukseklik->dugumSolGetir());
			int r_height = height(yukseklik->dugumSagGetir());
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}
		return h;
	}
	int AvlAgaci::difference(AgacDugum*& Difference) {//avl ağacı için gerekli olan fonksiyonlarımız
		int l_height = height(Difference->dugumSolGetir());
		int r_height = height(Difference->dugumSagGetir());
		int b_factor = l_height - r_height;
		return b_factor;
	}
	AgacDugum* AvlAgaci::rr_rotat(AgacDugum*& parent) {
		AgacDugum* temp;
		temp = parent->dugumSagGetir();
		parent->dugumSagGetir() = temp->dugumSolGetir();
		temp->dugumSolGetir() = parent;
		return temp;
	}
	AgacDugum* AvlAgaci::ll_rotat(AgacDugum*& parent) {
		AgacDugum* temp;
		temp = parent->dugumSolGetir();
		parent->dugumSolGetir() = temp->dugumSagGetir();
		temp->dugumSagGetir() = parent;
		return temp;
	}
	AgacDugum* AvlAgaci::lr_rotat(AgacDugum*& parent) {
		AgacDugum* temp ;
		temp = parent->dugumSolGetir();
		parent->dugumSolGetir() = rr_rotat(temp);
		return ll_rotat(parent);
	}
	AgacDugum* AvlAgaci::rl_rotat(AgacDugum*& parent) {
		AgacDugum* temp;
		temp = parent->dugumSagGetir();
		parent->dugumSagGetir() = ll_rotat(temp);
		return rr_rotat(parent);
	}
	AgacDugum* AvlAgaci::balance(AgacDugum*& t) {
		int bal_factor = difference(t);
		if (bal_factor > 1) {
			if (difference(t->dugumSolGetir()) > 0)
				t = ll_rotat(t);
			else
				t = lr_rotat(t);
		}
		else if (bal_factor < -1) {
			if (difference(t->dugumSagGetir()) > 0)
				t = rl_rotat(t);
			else
				t = rr_rotat(t);
		}
		return t;
	}	
	AgacDugum*& AvlAgaci::AraVeEkle(AgacDugum*& alt_dugum, const string& isYeri, const string& AdiSoyadi, const int& calismayaBaslamaTarihi) {//ekleme
		if (alt_dugum == NULL) {//eğer düğüm boşsa ekliyoruz
			alt_dugum = new AgacDugum(isYeri, AdiSoyadi, calismayaBaslamaTarihi);
			alt_dugum->elemanSayisiAyarla();
			alt_dugum->dugumSolGetir() = NULL;
			alt_dugum->dugumSagGetir() = NULL;
			return alt_dugum;
		}
		//önce eleman sayısına göre sonra iş yerine göre ayırıp ekleme yapıyoruz
		else if (elemanSayisiTutan < alt_dugum->elemanSayisiGetir()) {//eleman sayısını kıyaslıyoruz
			if (isYeri > alt_dugum->dugumVeriGetir()) {//doğru iş yerini arıyoruz
				alt_dugum = balance(alt_dugum);
				AraVeEkle(alt_dugum->dugumSolGetir(), isYeri, AdiSoyadi, calismayaBaslamaTarihi);
			}
			else if (isYeri == alt_dugum->dugumVeriGetir()) {//eğer eşitse aynı yere ekliyoruz
				alt_dugum = balance(alt_dugum);
				alt_dugum->calisanlariGetir()->ekle(AdiSoyadi, calismayaBaslamaTarihi);				
				alt_dugum->elemanSayisiAyarla();
				elemanSayisiTutan = alt_dugum->elemanSayisiGetir();
			}
			else {//değilse sagdan devam ediyoruz
				AraVeEkle(alt_dugum->dugumSagGetir(), isYeri, AdiSoyadi, calismayaBaslamaTarihi);
			}
		}
		else if (elemanSayisiTutan >= alt_dugum->elemanSayisiGetir()) {//eleman sayısını kontrol ediyoruz gene
			if (isYeri > alt_dugum->dugumVeriGetir()) {
				AraVeEkle(alt_dugum->dugumSolGetir(), isYeri, AdiSoyadi, calismayaBaslamaTarihi);
			}
			else if (isYeri == alt_dugum->dugumVeriGetir()) {
				alt_dugum = balance(alt_dugum);
				alt_dugum->calisanlariGetir()->ekle(AdiSoyadi, calismayaBaslamaTarihi);	
				alt_dugum->elemanSayisiAyarla();
				elemanSayisiTutan = alt_dugum->elemanSayisiGetir();
			}
			else if(isYeri < alt_dugum->dugumVeriGetir()){
				AraVeEkle(alt_dugum->dugumSagGetir(), isYeri, AdiSoyadi, calismayaBaslamaTarihi);
			}
		}//eğer hiçbirine uymazsa en başa gelip yeni düğüm oluşturuyor
		return alt_dugum;
	}
	void AvlAgaci::postOrder(AgacDugum* alt_dugum)const {//ekrana postorder şekilde yazdırma
		if (alt_dugum != NULL) {
			postOrder(alt_dugum->dugumSagGetir());	
			postOrder(alt_dugum->dugumSolGetir());						
			cout << alt_dugum->dugumVeriGetir() <<  endl;
			alt_dugum->calisanlariGetir()->listele();
			cout << endl <<endl;	
		}
	}
	AvlAgaci::AvlAgaci() {//kurucu fonksiyonu
		root = NULL;
	}
	void AvlAgaci::mevcutYilAyarla(int yil) {//yili ayarlama
		mevcutYil = yil;
	}
	void AvlAgaci::postOrder()const {//ekrana yazdırma
		postOrder(root);
	}
	void AvlAgaci::ekle(const string& isYeri, const string& AdiSoyadi, const int& CalismayaBaslamaTarihi) {//ağaca eleman ekleme
		AraVeEkle(root, isYeri, AdiSoyadi, CalismayaBaslamaTarihi);
	}
	AvlAgaci::~AvlAgaci() {//yıkıcı fonksiyonu
		delete root;
	}