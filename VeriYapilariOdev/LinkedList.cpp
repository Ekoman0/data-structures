#include "LinkedList.h"

// LinkedList sýnýfýnýn yapýcý fonksiyonu, baþlangýçta baþý nullptr olarak ayarlar
LinkedList::LinkedList() {
    head = nullptr;  // Listenin baþýný nullptr olarak baþlatýr
}

// LinkedList sýnýfýnýn yýkýcý fonksiyonu, tüm düðümleri siler
LinkedList::~LinkedList() {
    // Listenin baþýndan baþlayarak tüm düðümleri siler
    while (head != nullptr) {
        LinkedListNode* temp = head;  // Geçici bir düðüm iþaretçisi oluþturur
        head = head->next;  // Baþ düðümünü bir sonraki düðüm olarak günceller
        delete temp;  // Geçici düðümü siler
    }
}

// Yeni bir düðümü listenin sonuna ekler
void LinkedList::insert(int data) {
    LinkedListNode* newLinkedListNode = new LinkedListNode(data);  // Yeni bir düðüm oluþturur
    if (head == nullptr) {
        head = newLinkedListNode;  // Liste boþsa, yeni düðümü baþa ekler
    }
    else {
        LinkedListNode* temp = head;  // Listenin baþýndan baþlayarak sonuna kadar gider
        while (temp->next != nullptr) {
            temp = temp->next;  // Bir sonraki düðüme geçer
        }
        temp->next = newLinkedListNode;  // Yeni düðümü listenin sonuna ekler
    }
    std::cout << data << " liste'ye eklendi." << std::endl;  // Bilgilendirme mesajý
}

// Belirtilen veriyi listeden kaldýrýr
void LinkedList::remove(int data) {
    if (head == nullptr) {
        std::cout << "Liste bos. Silme islemi yapilamaz." << std::endl;  // Liste boþsa, mesaj verir
        return;
    }
    if (head->data == data) {
        LinkedListNode* temp = head;  // Ýlk düðüm hedef veriyi içeriyorsa, baþ düðümü siler
        head = head->next;  // Baþ düðümünü günceller
        std::cout << temp->data << " listeden silindi." << std::endl;  // Bilgilendirme mesajý
        delete temp;  // Eski baþ düðümü siler
        return;
    }
    LinkedListNode* prev = head;  // Önceki düðüm iþaretçisi
    LinkedListNode* current = head->next;  // Mevcut düðüm iþaretçisi
    while (current != nullptr && current->data != data) {
        prev = current;  // Önceki düðümü günceller
        current = current->next;  // Bir sonraki düðüme geçer
    }
    if (current == nullptr) {
        std::cout << "Listede " << data << " bulunamadi." << std::endl;  // Veri bulunamazsa mesaj verir
        return;
    }
    prev->next = current->next;  // Mevcut düðümü listeden çýkarýr
    std::cout << current->data << " listeden silindi." << std::endl;  // Bilgilendirme mesajý
    delete current;  // Mevcut düðümü siler
}

// Listenin içeriðini ekrana yazdýrýr
void LinkedList::display() {
    if (head == nullptr) {
        std::cout << "Liste bos." << std::endl;  // Liste boþsa mesaj verir
        return;
    }
    LinkedListNode* temp = head;  // Baþ düðümden baþlayarak listeyi dolaþýr
    while (temp != nullptr) {
        std::cout << temp->data << " ";  // Her düðümün verisini yazdýrýr
        temp = temp->next;  // Bir sonraki düðüme geçer
    }
    std::cout << std::endl;  // Yeni satýra geçer
}

// Yeni bir düðümü listenin baþýna ekler
void LinkedList::insertAtBeginning(int data) {
    LinkedListNode* newNode = new LinkedListNode(data);  // Yeni bir düðüm oluþturur
    newNode->next = head;  // Yeni düðümün sonraki iþaretçisini baþ düðüm olarak ayarlar
    head = newNode;  // Baþ düðümünü yeni düðüm olarak ayarlar
    std::cout << data << " liste basina eklendi." << std::endl;  // Bilgilendirme mesajý
}

// Yeni bir düðümü listenin sonuna ekler
void LinkedList::insertAtEnd(int data) {
    LinkedListNode* newNode = new LinkedListNode(data);  // Yeni bir düðüm oluþturur
    if (head == nullptr) {
        head = newNode;  // Liste boþsa, yeni düðümü baþa ekler
    }
    else {
        LinkedListNode* temp = head;  // Listenin baþýndan baþlayarak sonuna kadar gider
        while (temp->next != nullptr) {
            temp = temp->next;  // Bir sonraki düðüme geçer
        }
        temp->next = newNode;  // Yeni düðümü listenin sonuna ekler
    }
    std::cout << data << " liste sonuna eklendi." << std::endl;  // Bilgilendirme mesajý
}

// Listenin baþýndaki düðümü kaldýrýr
void LinkedList::removeFromBeginning() {
    if (head == nullptr) {
        std::cout << "Liste bos. Silme islemi yapilamaz." << std::endl;  // Liste boþsa mesaj verir
        return;
    }
    LinkedListNode* temp = head;  // Baþ düðümü geçici olarak saklar
    head = head->next;  // Baþ düðümünü bir sonraki düðüm olarak günceller
    std::cout << temp->data << " listeden silindi." << std::endl;  // Bilgilendirme mesajý
    delete temp;  // Geçici düðümü siler
}

// Listenin sonundaki düðümü kaldýrýr
void LinkedList::removeFromEnd() {
    if (head == nullptr) {
        std::cout << "Liste bos. Silme islemi yapilamaz." << std::endl;  // Liste boþsa mesaj verir
        return;
    }
    LinkedListNode* prev = nullptr;  // Önceki düðüm iþaretçisi
    LinkedListNode* temp = head;  // Mevcut düðüm iþaretçisi
    while (temp->next != nullptr) {
        prev = temp;  // Önceki düðümü günceller
        temp = temp->next;  // Bir sonraki düðüme geçer
    }
    if (prev == nullptr) {
        head = nullptr;  // Liste tek düðümlü ise, baþ düðümünü nullptr yapar
    }
    else {
        prev->next = nullptr;  // Önceki düðümün sonraki iþaretçisini nullptr yapar
    }
    std::cout << temp->data << " listeden silindi." << std::endl;  // Bilgilendirme mesajý
    delete temp;  // Mevcut düðümü siler
}


void LinkedList::clear() {
    while (head != nullptr) {
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << "Liste temizlendi." << std::endl;
}

int LinkedList::size() const {
    int count = 0;
    LinkedListNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
