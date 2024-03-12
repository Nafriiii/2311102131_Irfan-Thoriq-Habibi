/* 
1. Fungsi Class
class adalah salah satu konsep dari OOP (Object Oriented Programming)yang digunakan untuk membungkus 
suatu data abstraksi procedural sebagai deskripsi yang tergeneralisir atau rangcangan dari sebuah object 
untuk mendefinisikan atau menggambarakan isi dan tingkah laku sebagai entitas dari sebuah objek. 
*/
/*
2. Fungsi Struct
struct merupakan struktur data yang mana membentuk tipe data baru dengan cara menggabungkan satu tipe data dengan tipe data yang berbeda didalam C++.
struct dapat menyimpan serta menggabungkan berbagai variabel tipe data yang berbeda.
*/

// Contoh program dari fungsi struct dan class
#include <iostream>
using namespace std;

//deklarasi dari Struct data_131 yang didalamnya berisi data string (nama),char (jurusan) dan int (umur).
struct data_131 {
    string username_131;
    int password_131;
};
//deklarasi dari class hp_131 yang idalamnya berisi string(brand,model)dan int (tahunrilis,jumlah)
class hp_131 {
    public :
       string brand_131;
       string model_131;
       int tahunrilis_131;
       int jumlah_131;
};

int main (){
    //inisialisasi dari fungsi struct (data_131)di atas yang terdiri dari username dan password
    cout << "contoh program struct "<<endl;
    cout << "oleh Irfan Thoriq Habibi, NIM:2311102131"<<endl;
    cout << endl;
    data_131 data{"Irfan ",112322380};
    cout << "nama pengguna :"<<data.username_131<<endl;
    cout << "password :"<<data.password_131<<endl;
    cout<<endl;

    //inisialisasi dari fungsi class (hp_131)di atas yang terdiri dari brand,model,tahun rilis,dan jumlah.
    hp_131 hp;
    hp.brand_131 = "poco";
    hp.model_131 = "poco x3 pro";
    hp.tahunrilis_131 = 2021;
    hp.jumlah_131 = 1;
    cout << "contoh program class "<<endl;
    cout << endl;
    cout << "hp saya :"<<hp.brand_131<<endl;
    cout << "model :"<<hp.model_131<<endl;
    cout << "tahun rilis :"<<hp.tahunrilis_131<<endl;
    cout << "jumlah :"<<hp.jumlah_131<<endl;
    return 0;
}
