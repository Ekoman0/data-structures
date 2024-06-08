#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "LinkedList.h"
#include "IkiliAgac.h"
#include "Cirpilama.h"

using namespace std;
void Menu();
void   Yigin_uygulamasi();
void CirpilamaUygulamasi(Cirpilama& cirpilama);
void Kuyruk_uygulamasi();
void Bagli_liste_uygulamasi();
void IkiliAgacUygulamasi();

int main() {
    int secim;
    Cirpilama cirpilama(10); // Örnek bir hash tablosu oluşturduk

    while (true)
    {
       

        std::cout << "\n----------\n";
        std::cout << "1-Yigin Uygulamasi\n";
        std::cout << "2-Kuyruk Uygulamasi\n";
        std::cout << "3-Tek Yonlu Bagli Liste Uygulamasi\n";
        std::cout << "4-Ikili Agac  Uygulamasi\n";
        std::cout << "5-Cirpilma Uygulamasi\n";
        std::cout << "6-Programdan Cikis\n";
        std::cout << "----------\n";

        cin >> secim;



        if (std::cin.fail()) {
            std::cin.clear(); // Girilenleri temizle
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Hatalı girdiyi yoksay
            std::cout << "Gecersiz giris! Lutfen bir sayi girin.\n";
            continue; // Döngünün başına dön
        }

        if (secim == 6) {
            std::cout << "Programdan cikiliyor...\n";
            break; // while döngüsünden çık
        }

        switch (secim) {
        case 1:
            Yigin_uygulamasi();
            break;
        case 2:
            Kuyruk_uygulamasi();
            break;
        case 3:
            Bagli_liste_uygulamasi();
            break;
        case 4:
            IkiliAgacUygulamasi();
            break;

        case 5:
            CirpilamaUygulamasi(cirpilama); // Hash tablosu uygulamasını çağırdık
            break;
        case 6:
            cout << "Programdan cikiliyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim" << endl;
        }
    }

    return 0;
}



void   Yigin_uygulamasi() {
    Stack stack;
    int a,girilen_deger;

    do {
        
        std::cout << "\n\n----------Yigin Uygulamasi----------\n";
        cout << "1. Yigin'a ekle" << endl;
        cout << "2. Yigin'dan cikar" << endl;
        cout << "3. Yigin'i temizle" << endl;
        cout << "4. Yigin'daki eleman sayisini goster" << endl;
        cout << "5. Yigin'daki elemanlari goster " << endl;
        cout << "6. Ana menuye don" << endl;
        std::cout << "----------Yigin Uygulamasi----------\n";
        cout << "Seciminizi yapin: ";
        cin >> a;

        switch (a) {
        case 1:
            cout << "Eklemek istediginiz degeri girin: ";
            cin >> girilen_deger;
            stack.push(girilen_deger);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.clear();
            break;
        case 4:
            stack.display();
            break;
        case 5:
            cout << "Stack'teki eleman sayisi: " << stack.size() << endl;
            break;
        case 6:
            return;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }
    } while (a != 6);
}

void CirpilamaUygulamasi(Cirpilama& cirpilama) {
    int a, girilen_deger;

    do {
        std::cout << "\n\n----------Cirpilma Uygulamasi----------\n";
        std::cout << "1- Tabloya eleman ekle" << std::endl;
        std::cout << "2- Tabloya eleman cikar" << std::endl;
        std::cout << "3- Tabloyu temizle" << std::endl;
        std::cout << "4- Tabloyu göster" << std::endl;
        std::cout << "5- Tablodaki eleman sayisini göster" << std::endl;
        std::cout << "6- Ana menüye geri dön" << std::endl;
        std::cout << "----------Cirpilma Uygulamasi----------\n";
        std::cout << "Seciminizi yapin: ";
        std::cin >> a;

        switch (a) {
        case 1:
            std::cout << "Eklemek istediğiniz değeri girin: ";
            std::cin >> girilen_deger;
            cirpilama.ekle(girilen_deger);
            break;
        case 2:
            std::cout << "Çıkarmak istediğiniz değeri girin: ";
            std::cin >> girilen_deger;
            cirpilama.cikar(girilen_deger);
            break;
        case 3:
            cirpilama.temizle();
            std::cout << "Tablo temizlendi." << std::endl;
            break;
        case 4:
            std::cout << "Tablo:" << std::endl;
            cirpilama.goster();
            break;
        case 5:
            std::cout << "Tablodaki eleman sayisi: " << cirpilama.elemanSayisi() << std::endl;
            break;
        case 6:
            std::cout << "Ana menüye geri dönülüyor..." << std::endl;
            break;
        default:
            std::cout << "Gecersiz secim. Lütfen tekrar deneyin." << std::endl;
        }
    } while (a != 6);
}

