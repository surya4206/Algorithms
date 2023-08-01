#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

// Structure to represent a graph
struct Graph {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];
};


int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


void printShortestPaths(int dist[], int V, int src) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}


void dijkstra(struct Graph* graph, int src) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < graph->V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < graph->V - 1; count++) {
        int u = minDistance(dist, visited, graph->V);
        visited[u] = true;

        for (int v = 0; v < graph->V; v++) {
            if (!visited[v] && graph->graph[u][v] && dist[u] != INF &&
                dist[u] + graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->graph[u][v];
            }
        }
    }

    printShortestPaths(dist, graph->V, src);
}

int main() {
    struct Graph graph;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &graph.V);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < graph.V; i++) {
        for (int j = 0; j < graph.V; j++) {
            scanf("%d", &graph.graph[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(&graph, src);

    return 0;
}
