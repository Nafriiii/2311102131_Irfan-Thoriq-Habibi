#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana untuk menghasilkan indeks dari kunci (NIM)
int hash_func(string key) {
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % MAX_SIZE;
}

// Struktur data untuk menyimpan informasi mahasiswa
struct data_131 {
    string nama_131;
    string nim_131;
    int nilai_131;
    data_131* next;
    data_131(string nama_131, string nim_131, int nilai_131) : nama_131(nama_131),nim_131(nim_131), nilai_131(nilai_131), next(nullptr) {}
};

// Kelas HashTable
class HashTable {
private:
    data_131** table; 

public:
    // Konstruktor untuk inisialisasi tabel hash
    HashTable() {
        table = new data_131*[MAX_SIZE]();
    }

    // Destruktor untuk membebaskan memori yang dialokasikan
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            data_131* current = table[i];
            while (current != nullptr) {
                data_131* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Fungsi untuk menambahkan data mahasiswa ke hashtable
    void insertdata_131(string nama_131, string nim_131, int nilai_131) {
        int index = hash_func(nim_131);
        data_131* current = table[index];
        while (current != nullptr) {
            if (current->nim_131 == nim_131) {
                current->nilai_131 = nilai_131;
                return;
            }
            current = current->next;
        }
        data_131* data = new data_131(nama_131, nim_131, nilai_131);
        data->next = table[index];
        table[index] = data;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    data_131* carinim_131(string nim_131) {
        int index = hash_func(nim_131);
        data_131* current = table[index];
        while (current != nullptr) {
            if (current->nim_131 == nim_131) {
                return current;
            }
            current = current->next;
        }
        return nullptr; // Mengembalikan null jika data tidak ditemukan
    }

    // Fungsi untuk mencari dan menampilkan data mahasiswa berdasarkan rentang nilai
    void carinilai_131(int dari_131, int hingga_131) {
        cout << "======================================================"<<endl;
        cout << "=      DATA MAHASISWA DENGAN NILAI DALAM RENTANG     ="<<endl;
        cout << "======================================================"<<endl;
        cout << setw(25) << left << "NAMA" << setw(20) << left << "NIM" << setw(10) << left << "NILAI" << endl;
        cout << "======================================================"<<endl;
        for (int i = 0; i < MAX_SIZE; i++) {
            data_131* current = table[i];
            while (current != nullptr) {
            if (current->nilai_131 >= dari_131 && current->nilai_131 <= hingga_131) {
                cout << setw(25) << left << current->nama_131 << setw(20) << left << current->nim_131 << setw(10) << left << current->nilai_131 << endl;
            }
            current = current->next;
        }
    }
    cout << "======================================================"<<endl;
}

    // Fungsi untuk menghapus data mahasiswa berdasarkan nama
    void hapusdata_131(string nama_131) {
        for (int i = 0; i < MAX_SIZE; i++) {
            data_131* current = table[i];
            data_131* prev = nullptr;
            while (current != nullptr) {
                if (current->nama_131 == nama_131) {
                    if (prev == nullptr) {
                        table[i] = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    cout << "==================================================" << endl;
                    cout << "Data dengan nama " << nama_131 << " telah dihapus!" << endl;
                    cout << "==================================================" << endl;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
        cout << "Data dengan nama " << nama_131 << " tidak tersedia!" << endl;
    }

    // Fungsi untuk menampilkan seluruh data mahasiswa dalam hashtable
    void Traverse_131()
    {
        cout << "======================================================"<<endl;
        cout << "=      DATA MAHASISWA DENGAN NILAI DALAM RENTANG     ="<<endl;
        cout << "======================================================"<<endl;
        cout << setw(25) << left << "NAMA" << setw(20) << left << "NIM" << setw(10) << left << "NILAI" << endl;
        cout << "======================================================" << endl;
        for (int i = 0; i < MAX_SIZE; i++)
        {
            data_131 *current = table[i];
            while (current != nullptr)
            {
                cout << setw(25) << left << current->nama_131 << setw(20) << left << current->nim_131 << setw(10) << left << current->nilai_131 << endl;
                current = current->next;
            }
        }
        cout << "=======================================================" << endl;
    }
};

// Fungsi utama
int main() {
    HashTable ht;

    cout << "=============================================================================="<<endl;
    cout << "=                    PROGRAM HASH TABLE DATA DARI MAHASISWA                  ="<<endl;
    cout << "=============================================================================="<<endl;
    while (true) {
        cout << "============================="<<endl;
        cout << "=           Menu            ="<<endl;
        cout << "============================="<<endl;
        cout << "1. Tambahkan Data Mahasiswa"<<endl;
        cout << "2. Hapus Data Mahasiswa"<<endl;
        cout << "3. Cari Data Sesuai Dengan NIM Mahasiswa"<<endl;
        cout << "4. Cari Data Sesuai dengan Nilai"<<endl;
        cout << "5. Tampilkan Seluruh Data Mahasiswa"<<endl;
        cout << "6. Keluar"<<endl;
        cout << "Masukkan pilihan anda: ";
        int pilih_131;
        cin >> pilih_131;

        switch (pilih_131) {
            case 1: {
                cout << "================================================="<<endl;
                cout << "=           TAMBAHKAN DATA MAHASISWA            ="<<endl;
                cout << "================================================="<<endl;
                string nim_131;
                string nama_131;
                int nilai_131;
                cout << "Inputkan Nama: ";
                cin.ignore();
                getline(cin , nama_131);
                cout << "Inputkan NIM: ";
                cin >> nim_131;
                cout << "Inputkan Nilai: ";
                cin >> nilai_131;
                ht.insertdata_131(nama_131,nim_131, nilai_131);
                cout <<endl;
                cout << "Data mahasiswa dengan nama " << nama_131 << ", NIM " << nim_131 << ", Nilai " << nilai_131 << " berhasil ditambahkan." << endl;
                break;
            }
            case 2: {
                cout << "============================================" << endl;
                cout << "=           HAPUS DATA MAHASISWA           =" << endl;
                cout << "============================================" << endl;
                string nama_131;
                cout << "Inputkan Nama yang akan dihapus: ";
                cin.ignore();
                getline(cin, nama_131);
                ht.hapusdata_131(nama_131);
                break;
            }
            case 3: {
                cout << "==============================================================" << endl;
                cout << "=           CARI DATA SESUAI DENGAN NIM MAHASISWA            =" << endl;
                cout << "==============================================================" << endl;
                string nim_131;
                cout << "Inputkan NIM: ";
                cin >> nim_131;
                data_131* data = ht.carinim_131(nim_131);
                if (data != nullptr)
                    cout << "NIM " << nim_131 << " dimiliki oleh " << data->nama_131 << " dengan nilai " << data->nilai_131 << endl;
                else
                    cout << "Data tidak ditemukan!" << endl;
                break;
            }
            case 4: {
                cout << "======================================================" << endl;
                cout << "=           CARI DATA SESUAI DENGAN NILAI            =" << endl;
                cout << "======================================================" << endl;
                int dari_131, hingga_131;
                cout << "Rentang dimulai dari nilai: ";
                cin >> dari_131;
                cout << "hingga nilai: ";
                cin >> hingga_131;
                cout << "======================================================" << endl;
                cout << "=Mahasiswa dengan nilai antara " << dari_131 << " dan " << hingga_131 << " adalah: "<<endl;
                cout << "======================================================" << endl;
                ht.carinilai_131(dari_131, hingga_131);
                break;
            }
            case 5: {
                cout << "========================================================" << endl;
                cout << "=           TAMPILKAN SELURUH DATA MAHASISWA           =" << endl;
                cout << "========================================================" << endl;
                ht.Traverse_131();
                break;
            }
            case 6:
                cout << "==================================================================" << endl;
                cout << "=           Terima Kasih Telah Menggunakan Program Ini           =" << endl;
                cout << "==================================================================" << endl;
                return 0;
            default:
                cout << "==================================================================" << endl;
                cout << "=       Input tidak valid Mohon masukkan angka 1 hingga 6.       =" << endl;
                cout << "==================================================================" << endl;
        }
    }
}
