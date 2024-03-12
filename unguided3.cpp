/*
oleh Irfan Thoriq Habibi - 2311102121
*/
//contoh dari Program Fungsi Map
#include <iostream>
#include <map> //berfungsi supaya bisa menggunakan fungsi struktur data map
using namespace std;

int main() {
    //Deklarasi map dengan key int yang memiliki value yakni setring
    map<int, string> binatang_131;

    // Menambahkan elemen-elemen yang berada didalam map yang berisi macam-macam hewan yang berada di kebun binatang
    //setiap binatang memiliki jumlah yang berbeda-beda
    binatang_131[1] = "Gajah = 4";
    binatang_131[2] = "jerapah = 6";
    binatang_131[3] = "zebra = 3";
    binatang_131[4] = "rusa = 8";
    binatang_131[5] = "harimau = 2"; 

    cout << "====Selamat Datang di Kebun Binatang ABC==="<<endl;
    cout << "berikut ini adalah daftar binatang yang ada di kebun binatang ini"<<endl;
    //menggunakan loop mencetak nomor dan macam-macan binatang beserta jumlahnya.
    for (int b =1;b<=binatang_131.size();b++){
        cout <<"No."<< b <<" "<<binatang_131[b]<<endl;
    }
    return 0;
}
