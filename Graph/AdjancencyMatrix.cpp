#include <iostream>
using namespace std;

#define MAX 100

// ---------- VERTEX STRUCT ----------
struct Vertex {
    int id;
};

// ---------- GRAPH ----------
Vertex graph[MAX];
int adjMatrix[MAX][MAX];
int n;
bool directed;
bool weighted;

// ---------- INIT GRAPH ----------
void initGraph() {
    for (int i = 0; i < n; i++) {
        graph[i].id = i;

        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// ---------- ADD EDGE ----------
void addEdge(int u, int v, int w = 1) {

    if (weighted)
        adjMatrix[u][v] = w;
    else
        adjMatrix[u][v] = 1;

    if (!directed) {
        if (weighted)
            adjMatrix[v][u] = w;
        else
            adjMatrix[v][u] = 1;
    }
}

// ---------- REMOVE EDGE ----------
void removeEdge(int u, int v) {
    adjMatrix[u][v] = 0;

    if (!directed) {
        adjMatrix[v][u] = 0;
    }
}

// ---------- CHECK ADJACENCY ----------
bool isAdjacent(int u, int v) {
    return adjMatrix[u][v] != 0;
}

// ---------- DISPLAY MATRIX ----------
void displayMatrix() {
    cout << "\nAdjacency Matrix:\n\n";

    // Column headers
    cout << "        ";
    for (int j = 0; j < n; j++) {
        cout << "( " << graph[j].id << " ) ";
    }
    cout << endl;

    // Rows
    for (int i = 0; i < n; i++) {

        cout << "( " << graph[i].id << " )   ";

        for (int j = 0; j < n; j++) {
            cout << "  " << adjMatrix[i][j] << "    ";
        }

        cout << endl;
    }
}

// ---------- DEGREE ----------
int findDegree(int v) {
    int count = 0;

    for (int i = 0; i < n; i++)
        if (adjMatrix[v][i] != 0)
            count++;

    return count;
}

int findInDegree(int v) {
    int count = 0;

    for (int i = 0; i < n; i++)
        if (adjMatrix[i][v] != 0)
            count++;

    return count;
}

int findOutDegree(int v) {
    return findDegree(v);
}

// ---------- NEIGHBOURS ----------
void findNeighbours(int v) {
    cout << "Neighbours of " << graph[v].id << ": ";

    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] != 0)
            cout << graph[i].id << " ";
    }
    cout << endl;
}

// ---------- DFS ----------
// void dfs(int v, bool visited[]) {
//     visited[v] = true;

//     for (int i = 0; i < n; i++) {
//         if (adjMatrix[v][i] != 0 && !visited[i])
//             dfs(i, visited);
//     }
// }

// ---------- PATH ----------
bool findPathUtil(int u, int v, bool visited[]) {
    if (u == v) return true;

    visited[u] = true;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[u][i] != 0 && !visited[i]) {
            if (findPathUtil(i, v, visited))
                return true;
        }
    }
    return false;
}

bool findPath(int u, int v) {
    bool visited[MAX] = {false};
    return findPathUtil(u, v, visited);
}


// ---------- OUTPUT EDGES ----------
void outputAll() {
    cout << "\nEdges:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (adjMatrix[i][j] != 0) {
                if (weighted)
                    cout << graph[i].id << " -> " << graph[j].id
                         << " (weight: " << adjMatrix[i][j] << ")\n";
                else
                    cout << graph[i].id << " -> " << graph[j].id << endl;
            }
        }
    }
}

// ---------- MAIN ----------
int main() {

    int choice, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter graph type (1 = directed, 0 = undirected): ";
    cin >> directed;

    cout << "Enter weight type (1 = weighted, 0 = unweighted): ";
    cin >> weighted;

    initGraph();

    do {
        cout << "\n========== GRAPH MENU ==========\n";
        cout << "1. Add Edge\n";
        cout << "2. Remove Edge\n";
        cout << "3. Display Matrix\n";
        cout << "4. Check Adjacency\n";
        cout << "5. Degree\n";
        cout << "6. InDegree\n";
        cout << "7. OutDegree\n";
        cout << "8. Neighbours\n";
        cout << "9. Path\n";
        cout << "10. Output Edges\n";
        cout << "0. Exit\n";

        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter u and v: ";
                cin >> u >> v;

                if (weighted) {
                    int w;
                    cout << "Enter weight: ";
                    cin >> w;
                    addEdge(u, v, w);
                } else {
                    addEdge(u, v);
                }

                break;

            case 2:
                cin >> u >> v;
                removeEdge(u, v);
                break;

            case 3:
                displayMatrix();
                break;

            case 4:
                cin >> u >> v;
                cout << (isAdjacent(u, v) ? "Adjacent\n" : "Not Adjacent\n");
                break;

            case 5:
                cin >> v;
                cout << findDegree(v) << endl;
                break;

            case 6:
                cin >> v;
                cout << findInDegree(v) << endl;
                break;

            case 7:
                cin >> v;
                cout << findOutDegree(v) << endl;
                break;

            case 8:
                cin >> v;
                findNeighbours(v);
                break;

            case 9:
                cin >> u >> v;
                cout << (findPath(u, v) ? "Path Exists\n" : "No Path\n");
                break;

            case 10:
                outputAll();
                break;
        }

    } while(choice != 0);

    return 0;
}