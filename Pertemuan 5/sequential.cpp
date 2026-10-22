#include <iostream>
using namespace std;

int main() {
    int n, key, posisi = -1;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[n];

    cout << "Masukkan elemen data: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << ": ";
        cin >> data[i];
    }

    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> key;

    // TODO : Proses pencarian sequential/linear
    for(int i = 0; i < n; i++) {
        if (data[i] == key) {
            posisi = i; //simpan posisi data yang ditemukan
            break; //keluar dari loop jika data ditemukan
        }
    }

    // Output hasil
    if (posisi != -1) {
        cout << "Data ditemukan di posisi: " << posisi << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
    return 0;
}
