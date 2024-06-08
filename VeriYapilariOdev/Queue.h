#ifndef QUEUE_H
#define QUEUE_H

#include <iostream> // Standart giri�/��k�� i�lemleri i�in k�t�phaneyi dahil ediyoruz

// Node s�n�f�, kuyru�un d���mlerini temsil eder
class Node {
public:
    int data; // D���m�n veri alan�
    Node* next; // Sonraki d���m� i�aret eden i�aret�i

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Queue s�n�f�, bir kuyru�u temsil eder
class Queue {
private:
    Node* head; // Kuyru�un ba��n� i�aret eden i�aret�i
    Node* end; // Kuyru�un sonunu i�aret eden i�aret�i

public:
    // Yap�c� fonksiyon, bo� bir kuyruk olu�turur
    Queue();

    // Kuyru�a yeni bir eleman ekler
    void enqueue(int data);

    // Kuyruktan bir eleman ��kar�r
    void dequeue();

    // Kuyru�un i�eri�ini g�r�nt�ler
    void display() const;

    // Kuyru�un bo� olup olmad���n� kontrol eder
    bool isEmpty() const;

    // Kuyru�u temizler
    void clear();

    // Kuyruktaki eleman say�s�n� d�nd�r�r
    int size() const;
};

#endif // QUEUE_H
