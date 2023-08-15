#include<iostream>
#include<ctime>
using namespace std;
#define MAX 100

bool visited[MAX];
int adj[MAX][MAX];

void dfs(int start, int n)
{
    int stack[MAX];
    int top = -1;
    int v;
    visited[start] = true;
    stack[++top] = start;
    while(top!=-1)
    {
        v = stack[top--];
        cout<<v<<" ";
        for(int i=0;i<n;i++)
        {
            if(adj[v][i]&& !visited[i])
            {
                visited[i]=true;
                stack[++top]=i;    
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
    for (int i=0;i<n;i++)
        visited[i] = false;
    clock_t start_t = clock();
    dfs(start, n);
    clock_t end = clock();
    double time = double(end-start_t)/CLOCKS_PER_SEC;
    cout<<"time taken: "<<time*1000000<<" Microsseconds\n";
    return 0;
}
