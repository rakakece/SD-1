#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void dijkstra(int V, vector<vector<iPair>> &adj, int src) {
    // menyimpan jarak terpendek
    vector<int> dist(V, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    dist[src] = 0;
    pq.push({0, src}); // jarak, simpul

    // Loop Djikstra
    while(!pq.empty()) {
        int u = pq.top().second; // jarak terkecil
        int d = pq.top().first; // jarak dari sumber ke v
        pq.pop();

        // Jika jarak yang di ambil bukan yang terkecil, skip
        if (d > dist[u]) continue;

        // periksa semua tetangga dari simpul u
        for(auto edge : adj[u]){
            int v = edge.first; // vertex tetangga
            int w = edge.second; // bobot jarak u -> v

            // jika jarak melalui u lebih kecil, update jarak ke v
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }


    // Tampilkan hasil akhir
    cout << "Vertex\tDistance from X\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 6; // X, E, G, H, F, Y
    vector<vector<iPair>> adj(V);

    // Menambahkan edge sesuai graf 
    adj[0].push_back({1, 3}); // X–E 
    adj[0].push_back({4, 8}); // X–F
    adj[1].push_back({2, 4}); // E–G
    adj[1].push_back({3, 4}); // E–H
    adj[2].push_back({5, 3}); // G–Y
    adj[3].push_back({5, 3}); // H–Y
    adj[4].push_back({5, 2}); // F–Y

    // Karena graf tidak berarah, tambahkan sisi baliknya juga
    adj[1].push_back({0, 3});
    adj[4].push_back({0, 8});
    adj[2].push_back({1, 4});
    adj[3].push_back({1, 4});
    adj[5].push_back({2, 3});
    adj[5].push_back({3, 3});
    adj[5].push_back({4, 2});

    dijkstra(V, adj, 0); // 0 = X
    return 0;
}