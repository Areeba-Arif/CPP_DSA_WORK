#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// A simple structure to hold a coordinate
struct Point {
    int r, c;
};

int main() {
    srand(time(0)); // Seed for random generation

    int n, m;
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    // 1. Create and randomly fill a simple 2D array
    // We use standard 0 and 1 values.
    int A[100][100]; // Supporting up to a 100x100 grid for simplicity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = (rand() % 10 < 3) ? 1 : 0; // ~30% chance of block (1)
        }
    }
    // Force start (0,0) and end (n-1, m-1) to be open (0)
    A[0][0] = 0;
    A[n - 1][m - 1] = 0;

    // Print the generated Maze
    cout << "\nGenerated Maze (0 = Open, 1 = Blocked):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    // 2. Map coordinates to a unique integer ID (0 to n*m - 1)
    // ID = row * m + col
    // Example: (1,1) in a 3-column grid is ID = 1 * 3 + 1 = 4
    
    int totalVertices = n * m;
    vector<int> adj[10000]; // Simple array of vectors for graph adjacency list

    // 8-directional offsets
    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Construct the graph connections
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (A[r][c] == 1) continue; // Skip blocked cells

            int u = r * m + c; // Current node ID

            for (int d = 0; d < 8; d++) {
                int nr = r + rowOffsets[d];
                int nc = c + colOffsets[d];

                // Check boundary and make sure target cell is open (0)
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && A[nr][nc] == 0) {
                    int v = nr * m + nc; // Neighbor node ID
                    adj[u].push_back(v); // Add connection (edge)
                }
            }
        }
    }

    // Print the Graph representation (ID mapping)
    cout << "\n--- Mapped Graph Connections (as IDs) ---\n";
    for (int i = 0; i < totalVertices; i++) {
        int r = i / m;
        int c = i % m;
        if (A[r][c] == 0) {
            cout << "Node ID " << i << " (" << r << "," << c << ") is connected to: ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }
    cout << "-------------------------------------------\n";

    // 3. BFS logic using simple array tracking
    int start = 0;              // ID for (0,0)
    int dest = totalVertices - 1; // ID for (n-1, m-1)

    queue<int> q;
    bool visited[10000] = {false};
    int parent[10000]; // Track parent path: parent[child_id] = parent_id
    
    // Initialize parent array with -1
    for (int i = 0; i < totalVertices; i++) parent[i] = -1;

    visited[start] = true;
    q.push(start);

    bool pathFound = false;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == dest) {
            pathFound = true;
            break;
        }

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    // 4. Output path reconstruction
    if (!pathFound) {
        cout << "\nNo path exists from (0,0) to (" << n - 1 << "," << m - 1 << ").\n";
    } else {
        vector<int> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());

        cout << "\nPath found! Indices covered by the mouse:\n";
        for (size_t i = 0; i < path.size(); i++) {
            // Convert node ID back to 2D coordinates (Row and Column)
            int r = path[i] / m;
            int c = path[i] % m;
            cout << "(" << r << "," << c << ")";
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\n";
    }

    return 0;
}