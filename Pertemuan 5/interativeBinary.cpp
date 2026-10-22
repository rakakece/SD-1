#include <iostream>
#include <algorithm>
using namespace std;

// TODO : fungsi Iterative Binary Search
int binarySearchIterative(int arr[], int n, int target){
    int left = 0;
    int right = n - 1;
    int step = 1; // untuk hitung iterasi

    while (left <= right) {
        int mid = left + (right - left) / 2;

        cout << "Iterasi ke-" << step++ << ": ";
        cout << "left = " << left << ", mid = " << mid << ", right = " << right << endl;
        cout << " -> arr[mid] = " << arr[mid] << endl;

        if (arr[mid] == target) {
            return mid; // target ditemukan
        } else if (arr[mid] < target) {
            right = mid - 1; // cari di kiri
        } else {
            left = mid + 1; // cari di kanan
        }
      return -1; // target tidak ditemukan
    }
}


int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan " << n << " angka (acak):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // ascebding, arr = sort(arr, arr + n);
    sort(arr, arr + n, greater<int>());

    cout << "\nData setelah diurutkan (descending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int target;
    cout << "\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    int hasil = binarySearchIterative(arr, n, target);

    if (hasil != -1)
        cout << "\nAngka " << target << " ditemukan di indeks ke-" << hasil << endl;
    else
        cout << "\nAngka " << target << " tidak ditemukan dalam array." << endl;

    return 0;
}