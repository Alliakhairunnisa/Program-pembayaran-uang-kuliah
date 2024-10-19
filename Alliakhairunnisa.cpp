#include <iostream>
#include <string>

using namespace std;

struct Jurusan {
  string kode;
  string nama;
  int pmbyrnAwal;
  int jmlhCicilan;
  int besarCicilan;
};

void tampilkanDataJurusan(Jurusan jurusan[], int jmlhJurusan) {  
    cout << "Kode | Jurusan                | Pembayaran Awal | Jumlah Cicilan | Besar Cicilan\n";
    cout << "--------------------------------------------------------------------------------\n";
    for (int i = 0; i < jmlhJurusan; i++) {
        cout << jurusan[i].kode << "   | " 
             << jurusan[i].nama << "  | " 
             << jurusan[i].pmbyrnAwal << "            | " 
             << jurusan[i].jmlhCicilan << "          | " 
             << jurusan[i].besarCicilan << "\n";
    }
}

Jurusan* cariJurusan(Jurusan jurusan[], int jmlhJurusan, const string& kodeJurusan) {
  for (int i = 0; i <jmlhJurusan; i++) {
    if (jurusan[i].kode == kodeJurusan) {
      return &jurusan[i];
    }
  }
  return nullptr;
  
}

int main() {
  Jurusan jurusan[] = {
    {"SI", "Sistem Informasi", 2100000, 7, 300000},
    {"TI", "Teknik Informatika", 2500000, 7, 300000},
    {"KA", "Komputer  Akutansi", 1750000, 6, 200000},
    {"MI", "Manajemen Informatika", 1500000, 6, 250000}
  };
  
  const int jmlhJurusan = sizeof(jurusan) / sizeof(jurusan[0]);
  char lagi;
  
  cout << "+----------------------------------------------------------------+\n";
  cout << "|      Aplikasi Pembayaran Uang Kuliah Kaist University          |\n";
  cout << "+----------------------------------------------------------------+\n";
  
  
  do {
    string namaMahasiswa, npm, kodeJurusan;
    
    cout << "Nama Mahasiswa: ";
    getline(cin, namaMahasiswa);
    cout << "NPM: ";
    getline(cin, npm);
    cout << endl;
    
    tampilkanDataJurusan(jurusan, jmlhJurusan);
    cout << "\nKode Jurusan: ";
    cin >> kodeJurusan;
    
    Jurusan* jurusanDitemukan = cariJurusan(jurusan, jmlhJurusan, kodeJurusan);
   
    if (!jurusanDitemukan) {
      cout << "Kode Jurusan tidak ditemukan!\n";
      continue;
   }
   
   int totalUangKuliah = jurusanDitemukan->pmbyrnAwal + (jurusanDitemukan->jmlhCicilan * jurusanDitemukan->besarCicilan);
   cout << "Jurusan: " << jurusanDitemukan->nama << endl;
   cout << "Total uang kuliah: " << totalUangKuliah << endl;
   
   
   int pmbyrnKe;
   cout << "Masukkan Pembayaran Ke-i (1 s/d " << jurusanDitemukan->jmlhCicilan << "); ";
   cin >> pmbyrnKe;
   
   if (pmbyrnKe < 1 || pmbyrnKe > jurusanDitemukan->jmlhCicilan) {
     cout << "Pembayaran Ke-i tidak valid!\n";
     continue;
   }
   
   int uangKuliahTerbayar = jurusanDitemukan->pmbyrnAwal + ((pmbyrnKe - 1) * jurusanDitemukan->besarCicilan);
   cout << "Uang Kuliah Terbayar setelah " << pmbyrnKe << " kali cicilan: " << uangKuliahTerbayar << endl;
   cout << "Sisa Uang Kuliah: " << totalUangKuliah - uangKuliahTerbayar << endl;
   
   cout << "Masih ingin menghitung? (Y/T): ";
   cin >> lagi;
   cin.ignore(); 
   
   cout << "+----------------------------------------------------------------+\n";
   
  }while (lagi == 'Y' || lagi == 'y');
  
  return 0;
  
}
