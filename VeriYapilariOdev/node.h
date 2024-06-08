#ifndef NODE_H
#define NODE_H

// Node sýnýfý, baðlý listemizin her bir düðümünü temsil eder.
class Node {
public:
    int data;             // Düðümün veri alaný
    Node* next;           // Bir sonraki düðüme iþaret eden iþaretçi

    // Yapýcý fonksiyon, yeni bir düðüm oluþturur ve veriyi ayarlar
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

#endif // NODE_H
