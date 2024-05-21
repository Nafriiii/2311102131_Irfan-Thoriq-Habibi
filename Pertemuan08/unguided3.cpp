/*
Irfan Thoriq Habibi - 2311102131
*/

#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel dan inisialisasi nilai awal
    int n = 10; 
    int data_131[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; 
    int cari_131;
    int count = 0; 

    cout << "-------------------------------------" << endl;
    cout << "-         Sequential Search         -" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Data: (9, 4, 1, 4, 7, 10, 5, 4, 12, 4)" << endl;
    cout << "Masukkan angka yang ingin Anda cari: ";
    cin >> cari_131;

    // Melakukan pencarian berurutan dalam array
    for (int i = 0; i < n; i++) {
        if (data_131[i] == cari_131) {
            count++;
        }
    }
    cout << "\nJumlah angka " << cari_131 << " dalam data: " << count << endl;

    return 0;
}
