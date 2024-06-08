#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// LinkedListNode s�n�f�, ba�l� listemizin her bir d���m�n� temsil eder.
class LinkedListNode {
public:
    int data;                                 // D���m�n veri alan�
    LinkedListNode* next;                    // Bir sonraki d���me i�aret eden i�aret�i

    // Yap�c� fonksiyon, yeni bir d���m olu�turur ve veriyi ayarlar
    LinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList s�n�f�, ba�l� listeyi temsil eder.
class LinkedList {
private:
    LinkedListNode* head;                // Ba�l� listenin ba��n� i�aret eden i�aret�i

public:
    // Yap�c� fonksiyon, ba�lang��ta head'i nullptr olarak ayarlar
    LinkedList();

    // Y�k�c� fonksiyon, ba�l� listedeki t�m d���mleri siler
    ~LinkedList();

    // Verilen veriyi ba�l� listeye ekler
    void insert(int data);

    // Verilen veriyi ba�l� listeden kald�r�r
    void remove(int data);

    // Ba�l� listeyi ekrana yazd�r�r
    void display();

    // Yeni eklenen fonksiyonlar

    // Veriyi listenin ba��na ekler
    void insertAtBeginning(int data);

    // Veriyi listenin sonuna ekler
    void insertAtEnd(int data);

    // Listenin ba��ndaki d���m� kald�r�r
    void removeFromBeginning();

    // Listenin sonundaki d���m� kald�r�r
    void removeFromEnd();

    void clear();            // Listeyi temizler
    int size() const;        // Listedeki eleman say�s�n� d�nd�r�r
};

#endif

