/**
* @file calisanlarDugum.hpp
* @description Bir Iş Yeri Uygulamasi
* @course 1. Öğretim A Grubu
* @assignment 2
* @date 27.12.2020
* @author Mustafa Burak Aydın mustafa.aydin21@ogr.sakarya.edu.tr
*/
#ifndef CALISANLARDUGUM_HPP
#define CALISANLARDUGUM_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class calisanlarDugum {//calisanlar düğüm sınıfımız
private://değişkenlerimiz
	string AdiSoyadi;
	int calismayaBaslamaYili,mevcutYil,yukseklik,calismaSenesi,calisansayisi;
	calisanlarDugum* sag;
	calisanlarDugum* sol;
public://fonksiyonlarımız
	calisanlarDugum();
	calisanlarDugum(const string&, const int&);
	calisanlarDugum*& sagdakiniGetir();
	calisanlarDugum*& soldakiniGetir();
	string adiSoyadiGetir();
	int mevcutYilGetir();
	void calisanSayisiArttir();
	int calisanSayisiniGetir();
	int calismayaBaslamaYiliniGetir();
	void adiSoyadaVeriAta(string);
	int calismaSenesiniAta(int a);
	int calismaSenesiniGetir();
	int kacSeneCalisti();
	void calismayaBaslamaYiliniAta(int);
	void butunBilgileriAta(string&, int&);
	~calisanlarDugum();
};
#endif