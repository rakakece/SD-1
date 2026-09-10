#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "masukkan jumlah elemen array : ";
    cin >> n;

    int* arr = new int [n];

    cout << "masukkan " << n << " angka : \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "isi array : ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}