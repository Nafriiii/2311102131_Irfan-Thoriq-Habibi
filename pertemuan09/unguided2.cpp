/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Pohon{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi tree(pohon)
void init_131(){
    root = NULL;
}
// Cek apakah tree kosong
bool isEmpty_131(){
    return root == NULL;
}
// Buat node root(akar)
void buatNode_131(char data){
    if (isEmpty_131()){
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root." << endl;
    }else{
        cout << "\n Tree telah tersedia!" << endl;
    }
}
// Tambah node child di sebelah kiri
Pohon *insertLeft_131(char data, Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }else{
        if (node->left != NULL){
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }else{
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child  bagian kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Tambah node child di sebelah kanan
Pohon *insertRight_131(char data, Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }else{
        if (node->right != NULL){
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }else{
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child bagian kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Update nilai pada node
void update_131(char data, Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (!node){
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }else{
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
// Ambil nilai dari sebuah node
void retrieve_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (!node){
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }else{
            cout << "\n Data node: " << node->data << endl;
        }
    }
}
// Temukan dan tampilkan informasi sebuah node
void find_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (!node){
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }else{
            cout << "\n Data Node: " << node->data << endl;
            cout << " Root: " << root->data << endl;

            if (!node->parent)
                cout << " Parent: (tidak punya parent)" << endl;
            else
                cout << " Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling: " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling: " << node->parent->right->data << endl;
            else
                cout << " Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri: (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan: (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan: " << node->right->data << endl;
        }
    }
}
// PreOrder traversal
void preOrder_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (node != NULL){
            cout << " " << node->data << ", ";
            preOrder_131(node->left);
            preOrder_131(node->right);
        }
    }
}
// InOrder traversal
void inOrder_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (node != NULL){
            inOrder_131(node->left);
            cout << " " << node->data << ", ";
            inOrder_131(node->right);
        }
    }
}
// PostOrder traversal
void postOrder_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (node != NULL){
            postOrder_131(node->left);
            postOrder_131(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus tree(pohon) dan semua nodenya
void deleteTree_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if (node != NULL){
            if (node != root){
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree_131(node->left);
            deleteTree_131(node->right);
            if (node == root){
                delete root;
                root = NULL;
            }else{
                delete node;
            }
        }
    }
}
// Hapus subtree dari sebuah node
void deleteSub_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        deleteTree_131(node->left);
        deleteTree_131(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus seluruh pohon
void clear(){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        deleteTree_131(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Menghitung jumlah node dalam pohon
int size(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }else{
        if (!node){
            return 0;
        }else{
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Menghitung tinggi pohon
int height(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }else{
        if (!node){
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
// Menampilkan karakteristik dari pohon
void characteristic_131(){
    cout << "\n ukuran pohon: " << size(root) << endl;
    cout << " tinggi pohon: " << height(root) << endl;
    cout << " Rata-rata node pohon: " << size(root) / height(root) << endl;
}
// Menampilkan child node
void displayChildren_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else if (!node){
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }else{
        if (node->left)
            cout << " Child Kiri: " << node->left->data << endl;
        else
            cout << " Child Kiri: (tidak punya Child kiri)" << endl;
        if (node->right)
            cout << " Child Kanan: " << node->right->data << endl;
        else
            cout << " Child Kanan: (tidak punya Child kanan)" << endl;
    }
}

// Menampilkan turunan(descendant) dari sebuah node
void displayDescendants_131(Pohon *node){
    if (isEmpty_131()){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else if (!node){
        cout << "\n Node yang ditunjuk tidak ada!" << endl;
    }else{
        cout << " Keturunan dari " << node->data << ": ";
        preOrder_131(node);
        cout << endl;
    }
}
// Mencari dan mengembalikan node dengan nilai tertentu
Pohon *findNode(Pohon *node, char data){
    if (node == NULL)
        return NULL;
    if (node->data == data)
        return node;

    Pohon *leftNode = findNode(node->left, data);
    if (leftNode != NULL)
        return leftNode;

    return findNode(node->right, data);
}

int main(){
    init_131();
    int pilih_131;
    char data_131;
    Pohon *node = nullptr;
    do{
        cout << "Menu:"<<endl;
        cout << "1. Buat Pohon"<<endl;
        cout << "2. Tambah kanan"<<endl;
        cout << "3. Tambah kiri"<<endl;
        cout << "4. Perbarui Node"<<endl;
        cout << "5. mengambil Node"<<endl;
        cout << "6. Temukan Node"<<endl;
        cout << "7. Karakteristik"<<endl;
        cout << "8. PreOrder Traversal"<<endl;;
        cout << "9. InOrder Traversal"<<endl;
        cout << "10. PostOrder Traversal"<<endl;
        cout << "11. Tampilkan node(child)"<<endl;
        cout << "12. Tampilkan descendant"<<endl;
        cout << "13. Hapus pohon"<<endl;
        cout << "14. keluar"<<endl;
        cout << "Masukkan pilihan : ";
        cin >> pilih_131;
        switch (pilih_131){
        case 1:
            cout << "Masukkan root: ";
            cin >> data_131;
            buatNode_131(data_131);
            break;
        case 2:
            cout << "Masukkan data node baru: ";
            cin >> data_131;
            cout << "Masukkan data parent baru: ";
            char parentDataRight;
            cin >> parentDataRight;
            node = findNode(root, parentDataRight);
            if (node != nullptr)
                insertRight_131(data_131, node);
            break;
        case 3:
            cout << "Masukkan data node baru: ";
            cin >> data_131;
            cout << "Masukkan data parent baru: ";
            char parentDataLeft;
            cin >> parentDataLeft;
            node = findNode(root, parentDataLeft);
            if (node != nullptr)
                insertLeft_131(data_131, node);
            break;
        case 4:
            cout << "Masukan data yang ingin diubah: ";
            cin >> data_131;
            cout << "Masukkan node baru: ";
            char newData;
            cin >> newData;
            node = findNode(root, data_131);
            if (node != nullptr)
                update_131(newData, node);
            break;
        case 5:
            cout << "Masukan data yang akan diambil: ";
            cin >> data_131;
            node = findNode(root, data_131);
            retrieve_131(node);
            break;
        case 6:
            cout << "Masukkan data yang akan ditemukan: ";
            cin >> data_131;
            node = findNode(root, data_131);
            find_131(node);
            break;
        case 7:
            characteristic_131();
            break;
        case 8:
            cout << "PreOrder Traversal: ";
            preOrder_131(root);
            cout << endl;
            break;
        case 9:
            cout << "InOrder Traversal: ";
            inOrder_131(root);
            cout << endl;
            break;
        case 10:
            cout << "PostOrder Traversal: ";
            postOrder_131(root);
            cout << endl;
            break;
        case 11:
            cout << "Masukkan data untuk menampilkan node(child): ";
            cin >> data_131;
            node = findNode(root, data_131);
            displayChildren_131(node);
            break;
        case 12:
            cout << "Masukkan data untuk menampilkan descendant: ";
            cin >> data_131;
            node = findNode(root, data_131);
            displayDescendants_131(node);
            break;
        case 13:
            clear();
            break;
        case 14:
            cout << "Keluar program" << endl;
            break;
        default:
            cout << "pilihan tidak tersedia" << endl;
        }
    } while (pilih_131 != 14);

    return 0;
}