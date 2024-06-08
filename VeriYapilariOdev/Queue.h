#ifndef QUEUE_H
#define QUEUE_H

#include <iostream> // Standart giriþ/çýkýþ iþlemleri için kütüphaneyi dahil ediyoruz

// Node sýnýfý, kuyruðun düðümlerini temsil eder
class Node {
public:
    int data; // Düðümün veri alaný
    Node* next; // Sonraki düðümü iþaret eden iþaretçi

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Queue sýnýfý, bir kuyruðu temsil eder
class Queue {
private:
    Node* head; // Kuyruðun baþýný iþaret eden iþaretçi
    Node* end; // Kuyruðun sonunu iþaret eden iþaretçi

public:
    // Yapýcý fonksiyon, boþ bir kuyruk oluþturur
    Queue();

    // Kuyruða yeni bir eleman ekler
    void enqueue(int data);

    // Kuyruktan bir eleman çýkarýr
    void dequeue();

    // Kuyruðun içeriðini görüntüler
    void display() const;

    // Kuyruðun boþ olup olmadýðýný kontrol eder
    bool isEmpty() const;

    // Kuyruðu temizler
    void clear();

    // Kuyruktaki eleman sayýsýný döndürür
    int size() const;
};

#endif // QUEUE_H
