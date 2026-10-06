/*A network of n locations is represented as a graph. Write a C program that accepts the graph using an Adjacency Matrix, accepts a starting vertex, performs a graph traversal, 
displays the visit order, and ensures that a vertex is not processed repeatedly. Test it with connected and partially connected graphs. */
/*A network of n locations is represented as a graph. Write a C program that accepts the graph using an Adjacency Matrix, accepts a starting vertex, 
performs a graph traversal, displays the visit order, and ensures that a vertex is not processed repeatedly. Test it with connected and partially connected graphs. */
#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int n;
void DFS(int vertex)
{
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int start, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    printf("\nDFS Traversal: ");
    DFS(start);
    printf("\n");
    return 0;
}