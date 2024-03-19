/*
oleh Irfan Thoriq Habibi - 2311102121
*/
#include <iostream>
using namespace std;
int main (){
    int maks, a, i = 1, lokasi;
    cout <<"masukkan panjang array :";
    cin>>a; 
    int array[a];
    cout << " masukkan " << a << "angka\n";
    for ( i =0; i < a; i++){
        cout << " array ke-"<< (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i =0; i <a; i++){
        if  (array[i] > maks){
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di array ke " <<lokasi <<endl;
}