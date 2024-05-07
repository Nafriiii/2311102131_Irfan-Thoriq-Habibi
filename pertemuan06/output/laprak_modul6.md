# <h1 align="center">Laporan Praktikum Modul STACK</h1>
<p align="center">Irfan Throqi Habibi - 2311102131</p>

## Dasar Teori

A.STACK<br/>
 Stack merupakan struktur data  tumpukan yang mengikuti prinsip dari LIFO (last In First Out) yang mana elemen yang ditambahkan terakhir akan terlebih dahulu dihapus.<br/>
 Stack/tumpukan terdiri dari list linier yang dipada elemen puncaknya dinamakan (TOP).TOP ini merupakan tempat terjadinya operasi penyisipan dan penghapusan pada stack. pada penyisipan dilakukan diatas TOP, dan penghapusan dilakukan pada TOP.<br/>
B. Contoh pengoperasian STACK
 berikut ini merupakan contoh dari pengoperasian stack pada c++ antara lain :<br/>
a.IsFull (berfungsi untuk memeriksa tumpukan penuh atau tidak)<br/>
```C++
bool isFull(){
    return (top == maksimal);
}
```
b.IsEmpty (berfungsi untuk memeriksa tumpukan kosong atau tidak)<br/>
```C++
bool isEmpty(){
    return (top == 0);
}
```
c.push (Menambahkan elemen pada posisi paling atas)<br/>
```C++
void pushArrayBuku(string data){
    if (isFull()){
        cout << "Data telah penuh" << endl;
    }
    else{
        arrayBuku[top] = data;
        top++;
    }
}
```
d.pop (Menghapus elemen pada posisi paling atas)<br/>
```C++
void popArrayBuku(){
    if (isEmpty()){
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else{
        arrayBuku[top - 1] = "";
        top--;
    }
}
```
e.peek (Melihat nilai/elemen pada posisi tertentu)<br/>
```C++
void peekArrayBuku(int posisi){
    if (isEmpty()){
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else{
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
```
f.destroy/clear (Menghapus semua elemen pada tumpukan)<br/>
```C++
void destroyArraybuku(){
    for (int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}
```
## Guided 

### 1. [Stack]

```C++
/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull(){
    return (top == maksimal);
}
bool isEmpty(){
    return (top == 0);
}
void pushArrayBuku(string data){
    if (isFull()){
        cout << "Data telah penuh" << endl;
    }
    else{
        arrayBuku[top] = data;
        top++;
    }
}
void popArrayBuku(){
    if (isEmpty()){
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else{
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi){
    if (isEmpty()){
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else{
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
int countStack(){
    return top;
}
void changeArrayBuku(int posisi, string data){
    if (posisi > top){
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else{
        int index = top;
        for (int i = 1; i <= posisi; i++){
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku(){
    for (int i = top; i >= 0; i--){
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku(){
    if (isEmpty()){
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else{
        for (int i = top - 1; i >= 0; i--){
            cout << arrayBuku[i] << endl;
        }
    }
}
int main(){
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}

```
jadi pada guided ini berisi tentang data buku yang tersimpan didalam suatu stack. pada int main telah diinputkan oleh user. jadi program akan menampilkan sesuai dengan data yang tersimpan didalam stacknya. karena pada program ini tidak terdapat menu, maka user harus menginputkan sendiri perintah yang ingin ia lakukan pada int main.
## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]

```C++
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
```
#### Output:
![1](1)

program ini berfungsi untuk menentukan suatu kalimat apakah ia polindrom atau tidak. jadi pada cleanstack_131 ini berfungsi untuk mengubah semua huruf menjadi huruf kecil agar tidak memengaruhi perbandingan karakter ketika akan di cek apakah ia polidrom atau tidak. palindrome_131 berfungsi untuk mengecek kata yang diinputkan user itu polindrom atau tidak dengan membandingkan setiap karakter pada stack. jika karakter tersebut bukan palindrom makan akan menjadi false dan jika karakter tersebut palindrom apa menjadi true.

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakanstack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

```C++
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
            case 1:
            //menginputkan kata yang ingin dibalikkan
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


```
#### Output:
![2](2)
program ini berfungsi untuk membalikkan kata dari suatu kalimat seperti contohnya irfan menjadi nafri. jadi pada fungsi membalikkankata_131 disini berfungsi untuk membalikkan setiap karakter pada suatu kata yang semulanya berada diawal menjadi diakhir begitu juga sebaliknya,
## Kesimpulan
stack merupakan suatu struktur data yang mengikuti prinsif LIFO ( Last In First Out) yang mana pada nilai/elemen terakhir akan ditempatkan pada awal. stack biasanya digunakan pada banyak aplikasi seperti evaluasi ekspresi matematika,pembalikan urutan kata,dll.[1].

## Referensi
[1] Triase, Triase. "Struktur Data: Diktat Edisi Revisi." (2020).<br/>
[2] Schmidt, Thomas C. "Redesigning and Evaluating the Network Stack in the C++ Actor Framework."