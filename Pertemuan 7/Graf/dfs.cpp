#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j) {
        // i dan j dikurang satu supaya sesuai dengan angka di gambar
        i--;
        j--;
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1; // karena graf tidak berarah
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // ----- BAGIAN DFS -----
    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "Depth-First Traversal (dari vertex " << startVertex << "):" << endl;

        // TODO: panggil fungsi dfsUtil di sini
        dfsUtil(startVertex, visited);

        cout << endl;
    }

    void dfsUtil(int currentVertex, vector<bool>& visited) {
        // TODO: isi logika DFS di sini
        // 1. Tandai simpul sekarang sudah dikunjungi
        visited[currentVertex] = true;

        // 2. Cetak simpul sekarang
        int currentRealVertex = currentVertex + 1;
        cout << currentRealVertex << " ";

        // 3. Kunjungi semua simpul yang terhubung (rekursif)
        for(int i = 0; i < numVertices; i++){
            if(adjMatrix[currentVertex][i] == 1 && !visited[i]){
                dfsUtil(i, visited);
            }
        }
    }
};

int main() {
    Graph g(8);

    // Parameter fungsi addEdge sekarang menerima angka sesuai gambar
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 8);

    // Cetak adjacency matrix untuk melihat representasi graf
    g.printAdjMatrix();
    cout << endl;

    // Panggil fungsi DFS mulai dari vertex 0 (yakni simpul 1)
    g.dfs(0);

    return 0;
}