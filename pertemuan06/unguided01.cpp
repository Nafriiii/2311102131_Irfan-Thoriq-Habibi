/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
#include <stack>
using namespace std;

//fungsi untuk membersihkan dan mengubah semua karakter menjadi huruf kecil
string cleanstack_131(string str) {
    string cleaned;
    for (char c : str) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}
//fungsi untuk menentukan suatu kata apakah polidrom atau tidak
bool Palindrome_131(string str) {
    stack<char> charStack;
    str = cleanstack_131(str);
    for (char c : str) {
        charStack.push(c);
    }
    for (char c : str) {
        if (c != charStack.top()) {
            return false;
        }
        charStack.pop();
    }
    return true;
}

int main() {
    int choice;
    string kalimat;

    do {
        cout <<"-----------------------------------"<<endl;
        cout << "============== Menu =============="<<endl;
        cout <<"-----------------------------------"<<endl;
        cout << "1. Cek kalimat palindrome"<<endl;
        cout << "2. Keluar"<<endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore(); // untuk membersihkan buffer
        cout <<"-----------------------------------"<<endl;

        switch (choice) {
            case 1:
                cout << "Masukkan kalimat: ";
                getline(cin, kalimat);
                if (Palindrome_131(kalimat)) {
                    cout << "Kalimat tersebut adalah palindrom." << endl;
                } else {
                    cout << "Kalimat tersebut bukan palindrom." << endl;
                }
                break;
            case 2:
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 2);

    return 0;
}