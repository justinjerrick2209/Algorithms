#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[5];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    for (int i = 0; i < 5; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    int cost = 0;

    cout << "Edges in MST:\n";

    for (Edge e : edges) {

        if (find(e.u) != find(e.v)) {

            cout << e.u << " - "
                 << e.v << " : "
                 << e.w << endl;

            cost += e.w;
            unite(e.u, e.v);
        }
    }

    cout << "Minimum Cost = " << cost << endl;

    return 0;
}
