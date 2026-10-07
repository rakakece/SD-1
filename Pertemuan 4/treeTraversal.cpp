//Rumus Tree

//In order : kiri-root-kanan
//Pre order : root-kiri-kanan
//Post order : kiri-kanan-root


#include <iostream>
using namespace std;

struct Node {
    int data; // simpan data
    Node* kiri; // simpan alamat node kiri
    Node* kanan; // simpan alamat node kanan
};

Node* akar = NULL; // diawal belum ada node

// TODO : Membuat Node Baru
void addNode(Node** akar, int isi) {
    if(*akar == NULL){
        Node* baru = new Node;
        baru->data = isi;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *akar = baru;
    }
}

// TODO : Membuat Pre-order (root - kiri - kanan)
void preOrder(Node* akar) {
    if(akar != NULL){
        cout << akar->data << " "; // root
        preOrder(akar->kiri);
        preOrder(akar->kanan);
    }
}

// TODO : Membuat In-order (kiri - root - kanan)
void inOrder(Node* akar) {
    if(akar != NULL){
        inOrder(akar->kiri);
        cout << akar->data << " ";
        inOrder(akar->kanan);
    }
}

// TODO : Membuat Post-order (kiri - kanan - root)
void postOrder(Node* akar) {
    if(akar != NULL){
        postOrder(akar->kiri);
        postOrder(akar->kanan);
        cout << akar->data << " ";
    }
}

int main() {

    cout << "\n\n\tPosisi Awal Tree:\n\n";

    cout << "\t       15\n";
    cout << "\t      /  \\\n";
    cout << "\t    27    30\n";
    cout << "\t   /  \\\n";
    cout << "\t 25    29\n\n";

    // Membentuk tree
    addNode(&akar, 15);
    addNode(&akar->kiri, 27);
    addNode(&akar->kanan, 30);
    addNode(&akar->kiri->kiri, 25);
    addNode(&akar->kiri->kanan, 29);

    // Traversal
    cout << "Tampilan PreOrder  : ";
    preOrder(akar);

    cout << "\nTampilan InOrder   : ";
    inOrder(akar);

    cout << "\nTampilan PostOrder  : ";
    postOrder(akar);

    return 0;
}