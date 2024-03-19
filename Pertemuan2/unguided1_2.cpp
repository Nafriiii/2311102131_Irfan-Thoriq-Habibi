/*
oleh Irfan Thoriq Habibi - 2311102121
*/
#include <iostream>
#include <array>

using namespace std;

int main() {
    //// Mendeklarasikan array untuk menyimpan data yang berukuran 10
    array<int, 10> data_131;
    int angka_131;

    // Input data array dari user
    cout << "===Inputkan Data Array Yang Ingin Disimpan=== "<<endl;
    cout << "data array: ";
    for (int i_131 = 0; i_131 < 10; i_131++) {
        cin >> angka_131;
        data_131[i_131] = angka_131;
    }

    // Menampilkan angka genap dari data array
    cout << "Nomor genap: ";
    for (int i_131 = 0; i_131 < 10; i_131++) {
        if (data_131[i_131] % 2 == 0)
            cout << data_131[i_131] << ", ";
    }
    cout << endl;

    // Menampilkan angka ganjil dari data array
    cout << "Nomor ganjil: ";
    for (int i_131 = 0; i_131 < 10; i_131++) {
        if (data_131[i_131] % 2 != 0)
            cout << data_131[i_131] << ", ";
    }
    cout << endl;

    return 0;
}
