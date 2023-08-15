/*Branch and Bound Algorithm for Travelling Sales Person*/
#include <stdio.h>

int a[10][10], visited[10], n, cost = 0;

void get()
{
    int i, j;
    printf("Enter No.of Cities: ");
    scanf("%d", &n);
    printf("\nEnter Cost Matrix: \n");
    for (i = 0; i < n; i++)
    {
        // printf("Enter Elements of Row #: %d\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        visited[i] = 0;
    }
    printf("\n\nThe cost list is:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
    }
}

int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        if ((a[c][i] != 0) && (visited[i] == 0))
            if (a[c][i] < min)
            {
                min = a[i][0] + a[c][i];
                kmin = a[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}

void mincost(int city)
{
    int i, ncity;
    visited[city] = 1;
    printf("%d->", city + 1);
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}

void put()
{
    printf("\n\nMinimum cost: ");
    printf("%d", cost);
}

int main()
{
    get();
    printf("\n\nThe Path is: ");
    mincost(0);
    put();
    return 0;
}
