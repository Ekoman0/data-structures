#include "Stack.h" // Stack s�n�f�n� i�eren ba�l�k dosyas�n� dahil ediyoruz

Stack::Stack() {
    top = nullptr; // Y���n�n tepesi ba�lang��ta bo� olarak ayarl�yoruz
}

void Stack::push(int veri) {
    StackDugum* newNode = new StackDugum(veri); // Yeni bir d���m olu�turuluyor
    if (top == nullptr) {
        top = newNode; // E�er y���n bo�sa, yeni d���m y���n�n tepesine atan�r
    }
    else {
        newNode->next = top; // Y���n�n tepesindeki d���m, yeni d���m�n bir sonraki d���m� olarak atan�r
        top = newNode; // Yeni d���m y���n�n tepesi haline gelir
    }
    std::cout << veri << "Yigin'a girilen veri eklendi." << std::endl; // Eklenen verinin bilgisi ekrana yazd�r�l�yor
    elemanSayisi++; // burada y���ndaki eleman say�s�n� g�sterdi�imiz fonksiyonda kullanmak i�in eleman say�s�n� her eleman eklendi�inde bir artt�r�yoruz
}

void Stack::pop() {
    if (top == nullptr) {
        std::cout << "Stack bos." << std::endl; // E�er y���n bo�sa bu durum kullan�c�ya bildirilir
        return;
    }
    StackDugum* temp = top; // Y���n�n tepesindeki d���m ge�ici bir de�i�kene atan�r
    top = top->next; // Y���n�n tepesindeki d���m bir sonraki d���mle de�i�tirilir
    std::cout << temp->veri << " - Yigindan veri cikarildi." << std::endl; // ��kar�lan verinin bilgisi ekrana yazd�r�l�r
    delete temp; // ��kar�lan d���m bellekten silinir
    elemanSayisi--;

}

void Stack::display() {
    if (top == nullptr) {
        std::cout << "Yigin bos." << std::endl; // E�er y���n bo�sa bu durum kullan�c�ya bildirilir
        return;
    }
    StackDugum* temp = top;                  // Y���n�n tepesindeki d���m ge�ici bir de�i�kene atan�r
    while (temp != nullptr) {
        std::cout << temp->veri << " ";      // Y���ndaki her veri s�rayla ekrana yazd�r�l�r
        temp = temp->next;                  // Sonraki d���me ge�ilir
    }
    std::cout << std::endl; // Ekranda daha d�zenli bir g�r�nt� sa�lamak i�in yeni sat�ra ge�ilir
}

void Stack::clear() {
    while (top != nullptr) {
        StackDugum* temp = top; // Y���n�n tepesindeki d���m ge�ici bir de�i�kene atan�r
        top = top->next; // Y���n�n tepesindeki d���m bir sonraki d���mle de�i�tirilir
        delete temp; // ��kar�lan d���m bellekten silinir
        elemanSayisi = 0;
    }
    std::cout << "Yigin temizlendi." << std::endl; // Temizleme i�lemi tamamland���nda bildirim verilir
}

int Stack::size() const {
    return elemanSayisi; // Y���ndaki eleman say�s�n� d�nd�r�r
}


