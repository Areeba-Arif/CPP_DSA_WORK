#include <iostream>
using namespace std;

#define MAX 100

struct Vertex {
    int id;
};

Vertex graph[MAX];
int adjMatrix[MAX][MAX];
int n = 0;

// ---------- INITIALIZE ----------
void initGraph() {
    for (int i = 0; i < MAX; i++) {
        graph[i].id = i;
        for (int j = 0; j < MAX; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// ---------- ADD VERTEX ----------
void addVertex() {
    if (n >= MAX) {
        cout << "Graph is full!\n";
        return;
    }

    graph[n].id = n;

    // Initialize new row and column
    for (int i = 0; i <= n; i++) {
        adjMatrix[n][i] = 0;
        adjMatrix[i][n] = 0;
    }

    n++;
    cout << "Vertex added successfully!\n";
}

// ---------- REMOVE VERTEX ----------
void removeVertex(int v) {
    if (v < 0 || v >= n) {
        cout << "Invalid vertex!\n";
        return;
    }

    // Shift rows up
    for (int i = v; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = adjMatrix[i + 1][j];
        }
    }

    // Shift columns left
    for (int j = v; j < n - 1; j++) {
        for (int i = 0; i < n; i++) {
            adjMatrix[i][j] = adjMatrix[i][j + 1];
        }
    }

    // Update vertex IDs
    for (int i = v; i < n - 1; i++) {
        graph[i].id = i;
    }

    n--;
    cout << "Vertex removed successfully!\n";
}

// ---------- DISPLAY ----------
void displayMatrix() {
    cout << "\nAdjacency Matrix:\n\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// ---------- MAIN ----------
int main() {
    int choice, v;

    initGraph();

    do {
        cout << "\n1. Add Vertex\n";
        cout << "2. Remove Vertex\n";
        cout << "3. Display Matrix\n";
        cout << "0. Exit\n";

        cin >> choice;

        switch (choice) {

            case 1:
                addVertex();
                break;

            case 2:
                cout << "Enter vertex to remove: ";
                cin >> v;
                removeVertex(v);
                break;

            case 3:
                displayMatrix();
                break;
        }

    } while (choice != 0);

    return 0;
}