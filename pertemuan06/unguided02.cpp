/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//fungsi digunakan untuk membalikkan kata seperti contoh irfan menjadi nafri
string membalikankata_131(string sentence) {
    stack<char> charStack;
    string reversedSentence;

    for (char c : sentence) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }

    return reversedSentence;
}

int main() {
    int choice;
    string kalimat;
    do {
        cout <<"-----------------------------------"<<endl;
        cout << "============== Menu =============="<<endl;
        cout <<"-----------------------------------"<<endl;
        cout << "1. Balikkan Kalimat"<<endl;
        cout << "2. Keluar"<<endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore(); // membersihkan buffer
        cout <<"-----------------------------------"<<endl;

        switch (choice) {
            //menginputkan kata yang ingin dibalikkan
            case 1:
                cout << "Masukkan kalimat: ";
                getline(cin, kalimat);
                cout << "Kalimat Awal: " << kalimat << endl;
                cout << "Kalimat Terbalik: " << membalikankata_131(kalimat) << endl;
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
