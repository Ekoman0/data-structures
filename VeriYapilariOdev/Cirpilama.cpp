// Cirpilama.cpp

#include "Cirpilama.h"

// Cirpilama sýnýfýnýn yapýcý fonksiyonu
Cirpilama::Cirpilama(int size) : maxSize(size) {
    table.resize(maxSize); // Tablo boyutunu belirle
}

// Hash fonksiyonu, bir anahtarýn hangi endeksle tabloya yerleþtirileceðini belirler
int Cirpilama::hashFunction(int key) {
    return key % maxSize;
}

// Tabloya bir eleman ekler
void Cirpilama::ekle(int key) {
    int index = hashFunction(key); // Anahtarýn ekleneceði endeksi bul
    table[index].push_back(key); // Anahtarý ilgili endeksteki listeye ekle
}

// Tablodan bir elemaný çýkarýr
void Cirpilama::cikar(int key) {
    int index = hashFunction(key); // Çýkarýlacak elemanýn bulunduðu endeksi bul
    table[index].remove(key); // Elemaný ilgili endeksteki listeden çýkar
}

// Tabloyu temizler, tüm listeleri boþaltýr
void Cirpilama::temizle() {
    for (auto& list : table) {
        list.clear(); // Tüm listeleri temizle
    }
}

// Tabloyu ekrana yazdýrýr
void Cirpilama::goster() {
    for (int i = 0; i < maxSize; ++i) {
        std::cout << "Bucket " << i << ": ";
        for (auto& element : table[i]) {
            std::cout << element << " "; // Her endeksteki listeyi yazdýr
        }
        std::cout << std::endl;
    }
}

// Tablodaki toplam eleman sayýsýný hesaplar ve döndürür
int Cirpilama::elemanSayisi() {
    int count = 0;
    for (int i = 0; i < maxSize; ++i) {
        count += table[i].size(); // Her endeksteki listenin boyutunu topla
    }
    return count;
}
