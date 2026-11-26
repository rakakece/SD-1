#include <iostream>
#include <vector>
using namespace std;

class HashTableLinear {
private:
    int size;
    vector<int> table;

    // TODO 1: Buat hash function (kembalikan index awal)
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTableLinear(int s) {
        size = s;
        table.resize(size, -1); 
    }

    // TODO 2: Buat fungsi insert dengan linear probing
    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % size;
        }

        table[index] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (table[i] == -1)
                cout << "EMPTY";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    int size, n, value;

    cout << "Masukkan ukuran hash table: ";
    cin >> size;

    HashTableLinear ht(size);

    cout << "Berapa banyak angka yang ingin dimasukkan? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Input angka ke-" << i + 1 << ": ";
        cin >> value;
        ht.insert(value);
    }

    cout << "\n=== HASH TABLE (LINEAR PROBING) ===\n";
    ht.display();

    return 0;
}