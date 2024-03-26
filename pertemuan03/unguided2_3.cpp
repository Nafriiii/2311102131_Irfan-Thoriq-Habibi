/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi kelas Node untuk memperlihatkan simpul dalam linked list
class Node {
public:
    string nama_131;
    double harga_131;
    Node* prev;
    Node* next;
};

// Deklarasi kelas DoublyLinkedList untuk menggunakan double linked list
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // inisialisasi linked list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // fungsi untuk menambahkan simpul baru di awal linked list
    void push(string nama_131, double harga_131) {
        Node* newNode = new Node;
        newNode->nama_131 = nama_131;
        newNode->harga_131 = harga_131;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    // fungsi untuk menghapus simpul dari awal linked list
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    // fungsi untuk memperbarui data produk berdasarkan nama produk yang lama
    bool update(string oldNama_131, string newNama_131, double newHarga_131) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_131 == oldNama_131) {
                current->nama_131 = newNama_131;
                current->harga_131 = newHarga_131;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // fungsi untuk menghapus semua simpul dalam linked list
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // fungsi untuk menampilkan semua data produk dalam linked list
    void display() {
    Node* current = head;
    cout << left << setw(20) << "Nama Produk" << setw(10) << "Harga (Rp)" << endl;
    while (current != nullptr) {
        cout << left << setw(20) << current->nama_131 << setw(10) << current->harga_131 << endl;
        current = current->next;
    }
    cout << endl;
}

    // fungsi untuk menyisipkan simpul baru setelah simpul tertentu
    void insertAfter(string namaProduk_131, double hargaProduk_131, string namaBaruProduk_131) {
        Node* newNode = new Node;
        newNode->nama_131 = namaProduk_131;
        newNode->harga_131 = hargaProduk_131;

        Node* current = head;
        while (current != nullptr && current->nama_131 != namaBaruProduk_131 ){
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Produk " << namaBaruProduk_131 << " tidak tersedia" << endl;
            return;
        }
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    // fungsi untuk menghapus simpul dengan nama produk tertentu
    void deleteNode(string namaProduk_131) {
        Node* current = head;
        while (current != nullptr && current->nama_131 != namaProduk_131) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Produk " << namaProduk_131 << " tidak tersedia" << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }
};

int main() {
    DoublyLinkedList list;

    // Menambahkan data saat program dimulai
    list.push("Hanasui", 30000);
    list.push("Wardah", 50000);
    list.push("Skintific", 100000);
    list.push("Somethinc", 150000);
    list.push("Originote", 60000);

    while (true) {
        //menu utama program ini
        cout << "Toko Skincare Purwokerto"<<endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        //memiihih menu sesuai dengan yang diinginkan user
        int pilih_131;
        cout << "masukkan pilihanmu: ";
        cin >> pilih_131;
        switch (pilih_131) {
            //menambahkan data didalam double linked list
            case 1: {
                string nama_131;
                double harga_131;
                cout << "Masukkan nama produk: ";
                cin >> nama_131;
                cout << "Masukkan harga produk: ";
                cin >> harga_131;
                list.push(nama_131, harga_131);
                break;
            }
            //menghapus data didalam double linked list
            case 2: {
                string nama_131;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> nama_131;
                list.deleteNode(nama_131);
                break;
            }
            //mengupdate data didalam linked list
            case 3: {
                string oldNama_131, newNama_131;
                double newHarga_131;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> oldNama_131;
                cout << "Masukkan nama produk baru: ";
                cin >> newNama_131;
                cout << "Masukkan harga produk baru: ";
                cin >> newHarga_131;
                bool updated = list.update(oldNama_131, newNama_131, newHarga_131);
                if (!updated) {
                    cout << "Data tidak tersedia" << endl;
                }
                break;
            }
            //menambahkan data dengan urutan yang diinginkan user
            case 4: {
                string namaProduk_131, namaBaruProduk_131;
                double hargaProduk_131;
                cout << "Masukkan nama produk baru: ";
                cin >> namaProduk_131;
                cout << "Masukkan harga produk baru: ";
                cin >> hargaProduk_131;
                cout << "Masukkan nama produk setelah produk yang ingin ditambahkan: ";
                cin >> namaBaruProduk_131;
                list.insertAfter(namaProduk_131, hargaProduk_131, namaBaruProduk_131);
                break;
            }
            //menghapus data dengan urutan yang diinginkan user
            case 5: {
                string namaProduk_131;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk_131;
                list.deleteNode(namaProduk_131);
                break;
            }
            //menghapus semua data yang ada didalam double linked list
            case 6: {
                list.deleteAll();
                break;
            }
            //menampilkan seluruh data yang ada didalam double linked list
            case 7: {
                list.display();
                break;
            }
            //keluar dari program double linked list
            case 8: {
                return 0;
            }
            //jika user salah menginputkan pilihan maka akan menampilkan pesan berikut
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    }

    return 0;
}
