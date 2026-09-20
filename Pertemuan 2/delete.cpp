#include <iostream>
using namespace std;

// Deklarasi Struktur Node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Fungsi Cetak List
void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Fungsi tambah node di akhir (biar ada data untuk dihapus)
void insertLast(int n) {
    Node *newNode = new Node{n, NULL};
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// TODO : Hapus node pertama
void deleteFirst() {
    if (head != NULL) {
      cout << "List kosong!\n";
      return;

    }

    Node *temp = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    delete temp;

    }

// TODO : Hapus node terakhir
void deleteLast() {
     if (head != NULL) {
      cout << "List kosong!\n";
      return;

     }

     if(head == tail) {
        delete head;
        head = tail = NULL;
        return;

    }

    Node *p = head;
    while(p->next != tail) {
        p = p->next;
    }

    delete tail;
    tail = p;
    tail->next = NULL;

}

// Hapus node dengan nilai tertentu
void deleteMiddle(int value) {
    if (head != NULL) {
      cout << "List kosong!\n";
      return;

    }

    if (head->value == value) {
        deleteFirst();
        return;

    }

    Node *p = head;
    while (p->next != NULL && p->next->value != value) {
        p = p->next;
    }

    if(p->next == NULL) {
        cout << "Nilai " << value << " tidak ditemukan\n";

    } else {
        Node *temp = p->next;
        p->next = temp->next;
        if(temp == tail) tail = p;
        delete temp;
    }
}

int main() {
    // Contoh list awal
    insertLast(10);
    insertLast(20);
    insertLast(30);

    cout << "List awal:\n";
    printList();

    cout << "\nHapus node pertama:\n";
    deleteFirst();
    printList();

    cout << "\nHapus node terakhir:\n";
    deleteLast();
    printList();

    cout << "\nHapus node dengan nilai 20:\n";
    deleteMiddle(20);
    printList();

    return 0;
}