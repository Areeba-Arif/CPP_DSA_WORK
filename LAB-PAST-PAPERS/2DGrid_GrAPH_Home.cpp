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
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int row, col, dist;
};

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<string> grid(rows);

    int sr, sc, er, ec;

    // Input grid
    for (int i = 0; i < rows; i++)
    {
        cin >> grid[i];

        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 'U')
            {
                sr = i;
                sc = j;
            }
            if (grid[i][j] == 'H')
            {
                er = i;
                ec = j;
            }
        }
    }

    queue<Node> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    q.push({sr, sc, 0});
    visited[sr][sc] = true;

    // Up, Down, Left, Right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        if (current.row == er && current.col == ec)
        {
            cout << current.dist << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = current.row + dr[i];
            int nc = current.col + dc[i];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                !visited[nr][nc] &&
                grid[nr][nc] != 'X')
            {
                visited[nr][nc] = true;
                q.push({nr, nc, current.dist + 1});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}