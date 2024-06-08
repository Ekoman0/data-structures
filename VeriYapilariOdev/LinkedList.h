#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// LinkedListNode sýnýfý, baðlý listemizin her bir düðümünü temsil eder.
class LinkedListNode {
public:
    int data;                                 // Düðümün veri alaný
    LinkedListNode* next;                    // Bir sonraki düðüme iþaret eden iþaretçi

    // Yapýcý fonksiyon, yeni bir düðüm oluþturur ve veriyi ayarlar
    LinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList sýnýfý, baðlý listeyi temsil eder.
class LinkedList {
private:
    LinkedListNode* head;                // Baðlý listenin baþýný iþaret eden iþaretçi

public:
    // Yapýcý fonksiyon, baþlangýçta head'i nullptr olarak ayarlar
    LinkedList();

    // Yýkýcý fonksiyon, baðlý listedeki tüm düðümleri siler
    ~LinkedList();

    // Verilen veriyi baðlý listeye ekler
    void insert(int data);

    // Verilen veriyi baðlý listeden kaldýrýr
    void remove(int data);

    // Baðlý listeyi ekrana yazdýrýr
    void display();

    // Yeni eklenen fonksiyonlar

    // Veriyi listenin baþýna ekler
    void insertAtBeginning(int data);

    // Veriyi listenin sonuna ekler
    void insertAtEnd(int data);

    // Listenin baþýndaki düðümü kaldýrýr
    void removeFromBeginning();

    // Listenin sonundaki düðümü kaldýrýr
    void removeFromEnd();

    void clear();            // Listeyi temizler
    int size() const;        // Listedeki eleman sayýsýný döndürür
};

#endif

