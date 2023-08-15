#include<iostream>
#include<ctime>
#define MAX 100

using namespace std;

bool visited[MAX];
int adj[MAX][MAX];

void bfs(int start, int n)
{
    int queue[MAX];
    int front = 0, rear=-1;
    int v;
    for (int i=0;i<n;i++)
        visited[i] = false;
    visited[start] = true;
    queue[++rear] = start;
    while(front<=rear)
    {
        v = queue[front++];
        cout<<v<<" ";
        for(int i=0;i<n;i++)
        {
            if(adj[v][i]&& !visited[i])
            {
                visited[i]=true;
                queue[++rear]=i;    
            }
        }
    }
    cout<<endl;
}

int main()
{
    int start, n;
    cout<<"enter num of vertices: ";
    cin>>n;
    cout<<"enter vertices:"<<endl;
    for(int i = 0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>adj[i][j];
    cout<<"enter starting vertice: ";
    cin>>start;
    clock_t start_t = clock();
    bfs(start, n);
    clock_t end = clock();
    double time = double(end-start_t)/CLOCKS_PER_SEC;
    cout<<"time taken: "<<time*1000000<<" Microsseconds\n";
    return 0;
}
