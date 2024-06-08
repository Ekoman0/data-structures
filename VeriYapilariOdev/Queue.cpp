#include "Queue.h"          // Queue sýnýfýný içeren baþlýk dosyasýný dahil ediyoruz
#include <iostream>           // Standart giriþ/çýkýþ iþlemleri için kütüphaneyi dahil ediyoruz

using namespace std;           // std isim alanýný kullanacaðýmýzý belirtiyoruz

Queue::Queue() {
    head = nullptr;               // Kuyruðun önü ve sonunun baþlangýçta boþ olduðunu belirtir
    end = nullptr;
}

void Queue::enqueue(int data) {
    Node* newNode = new Node(data);         // Yeni bir düðüm oluþturuluyor
    if (end == nullptr) {
        head = end = newNode;               // Eðer kuyruk boþsa, yeni düðüm hem kuyruðun baþýna hem de sonuna eklenir
    }
    else {
        end->next = newNode;                // Kuyruðun sonundaki düðümün bir sonraki düðümü olarak yeni düðüm atanýr
        end = newNode;                        // Yeni düðüm kuyruðun sonu olarak atanýr
    }
    cout << data << " kuyruða eklendi." << endl;     // Eklenen verinin bilgisi ekrana yazdýrýlýr
}

void Queue::dequeue() {
    if (head == nullptr) {
        cout << "Kuyruk boþ." << endl;     // Eðer kuyruk boþsa bu durum kullanýcýya bildirilir
        return;
    }
    Node* temp = head;                   // Kuyruðun baþýndaki düðüm geçici bir deðiþkene atanýr
    head = head->next;                    // Kuyruðun baþýndaki düðüm bir sonraki düðümle deðiþtirilir
    if (head == nullptr) {
        end = nullptr;                                // Eðer kuyruk boþsa kuyruðun sonu da boþ olur
    }
    cout << temp->data << " kuyruktan çýkarýldý." << endl; // Çýkarýlan verinin bilgisi ekrana yazdýrýlýr
    delete temp;                         // Çýkarýlan düðüm bellekten silinir
}

void Queue::display() const {
    if (head == nullptr) {
        cout << "Kuyruk boþ." << endl;       // Eðer kuyruk boþsa bu durum kullanýcýya bildirilir
        return;
    }
    Node* temp = head;                     // Kuyruðun baþýndaki düðüm geçici bir deðiþkene atanýr
    while (temp != nullptr) {
        cout << temp->data << " ";        // Kuyruktaki her veri sýrayla ekrana yazdýrýlýr
        temp = temp->next;                 // Sonraki düðüme geçilir
    }
    cout << endl;                         // Ekranda daha düzenli bir görüntü saðlamak için yeni satýra geçilir
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();                            // Kuyruk boþalana kadar elemanlarý çýkar
    }
    cout << "Kuyruk temizlendi." << endl;
}

bool Queue::isEmpty() const {
    return head == nullptr;                       // Kuyruðun boþ olup olmadýðýný kontrol eder
}

int Queue::size() const {
    int count = 0;                               // Eleman sayýsýný tutmak için bir sayaç oluþturuyoruz
    Node* temp = head;                           // Kuyruðun baþýndaki düðüm geçici bir deðiþkene atanýr
    while (temp != nullptr) {
        count++;                                  // Her düðüm bulunduðunda sayaç artýrýlýr
        temp = temp->next;                      // Sonraki düðüme geçilir
    }
    return count;                             // Toplam düðüm sayýsý döndürülür
}
