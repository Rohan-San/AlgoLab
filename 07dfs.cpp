#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void DFS(int startVertex, int** graph, int numVertices) {
    bool* visited = new bool[numVertices] {false};
    stack<int> visitedStack;

    visitedStack.push(startVertex);
    visited[startVertex] = true;

    while (!visitedStack.empty()) {
        int vertex = visitedStack.top();
        visitedStack.pop();

        cout << vertex << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (graph[vertex][i] && !visited[i]) {
                visitedStack.push(i);
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

    cout << "DFS Traversal: ";
    auto start = high_resolution_clock::now();
    DFS(startVertex, graph, numVertices);
    auto end = high_resolution_clock::now();
    auto dur = duration_cast<nanoseconds>(end - start).count();
    cout << endl;
    cout << "The time taken for the traversal is " << dur <<" nanoseconds." << endl;


    return 0;
}
