#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int n) {
    Node *newNode = new Node();
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    Node *newNode = new Node();
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "Linked list kosong, silahkan insert di depan atau belakang.\n";
        return;
    }

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Nilai " << check << " tidak ditemukan.\n";
        return;
    }

    Node *newNode = new Node();
    newNode->value = n;
    newNode->next = p->next;
    p->next = newNode;

    if (p == tail) {
        tail = newNode;
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head == NULL) tail = NULL;
    delete temp;
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node *p = head;
    while (p->next != tail) {
        p = p->next;
    }

    delete tail;
    tail = p;
    tail->next = NULL;
}

void deleteByValue(int value) {
    if (head == NULL) {
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

    if (p->next == NULL) {
        cout << "Nilai " << value << " tidak ditemukan.\n";
    } else {
        Node *temp = p->next;
        p->next = temp->next;
        if (temp == tail) tail = p;
        delete temp;
    }
}

void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    if (temp == NULL) {
        cout << "NULL\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int pilihan;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        int nilai, nilaiCari;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertFirst(nilai);
                printList();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                printList();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                insertAfter(nilai, nilaiCari);
                printList();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                deleteByValue(nilai);
                printList();
                break;

            case 5:
                printList();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }

    } while (pilihan != 0);

    return 0;
}