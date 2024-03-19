#include <iostream>
#include <iomanip>

using namespace std;

// Variabel untuk menyimpan pilihan, ukuran array, nilai maksimum, minimum, dan rata-rata
char pilih_131; 
int ukuran_131, maks_131, min_131, rata_131;
double total_131; 

// Fungsi untuk meminta pengguna menginputkan ukuran array
void dataarray_131() {
    cout << "Masukkan ukuran array: ";
    cin >> ukuran_131;
}

// Fungsi untuk menampilkan menu pilihan
void menu_131() {
    cout << "1. Cari nilai maksimum \n";
    cout << "2. Cari nilai minimum \n";
    cout << "3. Cari nilai rata-rata \n";
    cout << "0. Keluar dari program \n";
    cout << "Pilihan anda: ";
    cin >> pilih_131;
}

int main() {
    cout << "Selamat datang di program array ini\n";
    
    // Meminta pengguna memasukkan ukuran array
    dataarray_131();

    // Alokasi memori dinamis untuk array
    int* array_131 = new int[ukuran_131];

    // Meminta pengguna memasukkan nilai-nilai array
    for (int i_131 = 0; i_131 < ukuran_131; i_131++) {
        cout << "Input bilangan ke-" << i_131 + 1 << " : ";
        cin >> array_131[i_131];
    }
    cout << endl;

    // Loop untuk menampilkan menu pilihan dan menjalankan operasi sesuai pilihan pengguna
    do {
        menu_131();
        switch (pilih_131) {
            case '1':
                // Mencari nilai maksimum dari array
                maks_131 = array_131[0];
                for (int i_131 = 0; i_131 < ukuran_131; i_131++) {
                    if (array_131[i_131] > maks_131) {
                        maks_131 = array_131[i_131];
                    }
                }
                cout << "Nilai maksimum adalah " << maks_131 << endl;
                break;
            case '2':
                // Mencari nilai minimum dari array
                min_131 = array_131[0];
                for (int i_131 = 0; i_131 < ukuran_131; i_131++) {
                    if (array_131[i_131] < min_131) {
                        min_131 = array_131[i_131];
                    }
                }
                cout << "Nilai minimum adalah " << min_131 << endl;
                break;
            case '3':
                // Menghitung nilai rata-rata dari array
                total_131 = 0;
                for (int i_131 = 0; i_131 < ukuran_131; i_131++) {
                    total_131 += array_131[i_131];
                }
                rata_131 = total_131 / ukuran_131;
                cout << "Nilai rata-rata adalah " << setprecision(2) << fixed << rata_131 << endl;
                break;
            case '0':
                // Keluar dari program
                cout << "Terima kasih sudah menggunakan program ini.\n";
                break;
            default:
                // Menampilkan pesan error jika pilihan tidak valid
                cout << "GAGAL!! Mohon untuk memasukkan sesuai yang ada di menu! \n";
                break;
        }
    } while (pilih_131 != '0'); // Loop akan terus berjalan sampai pengguna memilih (0)untuk keluar dari program

    // Dealokasi memori dinamis yang dialokasikan untuk array
    delete[] array_131;

    return 0;
}
