/*
oleh Irfan Thoriq Habibi - 2311102121
*/
#include <iostream>
#include <iomanip>//untuk mengatur bilangan desimal

using namespace std;

//deklarasi variabel
char no_131;
float sisi_131;
float a_131,b_131,c_131;
float alas_131,tinggi_131;

void menu (){//looping pada menu yang terdapat pilihan mencari keliling dan luas dari segitiga dan persegi.
    cout << "Kalkulator untuk mencari keliling serta luas dari segitiga dan persegi"<<endl;
    cout <<endl;
    cout <<"untuk segitiga";
    cout <<"\n1. Keliling Segitiga";
    cout <<"\n2. Luas Segitiga"<<endl;
    cout<<endl;
    cout <<"untuk persegi ";
    cout <<"\n3. Keliling Persegi";
    cout <<"\n4. Luas Persegi"<<endl; 
    cout <<"masukkan pilihan anda :";
    cin >> no_131;
}
void program1() {//ini merupakan fungsi untuk menghitung keliling segitiga yang mana rumusnya ialah menjumlahkan ketiga sisinya (a+b+c)
    cout <<"\n====KELILING SEGITIGA===="<<endl;
    cout << "sisi a : ";
    cin >> a_131;
    cout << "sisi b : ";
    cin >> b_131;
    cout << "sisi c : ";
    cin >> c_131;
    cout << "keliling segitiga adalah : "<< a_131 + b_131 + c_131 <<endl;
}

void program2(){//ini merupakan fungsi untuk menghitung luas segitiga yang mana rumusnya adalah 0.5 * alas * tinggi
    cout <<"\n====LUAS SEGITIGA===="<<endl;
    cout << "alas : ";
    cin >> alas_131;
    cout << "tinggi : ";
    cin >> tinggi_131;
    cout << "luas segitiga adalah : "<< fixed<<setprecision(2)<< 0.5*alas_131*tinggi_131 <<endl;
}
void program3(){//ini merupakan fungsi untuk menghitung keliling persegi yang mana rumusnya (sisi+sisi+sisi+sisi)
    cout <<"\n===KELILING PERSEGI==="<<endl;
    cout <<"sisi :";
    cin >>sisi_131;
    cout << "Keliling Persegi adalah :"<< sisi_131 + sisi_131 + sisi_131 + sisi_131<<endl;
}
void program4(){//ini merupakan fungsi untuk menghitung luas persegi
    cout << "\n===LUAS PERSEGI==="<<endl;
    cout << "sisi :";
    cin >> sisi_131;
    cout << "Luas Persegi adalah :"<<sisi_131 * sisi_131<<endl;
}


int main() {//fungsi utama
    string ulang_131;
    do { //looping pada menu
        menu(); //memanggil fungsi menu yang didalamnya terdapat case 1-4.
        switch (no_131) {//memilih program yang sesuai dengan yang diinginkan oleh pengguna
            case '1':
                program1();
            break;
            case '2':
                program2();
            break;
            case '3':
                program3();
            break;
            case '4':
                program4();
            break;
            default:
            cout << "gagal.... mohon untuk menginputkan pilihan dengan benar"<<endl;
        }
        cout << "\n Apakah anda ingin menggunakan kalkulator kembali? (y/n) : ";
        cin >> ulang_131;
    }while (ulang_131 =="y" ||ulang_131 =="Y");
    return 0;
}