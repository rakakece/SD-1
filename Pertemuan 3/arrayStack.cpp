#include <iostream>
using namespace std;

#define MAX 5 //slotnya sebanyak 5
int stack[MAX]; //int stack[5];
int top = -1; //awal stack kosong

// TODO : Operasi Push
void push (int value) {
    if(top == MAX - 1 ){
        cout << "Stack Penuh !\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << "ditambahkan dalam stack\n";
    }
}

// TODO : Operasi Pop
void pop (){
    if(top == -1){
        cout << "Stack Kosong !\n";
    } else {
        cout << "\n" << stack[top] << "dihapus dari stack\n";
        top--;
    }
}

// TODO : Nampilin Stack
void display(){
    if (top == -1){
        cout << "Stack Kosong !\n";
    } else {
        cout << "\nIsi Stack : ";
        for(int i = top; i >= 0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display;

    return 0;
}