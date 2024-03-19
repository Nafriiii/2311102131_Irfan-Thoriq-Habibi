/*
oleh Irfan Thoriq Habibi - 2311102121
*/
#include <iostream>
using namespace std;

int main() {
    int x_131, y_131, z_131;

    // Meminta pengguna untuk memasukkan ukuran array tiga dimensi
    cout << "Masukkan ukuran array tiga dimensi "<<endl;
    cout << "x :";
    cin >> x_131;
    cout << "y :";
    cin >> y_131;
    cout << "z :";
    cin >> z_131;

    // Deklarasi array sesuai dengan ukuran yang dimasukkan oleh pengguna
    int arr[x_131][y_131][z_131];

    // Input elemen array
    for (int x = 0; x < x_131; x++) {
        for (int y = 0; y < y_131; y++) {
            for (int z = 0; z < z_131; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output elemen array
    for (int x = 0; x < x_131; x++) {
        for (int y = 0; y < y_131; y++) {
            for (int z = 0; z < z_131; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < x_131; x++) {
        for (int y = 0; y < y_131; y++) {
            for (int z = 0; z < z_131; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
