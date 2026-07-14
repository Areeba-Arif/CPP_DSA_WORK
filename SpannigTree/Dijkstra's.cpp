#include <iostream>
using namespace std;

#define MAX 26
#define INF 999999

struct DijkstraGraph {
    int adjMatrix[MAX][MAX];
    bool exists[MAX];
};

void initGraph(DijkstraGraph& g) {
    for (int i = 0; i < MAX; i++) {
        g.exists[i] = false;
        for (int j = 0; j < MAX; j++) {
            g.adjMatrix[i][j] = 0;
        }
    }
}

void addVertex(DijkstraGraph& g, char v) {
    g.exists[v - 'A'] = true;
}

void addEdge(DijkstraGraph& g, char src, char dest, int weight) {
    addVertex(g, src);
    addVertex(g, dest);
    g.adjMatrix[src - 'A'][dest - 'A'] = weight; // Directed setup
}

void dijkstra(DijkstraGraph& g, char startVertex) {
    int dist[MAX];
    bool visited[MAX] = {false};

    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    
    int srcIdx = startVertex - 'A';
    dist[srcIdx] = 0;

    for (int count = 0; count < MAX; count++) {
        int minDist = INF, u = -1;

        // Extract min distance node
        for (int v = 0; v < MAX; v++) {
            if (g.exists[v] && !visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        // Relax neighbors
        for (int v = 0; v < MAX; v++) {
            if (g.exists[v] && !visited[v] && g.adjMatrix[u][v] != 0 && dist[u] != INF) {
                if (dist[u] + g.adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + g.adjMatrix[u][v];
                }
            }
        }
    }

    cout << "\n--- Dijkstra's Shortest Paths from Source " << startVertex << " ---\n";
    cout << "Destination \t Shortest Distance\n";
    for (int i = 0; i < MAX; i++) {
        if (g.exists[i]) {
            char destChar = i + 'A';
            cout << destChar << " \t\t ";
            if (dist[i] == INF) cout << "INF (Unreachable)\n";
            else cout << dist[i] << "\n";
        }
    }
}

int main() {
    DijkstraGraph g;
    initGraph(g);

    addEdge(g, 'A', 'B', 4);
    addEdge(g, 'A', 'C', 2);
    addEdge(g, 'B', 'C', 3);
    addEdge(g, 'B', 'D', 2);
    addEdge(g, 'C', 'B', 1);
    addEdge(g, 'C', 'D', 5);

    dijkstra(g, 'A');

    return 0;
}