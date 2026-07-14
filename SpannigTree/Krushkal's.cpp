#include <iostream>
using namespace std;

#define MAX_VERTICES 100
#define MAX_EDGES 1000

struct Edge {
    char src;
    char dest;
    int weight;
};

// --- Disjoint Set Union (DSU) / Union-Find Struct ---
struct DisjointSet {
    int parent[26]; // Track parents for capital letters A-Z

    void makeSet() {
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
            return true; // Union successful, no cycle
        }
        return false; // Cycle detected
    }
};

struct Graph {
    Edge edges[MAX_EDGES];
    int numVertices;
    int numEdges;
};

void initGraph(Graph& g, int vertices) {
    g.numVertices = vertices;
    g.numEdges = 0;
}

void addEdge(Graph& g, char src, char dest, int weight) {
    g.edges[g.numEdges++] = {src, dest, weight};
}

void kruskalMST(Graph& g) {
    // 1. Sort edges by weight using basic Bubble Sort
    for (int i = 0; i < g.numEdges - 1; i++) {
        for (int j = 0; j < g.numEdges - i - 1; j++) {
            if (g.edges[j].weight > g.edges[j + 1].weight) {
                Edge temp = g.edges[j];
                g.edges[j] = g.edges[j + 1];
                g.edges[j + 1] = temp;
            }
        }
    }

    DisjointSet dsu;
    dsu.makeSet();

    cout << "\n--- Kruskal's Minimum Spanning Tree Edges ---\n";
    int mstWeight = 0;
    int edgesCount = 0;

    for (int i = 0; i < g.numEdges; i++) {
        if (edgesCount == g.numVertices - 1) break;

        int u = g.edges[i].src - 'A';
        int v = g.edges[i].dest - 'A';

        if (dsu.unite(u, v)) {
            cout << g.edges[i].src << " - " << g.edges[i].dest << " (Weight: " << g.edges[i].weight << ")\n";
            mstWeight += g.edges[i].weight;
            edgesCount++;
        }
    }
    cout << "Total MST Weight: " << mstWeight << endl;
}

int main() {
    Graph g;
    // Let's assume a sample graph with 4 vertices: A, B, C, D
    initGraph(g, 4);

    addEdge(g, 'A', 'B', 10);
    addEdge(g, 'A', 'C', 6);
    addEdge(g, 'A', 'D', 5);
    addEdge(g, 'B', 'D', 15);
    addEdge(g, 'C', 'D', 4);

    kruskalMST(g);

    return 0;
}