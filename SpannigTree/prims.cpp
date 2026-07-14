#include <iostream>
using namespace std;

#define MAX 26
#define INF 999999

struct PrimGraph {
    int adjMatrix[MAX][MAX];
    bool exists[MAX];
    int numVertices;
};

void initGraph(PrimGraph& g) {
    g.numVertices = 0;
    for (int i = 0; i < MAX; i++) {
        g.exists[i] = false;
        for (int j = 0; j < MAX; j++) {
            g.adjMatrix[i][j] = 0;
        }
    }
}

void addVertex(PrimGraph& g, char v) {
    int idx = v - 'A';
    if (!g.exists[idx]) {
        g.exists[idx] = true;
        g.numVertices++;
    }
}

void addEdge(PrimGraph& g, char src, char dest, int weight) {
    addVertex(g, src);
    addVertex(g, dest);
    int u = src - 'A';
    int v = dest - 'A';
    g.adjMatrix[u][v] = weight;
    g.adjMatrix[v][u] = weight; // Undirected
}

void primMST(PrimGraph& g, char startVertex) {
    bool inMST[MAX] = {false};
    int parent[MAX];
    int key[MAX];

    for (int i = 0; i < MAX; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    int startIdx = startVertex - 'A';
    key[startIdx] = 0;

    // Loop exactly numVertices times
    for (int count = 0; count < MAX; count++) {
        if (!g.exists[count]) continue;

        int minKey = INF, u = -1;
        for (int v = 0; v < MAX; v++) {
            if (g.exists[v] && !inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        if (u == -1) break;
        inMST[u] = true;

        for (int v = 0; v < MAX; v++) {
            if (g.exists[v] && g.adjMatrix[u][v] != 0 && !inMST[v] && g.adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g.adjMatrix[u][v];
            }
        }
    }

    cout << "\n--- Prim's Minimum Spanning Tree Edges ---\n";
    int totalWeight = 0;
    for (int i = 0; i < MAX; i++) {
        if (g.exists[i] && parent[i] != -1) {
            char uChar = parent[i] + 'A';
            char vChar = i + 'A';
            cout << uChar << " - " << vChar << " (Weight: " << g.adjMatrix[i][parent[i]] << ")\n";
            totalWeight += g.adjMatrix[i][parent[i]];
        }
    }
    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    PrimGraph g;
    initGraph(g);

    addEdge(g, 'A', 'B', 4);
    addEdge(g, 'A', 'C', 3);
    addEdge(g, 'B', 'C', 1);
    addEdge(g, 'B', 'D', 2);
    addEdge(g, 'C', 'D', 5);

    primMST(g, 'A');

    return 0;
}