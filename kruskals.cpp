#include <iostream>
#include <algorithm>

using namespace std;

const int V = 5;
const int MAX_E = V * (V - 1) / 2;

// Define a class to represent an edge in the graph
class Edge {
public:
    int src, dest, weight;

    Edge() : src(0), dest(0), weight(0) {}
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Disjoint Set Union (DSU) data structure
class DSU {
private:
    int parent[V];
    int rank[V];

public:
    DSU() {
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int v) {
        if (v != parent[v])
            parent[v] = find(parent[v]);
        return parent[v];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB])
                swap(rootA, rootB);
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB])
                rank[rootA]++;
        }
    }
};

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskalMST(Edge edges[], int E) {
    sort(edges, edges + E, [](Edge& a, Edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu;

    Edge mst[V - 1];
    int mstSize = 0;
    for (int i = 0; i < E && mstSize < V - 1; ++i) {
        int srcRoot = dsu.find(edges[i].src);
        int destRoot = dsu.find(edges[i].dest);

        if (srcRoot != destRoot) {
            mst[mstSize++] = edges[i];
            dsu.unite(srcRoot, destRoot);
        }
    }

    cout << "Minimum Spanning Tree edges:" << endl;
    for (int i = 0; i < mstSize; ++i) {
        cout << mst[i].src << " - " << mst[i].dest << " : " << mst[i].weight << endl;
    }
}

int main() {
    Edge edges[MAX_E] = {
        Edge(0, 1, 2),
        Edge(0, 3, 6),
        Edge(1, 2, 3),
        Edge(1, 3, 8),
        Edge(1, 4, 5),
        Edge(2, 4, 7),
        Edge(3, 4, 9)
    };

    int E = 7; // Number of edges

    kruskalMST(edges, E);

    return 0;
}
