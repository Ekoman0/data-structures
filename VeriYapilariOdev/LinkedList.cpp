#include "LinkedList.h"

// LinkedList s�n�f�n�n yap�c� fonksiyonu, ba�lang��ta ba�� nullptr olarak ayarlar
LinkedList::LinkedList() {
    head = nullptr;  // Listenin ba��n� nullptr olarak ba�lat�r
}

// LinkedList s�n�f�n�n y�k�c� fonksiyonu, t�m d���mleri siler
LinkedList::~LinkedList() {
    // Listenin ba��ndan ba�layarak t�m d���mleri siler
    while (head != nullptr) {
        LinkedListNode* temp = head;  // Ge�ici bir d���m i�aret�isi olu�turur
        head = head->next;  // Ba� d���m�n� bir sonraki d���m olarak g�nceller
        delete temp;  // Ge�ici d���m� siler
    }
}

// Yeni bir d���m� listenin sonuna ekler
void LinkedList::insert(int data) {
    LinkedListNode* newLinkedListNode = new LinkedListNode(data);  // Yeni bir d���m olu�turur
    if (head == nullptr) {
        head = newLinkedListNode;  // Liste bo�sa, yeni d���m� ba�a ekler
    }
    else {
        LinkedListNode* temp = head;  // Listenin ba��ndan ba�layarak sonuna kadar gider
        while (temp->next != nullptr) {
            temp = temp->next;  // Bir sonraki d���me ge�er
        }
        temp->next = newLinkedListNode;  // Yeni d���m� listenin sonuna ekler
    }
    std::cout << data << " liste'ye eklendi." << std::endl;  // Bilgilendirme mesaj�
}

// Belirtilen veriyi listeden kald�r�r
void LinkedList::remove(int data) {
    if (head == nullptr) {
        std::cout << "Liste bos. Silme islemi yapilamaz." << std::endl;  // Liste bo�sa, mesaj verir
        return;
    }
    if (head->data == data) {
        LinkedListNode* temp = head;  // �lk d���m hedef veriyi i�eriyorsa, ba� d���m� siler
        head = head->next;  // Ba� d���m�n� g�nceller
        std::cout << temp->data << " listeden silindi." << std::endl;  // Bilgilendirme mesaj�
        delete temp;  // Eski ba� d���m� siler
        return;
    }
    LinkedListNode* prev = head;  // �nceki d���m i�aret�isi
    LinkedListNode* current = head->next;  // Mevcut d���m i�aret�isi
    while (current != nullptr && current->data != data) {
        prev = current;  // �nceki d���m� g�nceller
        current = current->next;  // Bir sonraki d���me ge�er
    }
    if (current == nullptr) {
        std::cout << "Listede " << data << " bulunamadi." << std::endl;  // Veri bulunamazsa mesaj verir
        return;
    }
    prev->next = current->next;  // Mevcut d���m� listeden ��kar�r
    std::cout << current->data << " listeden silindi." << std::endl;  // Bilgilendirme mesaj�
    delete current;  // Mevcut d���m� siler
}

// Listenin i�eri�ini ekrana yazd�r�r
void LinkedList::display() {
    if (head == nullptr) {
        std::cout << "Liste bos." << std::endl;  // Liste bo�sa mesaj verir
        return;
    }
    LinkedListNode* temp = head;  // Ba� d���mden ba�layarak listeyi dola��r
    while (temp != nullptr) {
        std::cout << temp->data << " ";  // Her d���m�n verisini yazd�r�r
        temp = temp->next;  // Bir sonraki d���me ge�er
    }
    std::cout << std::endl;  // Yeni sat�ra ge�er
}

// Yeni bir d���m� listenin ba��na ekler
void LinkedList::insertAtBeginning(int data) {
    LinkedListNode* newNode = new LinkedListNode(data);  // Yeni bir d���m olu�turur
    newNode->next = head;  // Yeni d���m�n sonraki i�aret�isini ba� d���m olarak ayarlar
    head = newNode;  // Ba� d���m�n� yeni d���m olarak ayarlar
    std::cout << data << " liste basina eklendi." << std::endl;  // Bilgilendirme mesaj�
}

// Yeni bir d���m� listenin sonuna ekler
void LinkedList::insertAtEnd(int data) {
    LinkedListNode* newNode = new LinkedListNode(data);  // Yeni bir d���m olu�turur
    if (head == nullptr) {
        head = newNode;  // Liste bo�sa, yeni d���m� ba�a ekler
    }
    else {
        LinkedListNode* temp = head;  // Listenin ba��ndan ba�layarak sonuna kadar gider
        while (temp->next != nullptr) {
            temp = temp->next;  // Bir sonraki d���me ge�er
        }
        temp->next = newNode;  // Yeni d���m� listenin sonuna ekler
    }
    std::cout << data << " liste sonuna eklendi." << std::endl;  // Bilgilendirme mesaj�
}

// Listenin ba��ndaki d���m� kald�r�r
void LinkedList::removeFromBeginning() {
    if (head == nullptr) {
        std::cout << "Liste bos. Silme islemi yapilamaz." << std::endl;  // Liste bo�sa mesaj verir
        return;
    }
    LinkedListNode* temp = head;  // Ba� d���m� ge�ici olarak saklar
    head = head->next;  // Ba� d���m�n� bir sonraki d���m olarak g�nceller
    std::cout << temp->data << " listeden silindi." << std::endl;  // Bilgilendirme mesaj�
    delete temp;  // Ge�ici d���m� siler
}

// Listenin sonundaki d���m� kald�r�r
void LinkedList::removeFromEnd() {
    if (head == nullptr) {
        std::cout << "Liste bos. Silme islemi yapilamaz." << std::endl;  // Liste bo�sa mesaj verir
        return;
    }
    LinkedListNode* prev = nullptr;  // �nceki d���m i�aret�isi
    LinkedListNode* temp = head;  // Mevcut d���m i�aret�isi
    while (temp->next != nullptr) {
        prev = temp;  // �nceki d���m� g�nceller
        temp = temp->next;  // Bir sonraki d���me ge�er
    }
    if (prev == nullptr) {
        head = nullptr;  // Liste tek d���ml� ise, ba� d���m�n� nullptr yapar
    }
    else {
        prev->next = nullptr;  // �nceki d���m�n sonraki i�aret�isini nullptr yapar
    }
    std::cout << temp->data << " listeden silindi." << std::endl;  // Bilgilendirme mesaj�
    delete temp;  // Mevcut d���m� siler
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
