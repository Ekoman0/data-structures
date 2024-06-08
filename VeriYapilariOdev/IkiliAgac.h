#ifndef IKILIAGAC_H
#define IKILIAGAC_H

#include <iostream>

// TreeNode sýnýfý, ikili aðaç düðümünü temsil eder
class TreeNode {
public:
    int data; // Düðümün veri deðeri
    TreeNode* left; // Sol alt aðacýn kök düðümü
    TreeNode* right; // Sað alt aðacýn kök düðümü

    // Yapýcý fonksiyon, yeni bir düðüm oluþturur
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// IkiliAgac sýnýfý, ikili aðaç yapýsýný temsil eder
class IkiliAgac {
private:
    TreeNode* root; // Kök düðüm

    // Özyinelemeli olarak düðüm eklemeyi gerçekleþtirir
    void ekleRecursive(TreeNode*& node, int data);

    // Verilen düðüm altýnda en küçük düðümü bulur
    TreeNode* enKucukDugum(TreeNode* node);

    // Özyinelemeli olarak düðüm silmeyi gerçekleþtirir
    TreeNode* silRecursive(TreeNode*& node, int data);

    // Özyinelemeli olarak aðacý temizlemeyi gerçekleþtirir
    void temizleRecursive(TreeNode* node);

    // Özyinelemeli olarak aðaçtaki eleman sayýsýný hesaplar
    int elemanSayisiRecursive(TreeNode* node);

    // Özyinelemeli olarak aðacý inorder sýrasýnda dolaþýr ve ekrana yazdýrýr
    void inorderDolasRecursive(TreeNode* node);

    // Özyinelemeli olarak aðacý preorder sýrasýnda dolaþýr ve ekrana yazdýrýr
    void preorderDolasRecursive(TreeNode* node);

    // Özyinelemeli olarak aðacý postorder sýrasýnda dolaþýr ve ekrana yazdýrýr
    void postorderDolasRecursive(TreeNode* node);

public:
    // Yapýcý fonksiyon, boþ bir aðaç oluþturur
    IkiliAgac();

    // Yýkýcý fonksiyon, aðacý temizler
    ~IkiliAgac();

    // Yeni bir veriyi aðaca ekler
    void ekle(int data);

    // Belirtilen veriyi aðaçtan siler
    void sil(int data);

    // Aðacý temizler
    void temizle();

    // Aðaçtaki eleman sayýsýný döndürür
    int elemanSayisi();

    // Aðacý inorder sýrasýnda dolaþýr ve ekrana yazdýrýr
    void inorderDolas();

    // Aðacý preorder sýrasýnda dolaþýr ve ekrana yazdýrýr
    void preorderDolas();

    // Aðacý postorder sýrasýnda dolaþýr ve ekrana yazdýrýr
    void postorderDolas();
};

#endif

