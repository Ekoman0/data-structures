#include "Stack.h" // Stack sýnýfýný içeren baþlýk dosyasýný dahil ediyoruz

Stack::Stack() {
    top = nullptr; // Yýðýnýn tepesi baþlangýçta boþ olarak ayarlýyoruz
}

void Stack::push(int veri) {
    StackDugum* newNode = new StackDugum(veri); // Yeni bir düðüm oluþturuluyor
    if (top == nullptr) {
        top = newNode; // Eðer yýðýn boþsa, yeni düðüm yýðýnýn tepesine atanýr
    }
    else {
        newNode->next = top; // Yýðýnýn tepesindeki düðüm, yeni düðümün bir sonraki düðümü olarak atanýr
        top = newNode; // Yeni düðüm yýðýnýn tepesi haline gelir
    }
    std::cout << veri << "Yigin'a girilen veri eklendi." << std::endl; // Eklenen verinin bilgisi ekrana yazdýrýlýyor
    elemanSayisi++; // burada yýðýndaki eleman sayýsýný gösterdiðimiz fonksiyonda kullanmak için eleman sayýsýný her eleman eklendiðinde bir arttýrýyoruz
}

void Stack::pop() {
    if (top == nullptr) {
        std::cout << "Stack bos." << std::endl; // Eðer yýðýn boþsa bu durum kullanýcýya bildirilir
        return;
    }
    StackDugum* temp = top; // Yýðýnýn tepesindeki düðüm geçici bir deðiþkene atanýr
    top = top->next; // Yýðýnýn tepesindeki düðüm bir sonraki düðümle deðiþtirilir
    std::cout << temp->veri << " - Yigindan veri cikarildi." << std::endl; // Çýkarýlan verinin bilgisi ekrana yazdýrýlýr
    delete temp; // Çýkarýlan düðüm bellekten silinir
    elemanSayisi--;

}

void Stack::display() {
    if (top == nullptr) {
        std::cout << "Yigin bos." << std::endl; // Eðer yýðýn boþsa bu durum kullanýcýya bildirilir
        return;
    }
    StackDugum* temp = top;                  // Yýðýnýn tepesindeki düðüm geçici bir deðiþkene atanýr
    while (temp != nullptr) {
        std::cout << temp->veri << " ";      // Yýðýndaki her veri sýrayla ekrana yazdýrýlýr
        temp = temp->next;                  // Sonraki düðüme geçilir
    }
    std::cout << std::endl; // Ekranda daha düzenli bir görüntü saðlamak için yeni satýra geçilir
}

void Stack::clear() {
    while (top != nullptr) {
        StackDugum* temp = top; // Yýðýnýn tepesindeki düðüm geçici bir deðiþkene atanýr
        top = top->next; // Yýðýnýn tepesindeki düðüm bir sonraki düðümle deðiþtirilir
        delete temp; // Çýkarýlan düðüm bellekten silinir
        elemanSayisi = 0;
    }
    std::cout << "Yigin temizlendi." << std::endl; // Temizleme iþlemi tamamlandýðýnda bildirim verilir
}

int Stack::size() const {
    return elemanSayisi; // Yýðýndaki eleman sayýsýný döndürür
}


