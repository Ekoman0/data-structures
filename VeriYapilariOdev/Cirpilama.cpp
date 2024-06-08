// Cirpilama.cpp

#include "Cirpilama.h"

// Cirpilama s�n�f�n�n yap�c� fonksiyonu
Cirpilama::Cirpilama(int size) : maxSize(size) {
    table.resize(maxSize); // Tablo boyutunu belirle
}

// Hash fonksiyonu, bir anahtar�n hangi endeksle tabloya yerle�tirilece�ini belirler
int Cirpilama::hashFunction(int key) {
    return key % maxSize;
}

// Tabloya bir eleman ekler
void Cirpilama::ekle(int key) {
    int index = hashFunction(key); // Anahtar�n eklenece�i endeksi bul
    table[index].push_back(key); // Anahtar� ilgili endeksteki listeye ekle
}

// Tablodan bir eleman� ��kar�r
void Cirpilama::cikar(int key) {
    int index = hashFunction(key); // ��kar�lacak eleman�n bulundu�u endeksi bul
    table[index].remove(key); // Eleman� ilgili endeksteki listeden ��kar
}

// Tabloyu temizler, t�m listeleri bo�alt�r
void Cirpilama::temizle() {
    for (auto& list : table) {
        list.clear(); // T�m listeleri temizle
    }
}

// Tabloyu ekrana yazd�r�r
void Cirpilama::goster() {
    for (int i = 0; i < maxSize; ++i) {
        std::cout << "Bucket " << i << ": ";
        for (auto& element : table[i]) {
            std::cout << element << " "; // Her endeksteki listeyi yazd�r
        }
        std::cout << std::endl;
    }
}

// Tablodaki toplam eleman say�s�n� hesaplar ve d�nd�r�r
int Cirpilama::elemanSayisi() {
    int count = 0;
    for (int i = 0; i < maxSize; ++i) {
        count += table[i].size(); // Her endeksteki listenin boyutunu topla
    }
    return count;
}
