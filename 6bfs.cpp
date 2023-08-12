#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void BFS(int startVertex, int** graph, int numVertices) {
    bool* visited = new bool[numVertices] {false};
    queue<int> visitedQueue;

    visitedQueue.push(startVertex);
    visited[startVertex] = true;

    while (!visitedQueue.empty()) {
        int vertex = visitedQueue.front();
        visitedQueue.pop();

        cout << vertex << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (graph[vertex][i] && !visited[i]) {
                visitedQueue.push(i);
                visited[i] = true;
            }
        }
    }

    
}

int main() {
    const int numVertices = 7;
    int** graph = new int*[numVertices];

    for (int i = 0; i < numVertices; ++i) {
        graph[i] = new int[numVertices] {0};
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][5] = 1;
    graph[2][6] = 1;

    int startVertex = 0;

    cout << "BFS Traversal: ";
    auto start = high_resolution_clock::now();
    BFS(startVertex, graph, numVertices);
    auto end = high_resolution_clock::now();
    auto dur = duration_cast<nanoseconds>(end - start).count();
    cout << endl;
    cout << "The time taken for the traversal is " << dur <<" nanoseconds." << endl;
    return 0;
}
