#ifndef NODE_H
#define NODE_H

// Node s�n�f�, ba�l� listemizin her bir d���m�n� temsil eder.
class Node {
public:
    int data;             // D���m�n veri alan�
    Node* next;           // Bir sonraki d���me i�aret eden i�aret�i

    // Yap�c� fonksiyon, yeni bir d���m olu�turur ve veriyi ayarlar
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

#endif // NODE_H
