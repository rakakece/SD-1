#include <bits/stdc++.h>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet) {

    int min = INT_MAX, min_index;

    for (int v = 0; v < mstSet.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    int totalWeight = 0;
    for (int i = 1; i < graph.size(); i++) {
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << endl;
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total weight of MST = " << totalWeight << endl;
}

void primMST(vector<vector<int>> &graph) {
    
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V);

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; // artnya vertex tidak ditarik dari vertex lain

    for (int count = 0; count < V - 1; count++) {
        
        // TODO (Step 1): Choose the vertex 'u' with the smallest key value
        // that is not yet included in the MST
        int u = minKey(key, mstSet);

        // TODO (Step 2): Mark the chosen vertex 'u' as part of the MST
        mstSet[u] = true;

        // TODO (Step 3): Update the key values and parent indexes
        for (int v = 0; v < V; v++) {
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
  	 vector<vector<int>> graph = {
        // 0   1   2   3   4   5   6   7   8
        { 0,  4,  0,  0,  0,  0,  0,  8,  0 }, // 0
        { 4,  0,  8,  0,  0,  0,  0, 11,  0 }, // 1
        { 0,  8,  0,  7,  0,  4,  0,  0,  2 }, // 2
        { 0,  0,  7,  0,  9, 14,  0,  0,  0 }, // 3
        { 0,  0,  0,  9,  0, 10,  0,  0,  0 }, // 4
        { 0,  0,  4, 14, 10,  0,  2,  0,  0 }, // 5
        { 0,  0,  0,  0,  0,  2,  0,  1,  6 }, // 6
        { 8, 11,  0,  0,  0,  0,  1,  0,  7 }, // 7
        { 0,  0,  2,  0,  0,  0,  6,  7,  0 }  // 8
    };

    // Print the solution
    primMST(graph);

    return 0;
}