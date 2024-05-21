#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cctype> // Untuk tolower
using namespace std;

// Fungsi untuk mengurutkan array karakter menggunakan selection sort
void selectionsort_131(char dataArray_131[], int length) {
    int temp, min, i, j;
    for (i = 0; i < length - 1; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            if (tolower(dataArray_131[j]) < tolower(dataArray_131[min])) { // Konversi ke huruf kecil sebelum membandingkan
                min = j;
            }
        }
        temp = dataArray_131[i];
        dataArray_131[i] = dataArray_131[min];
        dataArray_131[min] = temp;
    }
}

// Fungsi untuk mencari karakter menggunakan binary search
void binarysearch_131(char dataArray_131[], int length, char cari) {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = length - 1;
    int firstIndex = -1;

    // Cari indeks pertama dari karakter yang dicari menggunakan binary search
    while (awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (tolower(dataArray_131[tengah]) == tolower(cari)) { // Konversi ke huruf kecil sebelum membandingkan
            b_flag = true;
            firstIndex = tengah;
            akhir = tengah - 1;
        } else if (tolower(dataArray_131[tengah]) < tolower(cari)) { // Konversi ke huruf kecil sebelum membandingkan
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (b_flag) {
        cout << "\nKarakter '" << cari << "' ditemukan pada indeks ke: ";
        for (int i = firstIndex; i < length && tolower(dataArray_131[i]) == tolower(cari); i++) {
            cout << i;
            if (i < length - 1 && tolower(dataArray_131[i+1]) == tolower(cari)) {
                cout << ", "; // Tambahkan koma jika masih ada indeks selanjutnya yang sama
            }
        }
        cout << endl;
    } else {
        cout << "\nKarakter '" << cari << "' tidak ditemukan\n";
    }
}

int main() {
    char kalimat[30];
    char cari;

    cout << "======================="<<endl;
    cout << "     BINARY SEARCH     "<<endl;
    cout << "======================="<<endl;
    cout << "Masukkan sebuah kalimat: ";
    cin.getline(kalimat, 30);

    // Menghapus spasi dan menghitung panjang kalimat tanpa spasi
    int n = 0;
    for (int i = 0; kalimat[i] != '\0'; i++) {
        if (kalimat[i] != ' ') {
            kalimat[n++] = tolower(kalimat[i]); // Konversi ke huruf kecil
        }
    }
    kalimat[n] = '\0';  // Null-terminate the string

    // Tampilkan data awal
    cout << "\nKalimat awal: ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << kalimat[i];
    }
    cout << endl;

    // Urutkan data dengan selection sort
    selectionsort_131(kalimat, n);

    // Tampilkan data setelah diurutkan
    cout << "\nKalimat setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << kalimat[i];
    }
    cout << endl;

    cout << "\nMasukkan Huruf yang ingin Anda cari: ";
    cin >> cari;

    // Cari Huruf menggunakan binary search, menampilkan semua indeks,dan mengkonversikan semua menjadi huruf kecil
    binarysearch_131(kalimat, n, tolower(cari));

    _getche();
    return 0;
}
