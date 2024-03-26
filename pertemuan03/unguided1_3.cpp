#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node{
    string nama_131;
    int usia_131;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init_131() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool itsEmpty(){
    return head == NULL;
}

// Menghitung jumlah Node dalam linked list
int hitungListnode(){
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Menambahkan node di depan
void inputdepan_131(string nama,int usia){
    // membuat Node baru
    Node *baru = new Node;
    baru->nama_131 = nama;
    baru->usia_131 = usia;
    baru->next = NULL;
    if (itsEmpty()){
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambahkan node di tengah
void inputtengah_131(string nama, int usia, int posisi) {
    if (posisi < 1 || posisi > hitungListnode() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        inputdepan_131(nama, usia);
    } else {
        Node* baru = new Node();
        baru->nama_131 = nama;
        baru->usia_131 = usia;
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Menambahkan node di belakang
void inputbelakang_131(string nama, int usia) {
    // membuat Node baru
    Node* baru = new Node;
    baru->nama_131 = nama;
    baru->usia_131 = usia;
    baru->next = NULL;

    if (itsEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// fungsi menghapus Node di depan
void hapusDepan_131(){
    if (!itsEmpty()) {
        Node *hapus = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete hapus;
    } else {
        cout << "Tidak ada list yang tersedia" << endl;
    }
}

// fungsi menghapus Node di tengah
void hapusTengah_131(int posisi)
{
    if (posisi < 1 || posisi > hitungListnode()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        hapusDepan_131();
    } else {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

//fungsi menghapus Node di belakang
void hapusBelakang_131(){
    if (!itsEmpty()) {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = NULL;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// fungsi untuk mengupdate Node di tengah
void ubahTengah_131(string nama, int usia, int posisi){
    if (posisi < 1 || posisi > hitungListnode()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi) {
            bantu = bantu->next;
            nomor++;
        }
        bantu->nama_131 = nama;
        bantu->usia_131 = usia;
    }
}

// fungsi untuk mengupdate Node di belakang
void ubahBelakang_131(string nama,int usia){
    if (!itsEmpty()) {
        tail->nama_131 = nama;
        tail->usia_131 = usia;
    } else {
        cout << "Tidak ada list yang tersedia" << endl;
    }
}

// Hapus semua Node dalam linked list
void hapusList_131(){
    Node *bantu = head;
    while (bantu != NULL){
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan semua Node dalam linked list
void Tampilan_131() {
    Node *bantu = head;
    cout << left << setw(10) << "Nama" << right << setw(2) << "Usia" << endl;
    if (!itsEmpty()) {
        while (bantu != NULL) {
            cout << left << setw(10) << bantu->nama_131 << right << setw(2) << bantu->usia_131 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "Tidak ada data yang tersedia!" << endl;
            }
}

int main()
{
    init_131();
    cout << "Selamat datang di program single linked list" << endl;

    // Menambahkan data awal

    inputdepan_131("Karin", 18);
    inputdepan_131("Hoshino", 18);
    inputdepan_131("Akechi", 20);
    inputdepan_131("Yusuke", 19);
    inputdepan_131("Michael", 18);
    inputdepan_131("Jane", 20);
    inputdepan_131("John", 19);

    int pilih_131;
    do {
        // Menu utama program
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Seluruh Data" << endl;
        cout << "6. Tampilkan Data" << endl;
        cout << "7. Exit" << endl;
        cout << "Masukkan pilihanmu: ";
        cin >> pilih_131;

        switch (pilih_131) {
            case 1: {
                string nama_131;
                int usia_131;
                cout << "Masukkan nama: ";
                cin >> nama_131;
                cout << "Masukkan usia: ";
                cin >> usia_131;
                inputdepan_131(nama_131, usia_131);
                break;
            }
           case 2: {
                string namaHapus_131;
                cout << "Masukkan nama data yang ingin dihapus: ";
                cin >> namaHapus_131;
                Node* temp = head;
                 int posisi = 1;
                while (temp != NULL && temp->nama_131 != namaHapus_131) {
                temp = temp->next;
                posisi++;
             }
                if (temp != NULL) {
                hapusTengah_131(posisi);
                cout << "Data dengan nama " << namaHapus_131 << " berhasil dihapus." << endl;
    } else {
        cout << "Data dengan nama " << namaHapus_131 << " tidak ditemukan." << endl;
    }
    break;
}
            case 3: {
                string namaLama_131, namaBaru_131;
                int usiaBaru_131;
                cout << "Masukkan nama yang ingin diupdate: ";
                cin >> namaLama_131;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru_131;
                cout << "Masukkan usia baru: ";
                cin >> usiaBaru_131;
                Node* temp = head;
                int posisi = 1;
                while (temp != NULL && temp->nama_131 != namaLama_131) {
                    temp = temp->next;
                    posisi++;
                }
                if (temp != NULL) {
                    ubahTengah_131(namaBaru_131, usiaBaru_131, posisi);
                } else {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string nama_131, namabaru_131;
                int usia_131;
                cout << "Masukkan nama: ";
                cin >> nama_131;
                cout << "Masukkan usia: ";
                cin >> usia_131;
                cout << "Masukkan nama setelah data baru: ";
                cin >> namabaru_131;
                Node* temp = head;
                int posisi = 1;
                while (temp != NULL && temp->nama_131 != namabaru_131) {
                    temp = temp->next;
                    posisi++;
                }
                if (temp != NULL) {
                    inputtengah_131(nama_131, usia_131, posisi + 1);
                } else {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 5: {
                hapusList_131();
                break;
            }
            case 6: {
                Tampilan_131();
                break;
            }
            case 7: {
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
    } while (pilih_131!= 7);

    return 0;
}
