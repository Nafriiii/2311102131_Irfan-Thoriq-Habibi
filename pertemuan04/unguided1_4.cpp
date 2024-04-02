/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct node {
    string nama_131;
    string nim_131;
    node *next;
};

// Deklarasi variabel head dan tail
node *head;
node *tail;

// Inisialisasi linked list
void init_131() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool isempty() {
    return head == NULL;
}
// Menghitung jumlah node dalam linked list
int hitunglist_131() {
    int jumlah = 0;
    node *bantu = head;
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Menambah data mahasiswa di depan linked list
void insertdepan_131(string nama_131, string nim_131) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_131 = nama_131;
    baru->nim_131 = nim_131;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambah data mahasiswa di belakang linked list
void insertbelakang_131(string nama_131, string nim_131) {
    // Membuat node baru
    node *baru = new node;
    baru->nama_131 = nama_131;
    baru->nim_131 = nim_131;
    baru->next = NULL;

    // Jika linked list kosong
    if (isempty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Menambah data mahasiswa di tengah linked list
void inserttengah_131(string nama_131, string nim_131, int posisi_131) {
    if (posisi_131 < 1 || posisi_131 > hitunglist_131() + 1) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        if (posisi_131 == 1) {
            insertdepan_131(nama_131, nim_131);
        } else if (posisi_131 == hitunglist_131() + 1) {
            insertbelakang_131(nama_131, nim_131);
        } else {
            node *baru = new node;
            baru->nama_131 = nama_131;
            baru->nim_131 = nim_131;

            node *bantu = head;
            for (int i = 1; i < posisi_131 - 1; ++i) {
                bantu = bantu->next;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}

// Mengubah data mahasiswa di depan linked list
void ubahdepan_131(string nama_131, string nim_131) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = head->nama_131;
        string nim_sebelum = head->nim_131;

        // Mengubah data
        head->nama_131 = nama_131;
        head->nim_131 = nim_131;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_131 << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di belakang linked list
void ubahbelakang_131(string nama_131, string nim_131) {
    if (!isempty()) {
        // Menyimpan data sebelum diubah
        string nama_sebelum = tail->nama_131;
        string nim_sebelum = tail->nim_131;

        // Mengubah data
        tail->nama_131 = nama_131;
        tail->nim_131 = nim_131;

        // Menampilkan informasi
        cout << "Data telah diubah dari " << nama_sebelum << " menjadi " << nama_131 << endl;
    } else {
        cout << "Linked list masih kosong!" << endl;
    }
}

// Mengubah data mahasiswa di tengah linked list
void ubahtengah_131(string nama_131, string nim_131, int posisi_131) {
    if (posisi_131 < 1 || posisi_131 > hitunglist_131()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else {
        node *bantu = head;
        for (int i = 1; i < posisi_131; ++i) {
            bantu = bantu->next;
        }

        // Menyimpan data sebelum diubah
        string nama_sebelum = bantu->nama_131;
        string nim_sebelum = bantu->nim_131;

        // Mengubah data
        bantu->nama_131 = nama_131;
        bantu->nim_131 = nim_131;

        // Menampilkan informasi
        cout << "Data pada posisi " << posisi_131 << " telah diubah dari " << nama_sebelum << " menjadi " << nama_131 << endl;
    }
}
// Menghapus data mahasiswa di depan linked list
void hapusdepan_131() {
    if (!isempty()) {
        node *hapus = head;
        cout << "Data " << head->nama_131 << " berhasil dihapus dari depan" << endl;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di belakang linked list
void hapusbelakang_131() {
    if (!isempty()) {
        cout << "Data " << tail->nama_131 << " berhasil dihapus dari belakang" << endl;
        node *hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } else {
        cout << "Linked list kosong!" << endl;
    }
}

// Menghapus data mahasiswa di tengah linked list
void hapustengah_131(int posisi_131) {
    if (!isempty()) {
        if (posisi_131 < 1 || posisi_131 > hitunglist_131()) {
            cout << "Posisi diluar jangkauan" << endl;
        } else {
            if (posisi_131 == 1) {
                hapusdepan_131();
            } else if (posisi_131 == hitunglist_131()) {
                hapusbelakang_131();
            } else {
                node *hapus = head;
                for (int i = 1; i < posisi_131 - 1; ++i) {
                    hapus = hapus->next;
                }
                node *hapus_node = hapus->next;
                hapus->next = hapus_node->next;
                cout << "Data " << hapus_node->nama_131 << " berhasil dihapus dari posisi " << posisi_131 << endl;
                delete hapus_node;
            }
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
// Menghapus seluruh data di dalam linked list
void hapuslist_131() {
    while (!isempty()) {
        hapusdepan_131();
    }
    cout << "Linked list berhasil dihapus semua!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilkan_131() {
    if (!isempty()) {
        node *bantu = head;
        int nomor_131 = 1; // Variabel untuk nomor indeks atau nomor urut
        cout << setw(5) << left << "No" << setw(15) << left << "NAMA" << "NIM" << endl;
        while (bantu != NULL) {
            cout << setw(5) << left << nomor_131 << setw(15) << left << bantu->nama_131 << bantu->nim_131 << endl;
            bantu = bantu->next;
            nomor_131++; // Menginkremen nomor indeks atau nomor urut
        }
    } else {
        cout << "Linked list kosong!" << endl;
    }
}
int main() {
    init_131();
    int pilihan_131;
    string nama_131;
    string nim_131;
    int posisi_131;

    do {
        // Menampilkan menu yang terdiri dari tambah (depan,belakang,tengah),ubah (depan,belakang,tengah),hapus (depan,nelakang,tengah,list)dan,tampilkan semua list.
        cout << "=============================================================================="<<endl;
        cout << "=                 Menu Linked List Non-Circular Mahasiswa                    ="<<endl;
        cout << "=============================================================================="<<endl;
        cout <<endl;
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Keluar" << endl;
        cout << "================"<<endl;
        cout << "Opsi Pilihan :";cin >> pilihan_131;
        cout << "================"<<endl;
        cout <<endl;

        switch (pilihan_131) {
            //merupakan menu 1 yang berfungsi untuk menginputkan nama dan nim ke depan data linked list
            case 1:
                cout << "======================================="<<endl;
                cout << "=            Tambah Depan             ="<<endl;
                cout << "======================================="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_131;
                cout << "Masukkan NIM :";
                cin >> nim_131;
                cout<<endl;
                cout << "Data "<<nama_131<<" telah ditambahkan"<<endl;
                cout << endl;
                insertdepan_131(nama_131, nim_131);
                break;
                //merupakan menu 2 yang berfungsi untuk menginputkan nama dan nim ke bagian belakang dari data linked list
            case 2:
                cout << "======================================="<<endl;
                cout << "=           Tambah Belakang           ="<<endl;
                cout << "======================================="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_131;
                cout << "Masukkan NIM :";
                cin >> nim_131;
                cout<<endl;
                cout << "Data "<<nama_131<<" telah ditambahkan"<<endl;
                cout << endl;
                insertbelakang_131(nama_131, nim_131);
                break;
                //merupakan menu 3 yang berfungsi untuk menginputkan nama dan nim ke bagian tengah ataupun posisi manapun yang diinginkan oleh user dari data linked list
            case 3:
                cout << "======================================="<<endl;
                cout << "=            Tambah Tengah            ="<<endl;
                cout << "======================================="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_131;
                cout << "Masukkan NIM :";
                cin >> nim_131;
                cout << "Masukkan Posisi :";
                cin >> posisi_131;
                cout<<endl;
                cout << "Data "<<nama_131<<" telah ditambahkan"<<endl;
                cout << endl;
                inserttengah_131(nama_131, nim_131, posisi_131);
                break;
                //merupakan menu 4 yang berfungsi untuk mengubah data di posisi belakang pada linked list 
            case 4:
                cout << "====================================="<<endl;
                cout << "=            Ubah Depan             ="<<endl;
                cout << "====================================="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_131;
                cout << "Masukkan NIM :";
                cin >> nim_131;
                cout << endl;
                ubahdepan_131(nama_131, nim_131);
                break;
                //merupakan menu 5 yang berfungsi untuk mengubah data di posisi belakang pada linked list 
            case 5:
                cout << "====================================="<<endl;
                cout << "=           Ubah Belakang           ="<<endl;
                cout << "====================================="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_131;
                cout << "Masukkan NIM :";
                cin >> nim_131;
                cout << endl;
                ubahbelakang_131(nama_131, nim_131);
                break;
                //merupakan menu 6 yang berfungsi untuk mengubah data di posisi tengah atau posisi manapun yang diinginkan oleh user pada linked list 
            case 6:
                cout << "====================================="<<endl;
                cout << "=            Ubah Tengah            ="<<endl;
                cout << "====================================="<<endl;
                cout << "Masukkan Nama :";
                cin >> nama_131;
                cout << "Masukkan NIM :";
                cin >> nim_131;
                cout << "Masukkan Posisi :";
                cin >> posisi_131;
                cout << endl;
                ubahtengah_131(nama_131, nim_131, posisi_131);
                break;
                //merupakan menu 5 yang berfungsi untuk menghapus data di posisi depan pada linked list 
            case 7:
                cout << "======================================="<<endl;
                cout << "=            Hapus Depan              ="<<endl;
                cout << "======================================="<<endl;
                cout <<endl;
                hapusdepan_131();
                break;
                //merupakan menu 5 yang berfungsi untuk menghapus data di posisi belakang pada linked list 
            case 8:
                cout << "======================================="<<endl;
                cout << "=          Hapus Belakang             ="<<endl;
                cout << "======================================="<<endl;
                cout <<endl;
                hapusbelakang_131();
                break;
                //merupakan menu 5 yang berfungsi untuk menghapus data di posisi tengah atau posisi manapun yang diinginkan user pada linked list 
            case 9:
                cout << "======================================="<<endl;
                cout << "=            Hapus Tengah             ="<<endl;
                cout << "======================================="<<endl;
                cout <<"Posisi :";
                cin >>posisi_131;
                cout <<endl;
                hapustengah_131(posisi_131);
                break;
                //merupakan menu 10 yang memiliki fungsi untuk menghapus seluruh data yang berada didalam list yang telah diinputkan oleh user
            case 10:
                cout << "====================================="<<endl;
                cout << "=            Hapus List             ="<<endl;
                cout << "====================================="<<endl;
                hapuslist_131();
                break;
                //merupakan menu 11 yang memiliki fungsi untuk menampilkan seluruh data yang telah di tambahkan oleh user
            case 11:
                cout << "=============================================================================="<<endl;
                cout << "                        Menampilkan Semua data mahasiswa                     ="<<endl;
                cout << "=============================================================================="<<endl;
                cout << "======================================="<<endl;
                cout << "=           Data Mahasiswa            ="<<endl;
                cout << "======================================="<<endl;
                tampilkan_131();
                break;
                //merupakan menu 0 yang berfungsi untuk menutup atau menghentikan program
            case 0:
                cout << "============================================="<<endl;
                cout << "=            Keluar Dari Program            ="<<endl;
                cout << "============================================="<<endl;
                break;
                //merupakan fungsi apabila user menginputkan angka selain yang ada di menu
            default:
                cout << "=============================================="<<endl;
                cout << "=            Pilihan Tidak Valid             ="<<endl;
                cout << "=============================================="<<endl;
        }
    } while (pilihan_131 != 0);

    return 0;
}
