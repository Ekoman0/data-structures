// Cirpilama.h

#ifndef CIRPILAMA_H
#define CIRPILAMA_H

#include <iostream> // Giri�/��k�� i�lemleri i�in gerekli k�t�phane
#include <vector>   // Vekt�r veri yap�s� i�in gerekli k�t�phane
#include <list>     // Ba�l� liste veri yap�s� i�in gerekli k�t�phane

class Cirpilama {
private:
    int maxSize;                    // Tablonun maksimum boyutu
    std::vector<std::list<int>> table; // ��rp�lama tablosu

    // Hash fonksiyonu
    int hashFunction(int key);

public:
    // Yap�c� fonksiyon
    Cirpilama(int size);

    // Eleman ekleme fonksiyonu
    void ekle(int key);

    // Eleman ��karma fonksiyonu
    void cikar(int key);

    // Tabloyu temizleme fonksiyonu
    void temizle();

    // Elemanlar� g�sterme fonksiyonu
    void goster();

    // Eleman say�s�n� g�sterme fonksiyonu
    int elemanSayisi();
};

#endif
