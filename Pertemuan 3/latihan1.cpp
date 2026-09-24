#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// Menambahkan karakter ke stack
void push(char value) {
    if (top < MAX - 1) {
        top++;
        stack[top] = value;
    }
}

// Mengambil karakter paling atas
char pop() {
    if (top >= 0) {
        char value = stack[top];
        top--;
        return value;
    }

    return '\0';
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // Memasukkan setiap karakter ke stack
    for (char c : kata) {
        push(c);
    }

    // Mengeluarkan karakter dari stack
    cout << "Kata setelah dibalik: ";

    while (top >= 0) {
        cout << pop();
    }

    cout << endl;

    return 0;
}