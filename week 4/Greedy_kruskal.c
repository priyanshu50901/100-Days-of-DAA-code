#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int find(int parent[], int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}

void unionSet(int parent[], int a, int b)
{
    parent[a] = b;
}

int main()
{
    struct Edge e[20], temp;
    int parent[20];
    int n, m, i, j;
    int count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v weight):\n");

    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }

    // Sorting edges according to weight
    for(i = 0; i < m - 1; i++)
    {
        for(j = 0; j < m - i - 1; j++)
        {
            if(e[j].w > e[j + 1].w)
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }

    // Initially every vertex is its own parent
    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for(i = 0; i < m && count < n - 1; i++)
    {
        int a = find(parent, e[i].u);
        int b = find(parent, e[i].v);

        if(a != b)
        {
            printf("%d - %d = %d\n", e[i].u, e[i].v, e[i].w);

            cost = cost + e[i].w;
            unionSet(parent, a, b);

            count++;
        }
    }

    printf("\nMinimum cost = %d\n", cost);

    return 0;
}