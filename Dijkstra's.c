/*A transportation network contains cities connected by roads with different costs. Write a C program implementing Dijkstra’s Shortest Path Algorithm 
that accepts the number of vertices, Create weighted adjacency matrix and source vertex, computes the minimum distance from the source to every other vertex, 
and displays each destination with its shortest distance. Test it using at least five vertices. */
#include <stdio.h>
#define MAX 20
#define INF 99999
void dijkstra(int graph[MAX][MAX], int n, int source)
{
    int distance[MAX];
    int visited[MAX];
    int i, j;
    int minDistance, current;
    for (i = 0; i < n; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[source] = 0;
    for (i = 0; i < n - 1; i++)
    {
        minDistance = INF;
        current = -1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[j] < minDistance)
            {
                minDistance = distance[j];
                current = j;
            }
        }
        if (current == -1)
            break;
        visited[current] = 1;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] &&
                graph[current][j] != 0 &&
                distance[current] + graph[current][j] < distance[j])
            {
                distance[j] =
                    distance[current] + graph[current][j];
            }
        }
    }
    printf("\nShortest distances from source vertex %d:\n", source);
    for (i = 0; i < n; i++)
    {
        if (distance[i] == INF)
            printf("Vertex %d -> Not reachable\n", i);
        else
            printf("Vertex %d -> %d\n", i, distance[i]);
    }
}
int main()
{
    int graph[MAX][MAX];
    int n, source;
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);
    dijkstra(graph, n, source);
    return 0;
}