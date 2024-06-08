#include "IkiliAgac.h"

// IkiliAgac s�n�f�n�n yap�c� fonksiyonu
IkiliAgac::IkiliAgac() : root(nullptr) {}

// IkiliAgac s�n�f�n�n y�k�c� fonksiyonu
IkiliAgac::~IkiliAgac() {
    temizle(); // Bellek s�z�nt�s�n� �nlemek i�in temizleme i�lemi
}

// IkiliAgac'a eleman ekleme i�lemi
void IkiliAgac::ekle(int data) {
    ekleRecursive(root, data); // �zyinelemeli ekleme i�lemi
}

// IkiliAgac'tan eleman silme i�lemi
void IkiliAgac::sil(int data) {
    root = silRecursive(root, data); // �zyinelemeli silme i�lemi
}

// IkiliAgac'� temizleme i�lemi
void IkiliAgac::temizle() {
    temizleRecursive(root); // �zyinelemeli temizleme i�lemi
    root = nullptr; // K�k d���m� s�f�rlama
}

// IkiliAgac'taki eleman say�s�n� hesaplama
int IkiliAgac::elemanSayisi() {
    return elemanSayisiRecursive(root); // �zyinelemeli eleman say�s� hesaplama
}

// IkiliAgac'� inorder s�ras�nda dola�ma i�lemi
void IkiliAgac::inorderDolas() {
    inorderDolasRecursive(root); // �zyinelemeli inorder dola�ma i�lemi
}

// IkiliAgac'� preorder s�ras�nda dola�ma i�lemi
void IkiliAgac::preorderDolas() {
    preorderDolasRecursive(root); // �zyinelemeli preorder dola�ma i�lemi
}

// IkiliAgac'� postorder s�ras�nda dola�ma i�lemi
void IkiliAgac::postorderDolas() {
    postorderDolasRecursive(root); // �zyinelemeli postorder dola�ma i�lemi
}

// IkiliAgac'a �zyinelemeli olarak eleman ekleme i�lemi
void IkiliAgac::ekleRecursive(TreeNode*& node, int data) {
    if (node == nullptr) {
        node = new TreeNode(data);
    }
    else if (data < node->data) {
        ekleRecursive(node->left, data);
    }
    else if (data > node->data) {
        ekleRecursive(node->right, data);
    }
}

// IkiliAgac'dan �zyinelemeli olarak eleman silme i�lemi
TreeNode* IkiliAgac::silRecursive(TreeNode*& node, int data) {
    if (node == nullptr) {
        return nullptr;
    }
    if (data < node->data) {
        node->left = silRecursive(node->left, data);
    }
    else if (data > node->data) {
        node->right = silRecursive(node->right, data);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        else {
            TreeNode* temp = enKucukDugum(node->right);
            node->data = temp->data;
            node->right = silRecursive(node->right, temp->data);
        }
    }
    return node;
}

// IkiliAgac'daki en k���k d���m� bulma i�lemi
TreeNode* IkiliAgac::enKucukDugum(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// IkiliAgac'� �zyinelemeli olarak temizleme i�lemi
void IkiliAgac::temizleRecursive(TreeNode* node) {
    if (node != nullptr) {
        temizleRecursive(node->left);
        temizleRecursive(node->right);
        delete node;
    }
}

// IkiliAgac'taki eleman say�s�n� �zyinelemeli olarak hesaplama i�lemi
int IkiliAgac::elemanSayisiRecursive(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + elemanSayisiRecursive(node->left) + elemanSayisiRecursive(node->right);
}

// IkiliAgac'� �zyinelemeli olarak inorder s�ras�nda dola�ma i�lemi
void IkiliAgac::inorderDolasRecursive(TreeNode* node) {
    if (node != nullptr) {
        inorderDolasRecursive(node->left);
        std::cout << node->data << " ";
        inorderDolasRecursive(node->right);
    }
}

// IkiliAgac'� �zyinelemeli olarak preorder s�ras�nda dola�ma i�lemi
void IkiliAgac::preorderDolasRecursive(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorderDolasRecursive(node->left);
        preorderDolasRecursive(node->right);
    }
}

// IkiliAgac'� �zyinelemeli olarak postorder s�ras�nda dola�ma i�lemi
void IkiliAgac::postorderDolasRecursive(TreeNode* node) {
    if (node != nullptr) {
        postorderDolasRecursive(node->left);
        postorderDolasRecursive(node->right);
        std::cout << node->data << " ";
    }
}
