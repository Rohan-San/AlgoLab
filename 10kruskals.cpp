#include <bits/stdc++.h>
using namespace std;

// DSU Implementation
vector<int> parent;
vector<pair<int, int>> ans;

int find(int u)
{
  if (parent[u] == u)
    return u;
  return parent[u] = find(parent[u]);
}

void unionSet(int u, int v)
{
  int pu = find(u);
  int pv = find(v);
  if (pu != pv)
    parent[pu] = pv;
}

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<pair<int, pair<int, int>>> &edges)
{
  sort(edges.begin(), edges.end()); // Sort edges in non-decreasing order of weights
  parent.resize(V); // Initialize parent array for DSU
  for (int i = 0; i < V; ++i)
    parent[i] = i;
  int sum = 0;
  for (auto edge : edges)
  {
    int wt = edge.first;
    int u = edge.second.first;
    int v = edge.second.second;
    if (find(u) != find(v))
    {
      sum += wt;
      unionSet(u, v);
      ans.push_back({u, v});
    }
  }
  return sum;
}

int main()
{
  int V, E;
  cout << "Enter number of vertices & edges of the graph:" << endl;
  cin >> V >> E;
  vector<pair<int, pair<int, int>>> edges;
  cout << "Enter source, destination, and weight of each edge:" << endl;
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
  }
  cout << "The total weight is: " << spanningTree(V, edges) << endl;
  cout << "Traversal order_" << endl;
  for (auto x : ans)
  {
    cout << x.first << '-' << x.second << endl;
  }
  return 0;
}