void Kuyruk_uygulamasi() {
    Queue queue;
    int a, girilen_deger;

    do {
        std::cout << "\n\n----------Kuyruk Uygulamasi----------\n";
        cout << "Kuyruk Uygulamasi:" << endl;
        cout << "1. Kuyruga ekle" << endl;
        cout << "2. Kuyruktan cikar" << endl;
        cout << "3. Kuyrugu temizle" << endl;
        cout << "4. Kuyruktaki elemanlari goster " << endl;
        cout << "5.Kuyruktaki eleman sayisini goster " << endl;
        cout << "6.Menuye don. " << endl;
        std::cout << "----------Kuyruk Uygulamasi----------\n";
        cout << "Seciminizi yapin: ";
        cin >> a;

        switch (a) {
        case 1:
            cout << "Eklemek istediginiz degeri girin: ";
            cin >> girilen_deger;
            queue.enqueue(girilen_deger);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.clear();
            break;
        case 4:
            queue.display();
            break;

        case 5:
            cout << "Kuyruk'taki eleman sayisi: " << queue.size() << endl;
            break;

        case 6:
            cout << "Ana menuye donuluyor..." << endl;     
            break;

        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }
    } while (a != 6);
}

void Bagli_liste_uygulamasi() {
    LinkedList liste;
    int secim, deger;

    do {

        std::cout << "\n\n----------Bagli Liste Uygulamasi----------\n";
        cout << "1. Liste'ye ekle" << endl;
        cout << "2. Liste'den sil" << endl;
        cout << "3. Liste'yi temizle" << endl;
        cout << "4. Liste'yi goster" << endl;
        cout << "5. Listedeki eleman sayisini goster" << endl;
        cout << "6. Menuye don " << endl;
        std::cout << "----------Bagli Liste Uygulamasi----------\n";
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
        case 1:
            cout << "Ekleme turunu seciniz:" << endl;
            cout << "1- Araya eleman ekle" << endl;
            cout << "2- Sona eleman ekle" << endl;
            cout << "3- Liste islemlerine geri don" << endl;
            cout << "Seciminizi yapin: ";
            cin >> secim;
            switch (secim) {
            case 1:
                cout << "Araya eklenecek degeri girin: ";
                cin >> deger;
                liste.insertAtBeginning(deger);
                break;
            case 2:
                cout << "Sona eklenecek degeri girin: ";
                cin >> deger;
                liste.insertAtEnd(deger);
                break;
            case 3:
                cout << "Liste islemlerine geri donuluyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
            }
            break;
        case 2:
            cout << "Cikarma turunu seciniz:" << endl;
            cout << "1- Araya eleman cikar" << endl;
            cout << "2- Sona eleman cikar" << endl;
            cout << "3- Liste islemlerine geri don" << endl;
            cout << "Seciminizi yapin: ";
            cin >> secim;

            switch (secim) {
            case 1:
                cout << "Aradan cikarilacak degeri girin: ";
                cin >> deger;
                liste.removeFromBeginning();
                break;
            case 2:
                cout << "Sondan cikarilacak degeri girin: ";
                cin >> deger;
                liste.removeFromEnd();
                break;
            case 3:
                cout << "Liste islemlerine geri donuluyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
            }
            break;
        case 3:
            liste.clear();
            break;
        case 4:
            cout << "Liste elemanlari:" << endl;
            liste.display();
            break;
        case 5:
            cout << "Listedeki eleman sayisi: " << liste.size() << endl;
            break;
        case 6:
            cout << "Liste islemlerinden cikiliyor... " << liste.size() << endl;
            break;
        default:
            cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }
    } while (secim != 6);
}

void IkiliAgacUygulamasi() {
    IkiliAgac agac;
    int secim, deger;

    do {
        std::cout << "\n\n----------Ikili Agac Uygulamasi----------\n";
        cout << "1- Agaca Eleman Ekle" << endl;
        cout << "2- Agactan Eleman sil" << endl;
        cout << "3- Agaci Temizle" << endl;
        cout << "4- Agactaki Eleman Sayisini goster" << endl;
        cout << "5- Agaci InOrder dolaşarak Elemanlari Goster" << endl;
        cout << "6- Agaci PreOrder dolaşarak Elemanlari Goster" << endl;
        cout << "7- Agaci PostOrder dolaşarak Elemanlari Goster" << endl;
        cout << "8- Ana menuye geri don" << endl;
        cout << "Seciminizi yapin: ";
        cin >> secim;

        switch (secim) {
        case 1:
            cout << "Eklemek istediginiz degeri girin: ";
            cin >> deger;
            agac.ekle(deger);
            break;
        case 2:
            cout << "Silmek istediginiz degeri girin: ";
            cin >> deger;
            agac.sil(deger);
            break;
        case 3:
            agac.temizle();
            cout << "Agac temizlendi." << endl;
            break;
        case 4:
            cout << "Agactaki eleman sayisi: " << agac.elemanSayisi() << endl;
            break;
        case 5:
            cout << "Agac'i InOrder Dolasarak Elemanlari Gösterme" << endl;
            agac.inorderDolas();
            cout << endl;
            break;
        case 6:
            cout << "Agac'i PreOrder Dolasarak Elemanlari Gösterme" << endl;
            agac.preorderDolas();
            cout << endl;
            break;
        case 7:
            cout << "Agac'i PostOrder Dolasarak Elemanlari Gösterme" << endl;
            agac.postorderDolas();
            cout << endl;
            break;
        case 8:
            cout << "Ana menuye don" << endl;
            break;
        default:
            cout << "Gecersiz secim yaptiniz" << endl;
        }
    } while (secim != 8);
}

