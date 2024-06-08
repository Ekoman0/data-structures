#ifndef STACK_H
#define STACK_H

#include <iostream>

// StackDugum s�n�f�, bir y���n d���m�n� temsil ediyor 
class StackDugum {
public:
    int veri;         // D���m�n veri alan�
    StackDugum* next;  // Sonraki d���m� i�aret eden i�aret�i

    // Yap�c� fonksiyon, veri alan�n� ve sonraki d���m� s�f�ra ayarl�yor
    StackDugum(int veri) {
        this->veri = veri;
        this->next = nullptr;
    }
};

// Stack s�n�f�, bir y���n� temsil ediyor
class Stack {
private:
    StackDugum* top;  // Y���n�n �st d���m�n� i�aret eden i�aret�i
    int elemanSayisi;
public:
    // Yap�c� fonksiyon, bo� bir y���n olu�turuyor
    Stack();

    // Y���na yeni bir eleman eklemek i�in kulland���m�z fonksiyon
    void push(int veri);

    // Y���ndan bir eleman ��karmak i�in kulland���m�z fonksiyon
    void pop();

    // Y���n� ekrana yazd�rmak i�in kulland���m�z fonksiyon
    void display();

    // Y���ndaki eleman say�s�n� g�stermek i�in kulland���m�z fonksiyon
    int size() const; // const ifadesi nesnenin durumu hakk�nda de�i�iklik yapmad���n� belirtir


    // Y���ndaki elemanlar� temizleyen fonksiyon
    void clear();

    // Y���n�n bo� olup olmad���n� kontrol eden fonksiyon
    bool isEmpty();
};

#endif // STACK_H
