#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<int> q;
    int input;

    //Memasukkan data ke queue
    while ( cin >> input) {
        q.push(input);
    }

    //Mengeluarkan dan menampilkan semua data
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    return 0;
}