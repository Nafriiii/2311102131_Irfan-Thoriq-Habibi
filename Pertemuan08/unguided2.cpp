/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk memeriksa apakah suatu karakter adalah huruf vokal
bool vokal_131(char huruf_131) {
    huruf_131 = tolower(huruf_131);  // Mengubah karakter menjadi huruf kecil untuk memudahkan pengecekan
    return huruf_131 == 'a' || huruf_131 == 'e' || huruf_131 == 'i' || huruf_131 == 'o' || huruf_131 == 'u';
}

// Fungsi untuk menghitung banyaknya huruf vokal dalam sebuah kalimat
int Banyakvokal_131(const string& kalimat_131) {
    int count = 0;
    for (char ch : kalimat_131) { 
        if (vokal_131(ch)) {  
            count++;  
        }
    }
    return count; 
}

int main() {
    string data_131;

    cout << "---------------------------------"<<endl;
    cout << " Program menghitung jumlah vokal "<<endl;
    cout << "---------------------------------"<<endl;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, data_131); 

    // Menghitung jumlah huruf vokal
    int Jumlavokal_131 = Banyakvokal_131(data_131); 
    cout << "Jumlah huruf vokal dalam kalimat: " << Jumlavokal_131 << endl;

    return 0;
}
