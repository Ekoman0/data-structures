#include "Queue.h"          // Queue s�n�f�n� i�eren ba�l�k dosyas�n� dahil ediyoruz
#include <iostream>           // Standart giri�/��k�� i�lemleri i�in k�t�phaneyi dahil ediyoruz

using namespace std;           // std isim alan�n� kullanaca��m�z� belirtiyoruz

Queue::Queue() {
    head = nullptr;               // Kuyru�un �n� ve sonunun ba�lang��ta bo� oldu�unu belirtir
    end = nullptr;
}

void Queue::enqueue(int data) {
    Node* newNode = new Node(data);         // Yeni bir d���m olu�turuluyor
    if (end == nullptr) {
        head = end = newNode;               // E�er kuyruk bo�sa, yeni d���m hem kuyru�un ba��na hem de sonuna eklenir
    }
    else {
        end->next = newNode;                // Kuyru�un sonundaki d���m�n bir sonraki d���m� olarak yeni d���m atan�r
        end = newNode;                        // Yeni d���m kuyru�un sonu olarak atan�r
    }
    cout << data << " kuyru�a eklendi." << endl;     // Eklenen verinin bilgisi ekrana yazd�r�l�r
}

void Queue::dequeue() {
    if (head == nullptr) {
        cout << "Kuyruk bo�." << endl;     // E�er kuyruk bo�sa bu durum kullan�c�ya bildirilir
        return;
    }
    Node* temp = head;                   // Kuyru�un ba��ndaki d���m ge�ici bir de�i�kene atan�r
    head = head->next;                    // Kuyru�un ba��ndaki d���m bir sonraki d���mle de�i�tirilir
    if (head == nullptr) {
        end = nullptr;                                // E�er kuyruk bo�sa kuyru�un sonu da bo� olur
    }
    cout << temp->data << " kuyruktan ��kar�ld�." << endl; // ��kar�lan verinin bilgisi ekrana yazd�r�l�r
    delete temp;                         // ��kar�lan d���m bellekten silinir
}

void Queue::display() const {
    if (head == nullptr) {
        cout << "Kuyruk bo�." << endl;       // E�er kuyruk bo�sa bu durum kullan�c�ya bildirilir
        return;
    }
    Node* temp = head;                     // Kuyru�un ba��ndaki d���m ge�ici bir de�i�kene atan�r
    while (temp != nullptr) {
        cout << temp->data << " ";        // Kuyruktaki her veri s�rayla ekrana yazd�r�l�r
        temp = temp->next;                 // Sonraki d���me ge�ilir
    }
    cout << endl;                         // Ekranda daha d�zenli bir g�r�nt� sa�lamak i�in yeni sat�ra ge�ilir
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();                            // Kuyruk bo�alana kadar elemanlar� ��kar
    }
    cout << "Kuyruk temizlendi." << endl;
}

bool Queue::isEmpty() const {
    return head == nullptr;                       // Kuyru�un bo� olup olmad���n� kontrol eder
}

int Queue::size() const {
    int count = 0;                               // Eleman say�s�n� tutmak i�in bir saya� olu�turuyoruz
    Node* temp = head;                           // Kuyru�un ba��ndaki d���m ge�ici bir de�i�kene atan�r
    while (temp != nullptr) {
        count++;                                  // Her d���m bulundu�unda saya� art�r�l�r
        temp = temp->next;                      // Sonraki d���me ge�ilir
    }
    return count;                             // Toplam d���m say�s� d�nd�r�l�r
}
