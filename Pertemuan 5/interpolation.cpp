#include <iostream>
#include <algorithm>
#include <math.h>    
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    int data[N];
    cout << "Masukkan " << N << " data (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    // Urutkan data ascending agar bisa digunakan untuk Interpolation Search
    sort(data, data + N);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    // TODO : Proses Interpolation Search
    while (low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = low + ((float)(high - low) / (data[high] - data[low])) * (cari - data[low]);
        posisi = round(posisi1);

        cout << "Posisi perkiraan: " << posisi << endl;

        if (data[posisi] == cari) {
            flag = 1;
            break;
        } else if (data[posisi] < cari) {
            low = posisi + 1;
        } else {
            high = posisi - 1;
        }
    }
    
    
    cout << "\n\nHasil: ";
    if (flag == 1)
        cout << "Data " << cari << " ditemukan pada indeks ke-" << posisi << endl;
    else
        cout << "Data " << cari << " tidak ditemukan dalam array." << endl;

    return 0;
}