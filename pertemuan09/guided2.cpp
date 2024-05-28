#include <iostream>
#include <iomanip>
using namespace std;
struct Pohon{
    char data;
    Pohon *left, *right, *parent;
    };
Pohon *root, *baru;
void init(){
    root = NULL;
}
bool isEmpty(){
    return root == NULL;
}
void buatNode(char data){
    if (isEmpty()){
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root."<< endl;
    }
    else{
        cout << "\n Tree sudah ada!" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }else{
        if (node->left != NULL){
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl; 
                return NULL;
        }else{
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl; 
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }else{
        if (node->right != NULL){
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl; 
                return NULL;
        }else{
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl; 
            return baru;
        }
    }
}
void update(char data, Pohon *node){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (!node){
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else{
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "<< data << endl;
        }
    }
}
void retrieve(Pohon *node){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (!node){
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }else{
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
void find(Pohon *node){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (!node){
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }else{
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;

            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else{
        if (node != NULL){
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (node != NULL){
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node = root){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else{
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (node != NULL){
            if (node != root){
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root){
                delete root;
                root = NULL;
            }
            else{
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl; 
    }
}
// Hapus Tree
void clear(){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }else{
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }else{
        if (!node) {
            return 0;
        }else{
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root){
    if (isEmpty()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }else{
        if (!node)
        {
            return 0;
        }else{
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan){
                return heightKiri + 1;
            }else{
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic(){
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

int main() {
    init();
    int pilihan;

    do {
        cout << "Menu: " << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Ubah Data Node" << endl;
        cout << "5. Tampilkan Data Node" << endl;
        cout << "6. Cari Node" << endl;
        cout << "7. Karakteristik Pohon" << endl;
        cout << "8. Penelusuran PreOrder" << endl;
        cout << "9. Penelusuran InOrder" << endl;
        cout << "10. Penelusuran PostOrder" << endl;
        cout << "11. Hapus SubTree" << endl;
        cout << "12. Hapus Tree" << endl;
        cout << "13. Keluar" << endl;
        cout << "Pilih menu (1-13): ";
        
        cin >> pilihan;

        char data;
        Pohon *node;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data untuk node root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data untuk node kiri: ";
                cin >> data;
                insertLeft(data, root);
                break;
            case 3:
                cout << "Masukkan data untuk node kanan: ";
                cin >> data;
                insertRight(data, root);
                break;
            case 4:
                cout << "Masukkan data baru untuk node: ";
                cin >> data;
                cout << "Masukkan data node yang ingin diubah: ";
                cin >> data;
                update(data, node);
                break;
            case 5:
                cout << "Masukkan data node yang ingin ditampilkan: ";
                cin >> data;
                retrieve(node);
                break;
            case 6:
                cout << "Masukkan data node yang ingin dicari: ";
                cin >> data;
                find(node);
                break;
            case 7:
                characteristic();
                break;
            case 8:
                cout << "Penelusuran PreOrder: ";
                preOrder(root);
                cout << endl;
                break;
            case 9:
                cout << "Penelusuran InOrder: ";
                inOrder(root);
                cout << endl;
                break;
            case 10:
                cout << "Penelusuran PostOrder: ";
                postOrder(root);
                cout << endl;
                break;
            case 11:
                cout << "Masukkan data node yang ingin dihapus: ";
                cin >> data;
                deleteSub(node);
                break;
            case 12:
                clear();
                break;
            case 13:
                cout << "Terima kasih! Keluar dari program." << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 13);

    return 0;
}