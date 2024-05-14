/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
#include <iomanip> 

using namespace std;

// Deklarasi struct node
struct node {
    string NamaMahasiswa_131;
    string NIM_131;
    node *next;
};

node *front;
node *back;

// Prosedur inisialisasi node front dan back sebagai NULL
void Inisialisasi_131() {
    front = NULL;
    back = NULL;
}

// Fungsi untuk mengecek apakah queue kosong atau tidak
bool isEmpty_131() {
    return front == NULL;
}

// Prosedur untuk menambahkan data pada antrian
void TambahData_131(string NamaMahasiswa_131, string NIM_131) {
    node *baru = new node;
    baru->NamaMahasiswa_131 = NamaMahasiswa_131;
    baru->NIM_131 = NIM_131;
    baru->next = NULL;
    if (isEmpty_131()) {
        front = back = baru;
    } else {
        back->next = baru;
        back = baru;
    }
}

// Prosedur untuk mengurangi antrian (lanjut ke antrian selanjutnya)
void KurangiAntrian_131(){
    if (!isEmpty_131()) {
        node *hapus = front;
        if (front == back) {
            front = back = NULL;
        } else {
            front = front->next;
        }
        delete hapus;
        cout << "Antrian pertama telah dihapus." << endl;
    } else {
        cout << "Antrian masih kosong!" << endl;
    }
}

// Fungsi untuk menghitung jumlah antrian
int HitungAntrian_131() {
    int jumlah_131 = 0;
    node *hitung = front;
    while (hitung != NULL) {
        hitung = hitung->next;
        jumlah_131++;
    }
    return jumlah_131;
}

// Prosedur untuk menghapus seluruh antrian
void HapusAntrian_131() {
    while (!isEmpty_131()) {
        KurangiAntrian_131();
    }
}

// Prosedur untuk menampilkan antrian
void LihatAntrian_131() {
    if (isEmpty_131()) {
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "=== Antrian Saat Ini ===" << endl;
        cout << left << setw(5) << "No" << setw(30) << "Nama Mahasiswa" << setw(15) << "NIM" << endl;
        cout << "============================================="<<endl;
        int NomorAntrian_131 = 1;
        node *bantu = front;
        while (bantu != NULL) {
            cout << left << setw(5) << NomorAntrian_131 << setw(30) << bantu->NamaMahasiswa_131 << setw(15) << bantu->NIM_131 << endl;
            bantu = bantu->next;
            NomorAntrian_131++;
        }
    }
}

int main() {
    Inisialisasi_131(); // Inisialisasi antrian
    int pilih_131;
    string nama_131, nim_131;

    do {
        cout << "============================================="<<endl;
        cout << "=           Menu Antrian Mahasiswa          ="<<endl;
        cout << "============================================="<<endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Kurangi Antrian" << endl;
        cout << "3. Lihat Antrian" << endl;
        cout << "4. Hitung Antrian" << endl;
        cout << "5. Hapus Seluruh Antrian" << endl;
        cout << "0. Keluar" << endl;
        cout << "==========="<<endl;
        cout << "Pilihan: ";
        cin >> pilih_131;
        cout << "==========="<<endl;

        switch (pilih_131) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                cin>>nama_131;
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim_131;
                TambahData_131(nama_131, nim_131);
                cout << "============================================="<<endl;
                cout << "Data mahasiswa dengan Nama " << nama_131 << " dengan NIM " << nim_131 << " berhasil disimpan kedalam antrian." << endl;
                break;
            case 2:
                KurangiAntrian_131();
                break;
            case 3:
                LihatAntrian_131();
                break;
            case 4:
                cout << "Jumlah antrian saat ini: " << HitungAntrian_131() << endl;
                break;
            case 5:
                HapusAntrian_131();
                cout << "Seluruh antrian telah dihapus." << endl;
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilih_131 != 0);

    return 0;
}