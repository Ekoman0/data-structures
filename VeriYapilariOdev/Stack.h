#ifndef STACK_H
#define STACK_H

#include <iostream>

// StackDugum sýnýfý, bir yýðýn düðümünü temsil ediyor 
class StackDugum {
public:
    int veri;         // Düðümün veri alaný
    StackDugum* next;  // Sonraki düðümü iþaret eden iþaretçi

    // Yapýcý fonksiyon, veri alanýný ve sonraki düðümü sýfýra ayarlýyor
    StackDugum(int veri) {
        this->veri = veri;
        this->next = nullptr;
    }
};

// Stack sýnýfý, bir yýðýný temsil ediyor
class Stack {
private:
    StackDugum* top;  // Yýðýnýn üst düðümünü iþaret eden iþaretçi
    int elemanSayisi;
public:
    // Yapýcý fonksiyon, boþ bir yýðýn oluþturuyor
    Stack();

    // Yýðýna yeni bir eleman eklemek için kullandýðýmýz fonksiyon
    void push(int veri);

    // Yýðýndan bir eleman çýkarmak için kullandýðýmýz fonksiyon
    void pop();

    // Yýðýný ekrana yazdýrmak için kullandýðýmýz fonksiyon
    void display();

    // Yýðýndaki eleman sayýsýný göstermek için kullandýðýmýz fonksiyon
    int size() const; // const ifadesi nesnenin durumu hakkýnda deðiþiklik yapmadýðýný belirtir


    // Yýðýndaki elemanlarý temizleyen fonksiyon
    void clear();

    // Yýðýnýn boþ olup olmadýðýný kontrol eden fonksiyon
    bool isEmpty();
};

#endif // STACK_H
