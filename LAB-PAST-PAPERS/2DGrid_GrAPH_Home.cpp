/*

Conversation with Gemini
write simple code in cpp

using namesapce

To solve this problem, we need to map the grid to a graph and find the shortest path from Umer's initial position (U) to his home (H) using a Breadth-First Search (BFS), which is the standard way to find the shortest path in an unweighted grid/graph.

According to the requirements:

Grid dimensions (width and height) are taken as input from the user.

The user specifies the positions (row and column indices) for Umer (U) and his home (H).

The remaining spaces are randomly populated with empty paths (-) and obstacles (X).

The grid is converted/mapped to a graph representation (where valid neighboring cells have edges between them).

We output the path positions (row and column indices) and find the minimum number of steps to reach the home. If it is unreachable, we return -1.

*/


#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structure to represent a point on the 2D grid
struct Point {
    int r, c;
};

// Node structure for our graph representation
struct GraphNode {
    Point pos;
    vector<Point> neighbors; // Adjacency list
};

int main() {
    srand(time(0)); // Seed for random generation of '-' and 'X'

    int width, height;
    cout << "Enter the width (number of columns) and height (number of rows) of the grid: ";
    cin >> width >> height;

    // Initialize 2D grid
    vector<vector<char>> grid(height, vector<char>(width));

    // Get Umer's position (U)
    int uRow, uCol;
    cout << "Enter Umer's position 'U' (row and col indices, 0-indexed): ";
    cin >> uRow >> uCol;

    // Get Home's position (H)
    int hRow, hCol;
    cout << "Enter Home's position 'H' (row and col indices, 0-indexed): ";
    cin >> hRow >> hCol;

    // Validate inputs
    if (uRow < 0 || uRow >= height || uCol < 0 || uCol >= width ||
        hRow < 0 || hRow >= height || hCol < 0 || hCol >= width) {
        cout << "Error: Positions are out of bounds!" << endl;
        return 1;
    }

    // Populate the grid randomly with '-' and 'X'
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (r == uRow && c == uCol) {
                grid[r][c] = 'U';
            } else if (r == hRow && c == hCol) {
                grid[r][c] = 'H';
            } else {
                // Randomly assign '-' (empty path, 75% chance) or 'X' (house/obstacle, 25% chance)
                grid[r][c] = (rand() % 4 == 0) ? 'X' : '-';
            }
        }
    }

    // Print the generated grid scenario
    cout << "\n--- Generated Grid Scenario ---" << endl;
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;

    // Map the grid scenario to an adjacency-list based Graph
    // Valid movements: Up, Down, Left, Right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    vector<vector<GraphNode>> graph(height, vector<GraphNode>(width));

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            graph[r][c].pos = {r, c};
            
            // If the current cell is an obstacle ('X'), it has no valid transitions/edges
            if (grid[r][c] == 'X') continue;

            // Connect to neighboring valid non-obstacle cells
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < height && nc >= 0 && nc < width) {
                    if (grid[nr][nc] != 'X') {
                        graph[r][c].neighbors.push_back({nr, nc});
                    }
                }
            }
        }
    }

    // BFS to find the shortest path from 'U' to 'H'
    queue<Point> q;
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    vector<vector<Point>> parent(height, vector<Point>(width, {-1, -1}));

    q.push({uRow, uCol});
    visited[uRow][uCol] = true;

    bool reachedHome = false;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.r == hRow && curr.c == hCol) {
            reachedHome = true;
            break;
        }

        // Traverse neighboring graph nodes
        for (const Point& neighbor : graph[curr.r][curr.c].neighbors) {
            if (!visited[neighbor.r][neighbor.c]) {
                visited[neighbor.r][neighbor.c] = true;
                parent[neighbor.r][neighbor.c] = curr;
                q.push(neighbor);
            }
        }
    }

    // Output the results
    if (reachedHome) {
        // Reconstruct the path from Home to Umer using parent pointers
        vector<Point> path;
        Point curr = {hRow, hCol};
        while (curr.r != -1 && curr.c != -1) {
            path.push_back(curr);
            curr = parent[curr.r][curr.c];
        }

        cout << "\nPath found! Coordinates along the route (from U to H):" << endl;
        int steps = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << "(" << path[i].r << ", " << path[i].c << ")";
            if (i > 0) cout << " -> ";
            steps++;
        }
        cout << "\nMinimum steps to get back home: " << steps - 1 << endl;
    } else {
        cout << "\nIt is not possible for Umer to return home." << endl;
        cout << "Minimum steps: -1" << endl;
    }

    return 0;
}



//test cases
/**/