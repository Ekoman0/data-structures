// Cirpilama.h

#ifndef CIRPILAMA_H
#define CIRPILAMA_H

#include <iostream> // Giriþ/çýkýþ iþlemleri için gerekli kütüphane
#include <vector>   // Vektör veri yapýsý için gerekli kütüphane
#include <list>     // Baðlý liste veri yapýsý için gerekli kütüphane

class Cirpilama {
private:
    int maxSize;                    // Tablonun maksimum boyutu
    std::vector<std::list<int>> table; // Çýrpýlama tablosu

    // Hash fonksiyonu
    int hashFunction(int key);

public:
    // Yapýcý fonksiyon
    Cirpilama(int size);

    // Eleman ekleme fonksiyonu
    void ekle(int key);

    // Eleman çýkarma fonksiyonu
    void cikar(int key);

    // Tabloyu temizleme fonksiyonu
    void temizle();

    // Elemanlarý gösterme fonksiyonu
    void goster();

    // Eleman sayýsýný gösterme fonksiyonu
    int elemanSayisi();
};

#endif
