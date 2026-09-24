#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    int input;

    //Input berhenti ketika input bukan angka
    while (cin >> input) {
        s.push(input);
    }

    //Mengeluarkan semua data dari stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}