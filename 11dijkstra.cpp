#include <iostream>
using namespace std;

#define INF 99999
#define MAX 20

int parent[MAX], key[MAX];
int graph[MAX][MAX];
bool visited[MAX];

int minDistance(int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] <= min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int v) {
    if (parent[v] == -1)
        return;
    printPath(parent[v]);
    cout << v << " ";
}

void printSolution(int src, int V) {
    cout << "Vertex \tDistance \tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t" << key[i] << " \t\t" << src << " ";
        printPath(i);
        cout << endl;
    }
}

void dijkstra(int src, int V) {
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    key[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(V);
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && key[u] != INF && key[u] + graph[u][v] < key[v]) {
                key[v] = key[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution(src, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    int source;
    cout << "Enter the adjacency matrix of the graph (row by row):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(source, V);
    return 0;
}
