#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  // Menentukan jumlah simpul
  int jumlahSimpul_131;
  cout << "Silakan masukkan jumlah simpul: ";
  cin >> jumlahSimpul_131;

  // Membuat vektor untuk menyimpan nama simpul
  vector<string> namaSimpul_131(jumlahSimpul_131);

  // Memasukkan nama simpul
    cout << "Silahkan masukan nama simpul "<<endl;
    for (int i = 0; i < jumlahSimpul_131; i++) {
    cout << "simpul " << i + 1 << ": ";
    cin >> namaSimpul_131[i];
  }

  // Membuat matriks untuk menyimpan bobot antar simpul
  vector<vector<int>> bobotSimpul_131(jumlahSimpul_131, vector<int>(jumlahSimpul_131));

  // Memasukkan bobot antar simpul
  cout << "Silahkan masukan bobot antar simpul " << endl;
  for (int i = 0; i < jumlahSimpul_131; i++) {
    for (int j = 0; j < jumlahSimpul_131; j++) {
      cout << namaSimpul_131[i] << " -> " << namaSimpul_131[j] << ": ";
      cin >> bobotSimpul_131[i][j];
    }
  }

  cout<<endl;
  // Menampilkan header baris
  cout << setw(8) << " ";
  for (int i = 0; i < jumlahSimpul_131; i++) {
    cout << setw(8) << namaSimpul_131[i];
  }
  cout << endl;
  // Menampilkan isi matriks
  for (int i = 0; i < jumlahSimpul_131; i++) {
    cout << setw(8) << namaSimpul_131[i];
    for (int j = 0; j < jumlahSimpul_131; j++) {
      cout << setw(8) << bobotSimpul_131[i][j];
    }
    cout << endl;
  }

  return 0;
}
