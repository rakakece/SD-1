#include <iostream>
#include <algorithm> 
using namespace std;

// TODO : fungsi Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target, int step = 1){
    if (left > right) {
        return -1; // target tidak ditemukan
    }

    int mid = left + (right - left) / 2;

    cout << "Iterasi ke-" << step << ": ";
    cout << "left = " << left << ", mid = " << mid << ", right = " << right << endl;
    cout << " -> arr[mid] = " << arr[mid] << endl;

    if (arr[mid] == target) {
        return mid; // target ditemukan
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, left, mid - 1, target, step + 1); // cari di kiri
    } else {
        return binarySearchRecursive(arr, mid + 1, right, target, step + 1); // cari di kanan
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

    sort(arr, arr + n, greater<int>());

    cout << "\nData setelah diurutkan (descending): ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int target;
    cout << "\nMasukkan angka yang ingin dicari: ";
    cin >> target;

    int hasil = binarySearchRecursive(arr, 0, n - 1, target);

    if (hasil != -1)
        cout << "\nAngka " << target << " ditemukan di indeks ke-" << hasil << endl;
    else
        cout << "\nAngka " << target << " tidak ditemukan dalam array." << endl;

    return 0;
}