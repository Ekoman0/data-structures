#ifndef IKILIAGAC_H
#define IKILIAGAC_H

#include <iostream>

// TreeNode s�n�f�, ikili a�a� d���m�n� temsil eder
class TreeNode {
public:
    int data; // D���m�n veri de�eri
    TreeNode* left; // Sol alt a�ac�n k�k d���m�
    TreeNode* right; // Sa� alt a�ac�n k�k d���m�

    // Yap�c� fonksiyon, yeni bir d���m olu�turur
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

// IkiliAgac s�n�f�, ikili a�a� yap�s�n� temsil eder
class IkiliAgac {
private:
    TreeNode* root; // K�k d���m

    // �zyinelemeli olarak d���m eklemeyi ger�ekle�tirir
    void ekleRecursive(TreeNode*& node, int data);

    // Verilen d���m alt�nda en k���k d���m� bulur
    TreeNode* enKucukDugum(TreeNode* node);

    // �zyinelemeli olarak d���m silmeyi ger�ekle�tirir
    TreeNode* silRecursive(TreeNode*& node, int data);

    // �zyinelemeli olarak a�ac� temizlemeyi ger�ekle�tirir
    void temizleRecursive(TreeNode* node);

    // �zyinelemeli olarak a�a�taki eleman say�s�n� hesaplar
    int elemanSayisiRecursive(TreeNode* node);

    // �zyinelemeli olarak a�ac� inorder s�ras�nda dola��r ve ekrana yazd�r�r
    void inorderDolasRecursive(TreeNode* node);

    // �zyinelemeli olarak a�ac� preorder s�ras�nda dola��r ve ekrana yazd�r�r
    void preorderDolasRecursive(TreeNode* node);

    // �zyinelemeli olarak a�ac� postorder s�ras�nda dola��r ve ekrana yazd�r�r
    void postorderDolasRecursive(TreeNode* node);

public:
    // Yap�c� fonksiyon, bo� bir a�a� olu�turur
    IkiliAgac();

    // Y�k�c� fonksiyon, a�ac� temizler
    ~IkiliAgac();

    // Yeni bir veriyi a�aca ekler
    void ekle(int data);

    // Belirtilen veriyi a�a�tan siler
    void sil(int data);

    // A�ac� temizler
    void temizle();

    // A�a�taki eleman say�s�n� d�nd�r�r
    int elemanSayisi();

    // A�ac� inorder s�ras�nda dola��r ve ekrana yazd�r�r
    void inorderDolas();

    // A�ac� preorder s�ras�nda dola��r ve ekrana yazd�r�r
    void preorderDolas();

    // A�ac� postorder s�ras�nda dola��r ve ekrana yazd�r�r
    void postorderDolas();
};

#endif

