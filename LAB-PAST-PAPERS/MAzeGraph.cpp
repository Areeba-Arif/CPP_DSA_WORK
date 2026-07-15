/*
The question is asking you to:

Take an n × m matrix as input.
Fill it randomly with 0 and 1.
0 = path (mouse can move)
1 = blocked cell
Convert the maze into a Graph using Adjacency List.
Use Breadth First Search (BFS) to find the path from (0,0) to (n-1,m-1).
Mouse can move in 8 directions (up, down, left, right, and diagonals).
Print the path as (row,column) indexes.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;

struct Node
{
    int x, y;
};

int main()
{
    srand(time(0));

    int n, m;
    cout << "Enter rows: ";
    cin >> n;
    cout << "Enter columns: ";
    cin >> m;

    vector<vector<int>> maze(n, vector<int>(m));

    // Fill maze randomly
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            maze[i][j]=rand()%2;
        }
    }

    // Start and End must be open
    maze[0][0]=0;
    maze[n-1][m-1]=0;

    cout<<"\nMaze:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }

    // Adjacency List
    vector<vector<int>> adj(n*m);

    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};


    //Build graph
    // Visit every cell of the maze
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        // Skip blocked cells (1)
        if(maze[i][j]==1)
            continue;

        // Convert (row,column) into graph node number
        int u=i*m+j;

        // Check all 8 possible directions
        for(int k=0;k<8;k++)
        {
            // Find neighbour coordinates
            int ni=i+dx[k];
            int nj=j+dy[k];

            // If neighbour is inside the maze and is an open path
            if(ni>=0 && ni<n && nj>=0 && nj<m && maze[ni][nj]==0)
            {
                // Convert neighbour into graph node
                int v=ni*m+nj;

                // Add an edge from current node to neighbour
                adj[u].push_back(v);
            }
        }
    }
}

    // Parent array stores from which node we reached the current node
    vector<int> parent(n*m,-1);

    // Keeps track of visited nodes
    vector<bool> visited(n*m,false);

    // Queue is used for BFS traversal
    queue<int> q;

    // Start node (0,0) and destination node (last cell)
    int start=0;
    int goal=n*m-1;

    // Start BFS from the starting node
    q.push(start);
    visited[start]=true;

    // Continue until queue becomes empty
    while(!q.empty())
    {
        // Take the front node from the queue
        int u=q.front();
        q.pop();

        // Stop if destination is reached
        if(u==goal)
            break;

        // Visit all neighbouring nodes
        for(int v:adj[u])
        {
            // Process only unvisited neighbours
            if(!visited[v])
            {
                visited[v]=true; // Mark as visited
                parent[v]=u;     // Save parent for path reconstruction
                q.push(v);       // Add neighbour to queue
            }
        }
    }

    // If destination was never visited, no path exists
    if(!visited[goal])
    {
        cout<<"No Path Found!";
        return 0;
    }

    // Reconstruct the path from destination back to start
    vector<int> path;

    for(int v=goal;v!=-1;v=parent[v])
        path.push_back(v);

    // Print path in correct order
    for(int i=path.size()-1;i>=0;i--)
    {
        // Convert node number back into (row,column)
        int r=path[i]/m;
        int c=path[i]%m;

        cout<<"("<<r<<","<<c<<") ";

        if(i!=0)
            cout<<" -> ";
    }

    cout<<endl;

    return 0;
}




/*
Input n and m
        ↓
Generate random maze (0 & 1)
        ↓
Keep start/end open
        ↓
Convert every 0 cell into a graph node
        ↓
Connect all valid 8-direction neighbours
        ↓
Run BFS from (0,0)
        ↓
Store parent of every visited node
        ↓
Reach destination?
      /      \
    Yes       No
     |         |
Print path   Print "No Path Found"
*/