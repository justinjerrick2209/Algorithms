#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n = 5;

    // Graph represented using adjacency matrix
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[5];
    bool visited[5];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;

    int totalCost = 0;

    cout << "Edges in MST:\n";

    for (int count = 0; count < n; count++) {
        int u = -1;

        // Find vertex with minimum key
        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = true;

        if (key[u] != 0) {
            cout << "Vertex " << u
                 << " - Weight " << key[u] << endl;
            totalCost += key[u];
        }

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
            }
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}
