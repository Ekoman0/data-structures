#include "IkiliAgac.h"

// IkiliAgac sýnýfýnýn yapýcý fonksiyonu
IkiliAgac::IkiliAgac() : root(nullptr) {}

// IkiliAgac sýnýfýnýn yýkýcý fonksiyonu
IkiliAgac::~IkiliAgac() {
    temizle(); // Bellek sýzýntýsýný önlemek için temizleme iþlemi
}

// IkiliAgac'a eleman ekleme iþlemi
void IkiliAgac::ekle(int data) {
    ekleRecursive(root, data); // Özyinelemeli ekleme iþlemi
}

// IkiliAgac'tan eleman silme iþlemi
void IkiliAgac::sil(int data) {
    root = silRecursive(root, data); // Özyinelemeli silme iþlemi
}

// IkiliAgac'ý temizleme iþlemi
void IkiliAgac::temizle() {
    temizleRecursive(root); // Özyinelemeli temizleme iþlemi
    root = nullptr; // Kök düðümü sýfýrlama
}

// IkiliAgac'taki eleman sayýsýný hesaplama
int IkiliAgac::elemanSayisi() {
    return elemanSayisiRecursive(root); // Özyinelemeli eleman sayýsý hesaplama
}

// IkiliAgac'ý inorder sýrasýnda dolaþma iþlemi
void IkiliAgac::inorderDolas() {
    inorderDolasRecursive(root); // Özyinelemeli inorder dolaþma iþlemi
}

// IkiliAgac'ý preorder sýrasýnda dolaþma iþlemi
void IkiliAgac::preorderDolas() {
    preorderDolasRecursive(root); // Özyinelemeli preorder dolaþma iþlemi
}

// IkiliAgac'ý postorder sýrasýnda dolaþma iþlemi
void IkiliAgac::postorderDolas() {
    postorderDolasRecursive(root); // Özyinelemeli postorder dolaþma iþlemi
}

// IkiliAgac'a özyinelemeli olarak eleman ekleme iþlemi
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

// IkiliAgac'dan özyinelemeli olarak eleman silme iþlemi
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

// IkiliAgac'daki en küçük düðümü bulma iþlemi
TreeNode* IkiliAgac::enKucukDugum(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// IkiliAgac'ý özyinelemeli olarak temizleme iþlemi
void IkiliAgac::temizleRecursive(TreeNode* node) {
    if (node != nullptr) {
        temizleRecursive(node->left);
        temizleRecursive(node->right);
        delete node;
    }
}

// IkiliAgac'taki eleman sayýsýný özyinelemeli olarak hesaplama iþlemi
int IkiliAgac::elemanSayisiRecursive(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + elemanSayisiRecursive(node->left) + elemanSayisiRecursive(node->right);
}

// IkiliAgac'ý özyinelemeli olarak inorder sýrasýnda dolaþma iþlemi
void IkiliAgac::inorderDolasRecursive(TreeNode* node) {
    if (node != nullptr) {
        inorderDolasRecursive(node->left);
        std::cout << node->data << " ";
        inorderDolasRecursive(node->right);
    }
}

// IkiliAgac'ý özyinelemeli olarak preorder sýrasýnda dolaþma iþlemi
void IkiliAgac::preorderDolasRecursive(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorderDolasRecursive(node->left);
        preorderDolasRecursive(node->right);
    }
}

// IkiliAgac'ý özyinelemeli olarak postorder sýrasýnda dolaþma iþlemi
void IkiliAgac::postorderDolasRecursive(TreeNode* node) {
    if (node != nullptr) {
        postorderDolasRecursive(node->left);
        postorderDolasRecursive(node->right);
        std::cout << node->data << " ";
    }
}
