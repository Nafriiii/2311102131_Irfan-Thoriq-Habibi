/*
Irfan Thoriq Habibi - 2311102131
*/
#include <iostream>

using namespace std;

int main (){
    int n = 10;
    int data[n] = {9,4,1,7,5,12,4,13,4,10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for (i = 0; i < n; i++){
        if ( data [i]==cari){
            ketemu = true;
            break;
        }
    }
    cout << " Program Sequential search"<<endl;
    cout << "data : {9,4,1,7,5,12,4,13,4,10}"<<endl;

    if (ketemu){
        cout << "\nangka "<<cari<<" ditemukan pada indeks ke -"<<i<<endl;
    }else{
        cout <<"data tidak diketemukan"<<endl;
    }
    return 0;
}