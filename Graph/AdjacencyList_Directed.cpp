#include <iostream>
using namespace std;

struct Vertex;
struct Edge;

struct Vertex {
    char data;
    Vertex* next;
    Edge* edgeList;
};

struct Edge {
    Vertex* dest;
    Edge* next;
};

Vertex* graph = NULL;

// ---------- Find Vertex ----------
Vertex* searchVertex(char key) {
    Vertex* temp = graph;
    while (temp) {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// ---------- Add Vertex ----------
void addVertex(char data) {
    if (searchVertex(data)) {
        cout << "Vertex already exists\n";
        return;
    }

    Vertex* v = new Vertex{data, NULL, NULL};

    if (!graph)
        graph = v;
    else {
        Vertex* temp = graph;
        while (temp->next)
            temp = temp->next;
        temp->next = v;
    }
}

// ---------- Add Edge (Directed, Unweighted) ----------
void addEdge(char v1, char v2) {
    Vertex* src = searchVertex(v1);
    Vertex* dest = searchVertex(v2);

    if (!src || !dest) {
        cout << "Vertex not found\n";
        return;
    }

       // check duplicate
    Edge* e = src->edgeList;
    while (e) {
        if (e->dest == dest) {
            cout << "Edge already exists\n";
            return;
        }
        e = e->next;
    }

    if(src!=nullptr && dest!=nullptr)
    {
        Edge* edge = new Edge;
        edge->dest = dest;
        edge->next = nullptr;

        if(src->edgeList == nullptr)
        {
            src->edgeList = edge;
        }
        else{
            Edge* currEdge = src->edgeList;
            while(currEdge -> next != nullptr)
            {
                currEdge = currEdge -> next;
            }

            currEdge -> next = edge;
        }
    }

 

}


// ---------- Remove Edge ----------
void removeEdge(char v1, char v2) {
    Vertex* src = searchVertex(v1);
    if (!src) return;

    Edge* curr = src->edgeList;
    Edge* prev = NULL;

    while (curr) {
        if (curr->dest->data == v2) {
            if (!prev) src->edgeList = curr->next;
            else prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// ---------- Remove Vertex ----------
void removeVertex(char key) {
    Vertex* curr = graph;
    Vertex* prev = NULL;

    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) return;

    // remove all incoming edges
    Vertex* temp = graph;
    while (temp) {
        removeEdge(temp->data, key);
        temp = temp->next;
    }

    // delete outgoing edges
    Edge* e = curr->edgeList;
    while (e) {
        Edge* t = e;
        e = e->next;
        delete t;
    }

    if (!prev) graph = curr->next;
    else prev->next = curr->next;

    delete curr;
}


// ---------- Print Neighbours ----------
void findNeighbours(char key) {
    Vertex* v = searchVertex(key);
    if (!v) {
        cout << "Vertex not found\n";
        return;
    }

    Edge* e = v->edgeList;
    if (!e) {
        cout << "NULL\n";
        return;
    }

    while (e) {
        cout << e->dest->data << " ";
        e = e->next;
    }
    cout << endl;
}


bool isAdjacent(char v1 , char v2)
{
    Vertex* src = searchVertex(v1);
    if(!src) return false;

    Edge* edge = src->edgeList;
    if(!edge) return false;
    while(edge)
    {
        if(edge->dest->data == v2)
        {
            return true;
        }
        edge = edge->next;
    }
    return false;
}

//----------PATH---------------

bool findPathUtil(Vertex* src, char dest, bool visited[])
{
    if(src->data == dest)
        return true;

    visited[src->data - 'A'] = true;

    Edge* e = src->edgeList;

    while(e)
    {
        if(!visited[e->dest->data - 'A'])
        {
            if(findPathUtil(e->dest, dest, visited))
                return true;
        }
        e = e->next;
    }

    return false;
}

bool findPath(char v1, char v2)
{
    Vertex* src = searchVertex(v1);
    if(!src) return false;

    bool visited[26] = {false};

    return findPathUtil(src, v2, visited);
}



bool isConnected(char v1, char v2)
{
    return findPath(v1, v2);
}


void DFS(Vertex* v, bool visited[])
{
    if (!v) return;

    visited[v->data - 'A'] = true;

    Edge* e = v->edgeList;

    while (e)
    {
        if (!visited[e->dest->data - 'A'])
        {
            DFS(e->dest, visited);
        }
        e = e->next;
    }
}

bool isGraphConnected()
{
    if(!graph) return true;

    bool visited[26] = {false};

    DFS(graph, visited);

    Vertex* temp = graph;
    while(temp)
    {
        if(!visited[temp->data - 'A'])
            return false;
        temp = temp->next;
    }

    return true;
}

/*While doing DFS:

visited[] = nodes we have seen before
recStack[] = nodes currently in recursion (path)

👉 If we visit a node that is already in recStack,
➡️ that means cycle exists*/
bool isCyclicUtil(Vertex* v, bool visited[], bool recStack[])
{
    visited[v->data - 'A'] = true;
    recStack[v->data - 'A'] = true;

    Edge* e = v->edgeList;

    while (e)
    {
        int idx = e->dest->data - 'A';

        if (!visited[idx])
        {
            if (isCyclicUtil(e->dest, visited, recStack))
                return true;
        }
        else if (recStack[idx])
        {
            return true; // cycle found
        }

        e = e->next;
    }

    recStack[v->data - 'A'] = false;
    return false;
}

bool isCyclic()
{
    bool visited[26] = {false};
    bool recStack[26] = {false};

    Vertex* temp = graph;

    while (temp)
    {
        int idx = temp->data - 'A';

        if (!visited[idx])
        {
            if (isCyclicUtil(temp, visited, recStack))
                return true;
        }

        temp = temp->next;
    }

    return false;
}




// ---------- Degree ----------
int findOutDegree(char key) {
    Vertex* v = searchVertex(key);
    if (!v) return 0;

    int count = 0;
    Edge* e = v->edgeList;

    while (e) {
        count++;
        e = e->next;
    }
    return count;
}

int findInDegree(char key) {
    int count = 0;
    Vertex* temp = graph;

    while (temp) {
        Edge* e = temp->edgeList;
        while (e) {
            if (e->dest->data == key)
                count++;
            e = e->next;
        }
        temp = temp->next;
    }
    return count;
}

int findTotalDegree(char key) {
    return findInDegree(key) + findOutDegree(key);
}


// ---------- Display ----------
void display() {
    Vertex* v = graph;

    while (v) {
        cout << v->data << " -> ";

        Edge* e = v->edgeList;
        if (!e) cout << "NULL";

        while (e) {
            cout << e->dest->data << " ";
            e = e->next;
        }
        cout << endl;

        v = v->next;
    }
}

// ---------- MAIN ----------
int main() {
    int choice;
    char v1, v2;

    do {
        cout << "\n===============================" << endl;
        cout << "      GRAPH MENU" << endl;
        cout << "===============================" << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Add Edge (Directed)" << endl;
        cout << "3. Remove Vertex" << endl;
        cout << "4. Remove Edge" << endl;
        cout << "5. Find Out-Degree" << endl;
        cout << "6. Find In-Degree" << endl;
        cout << "7. Find Total Degree" << endl;
        cout << "8. Find Neighbours" << endl;
        cout << "9. Check Path (Connectivity)" << endl;
        cout << "10. Check Adjacency" << endl;
        cout << "11. Display Graph" << endl;
        cout << "12. Check Cycle" << endl;
        cout << "0. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter vertex: ";
                cin >> v1;
                addVertex(v1);
                break;

            case 2:
                cout << "Enter source: ";
                cin >> v1;
                cout << "Enter destination: ";
                cin >> v2;
                addEdge(v1, v2);
                break;

            case 3:
                cout << "Enter vertex to remove: ";
                cin >> v1;
                removeVertex(v1);
                break;

            case 4:
                cout << "Enter source vertex: ";
                cin >> v1;
                cout << "Enter destination vertex: ";
                cin >> v2;
                removeEdge(v1, v2);
                break;

            case 5:
                cout << "Enter vertex: ";
                cin >> v1;
                cout << "Out-Degree: " << findOutDegree(v1) << endl;
                break;

            case 6:
                cout << "Enter vertex: ";
                cin >> v1;
                cout << "In-Degree: " << findInDegree(v1) << endl;
                break;

            case 7:
                cout << "Enter vertex: ";
                cin >> v1;
                cout << "Total Degree: " << findTotalDegree(v1) << endl;
                break;

            case 8:
                cout << "Enter vertex: ";
                cin >> v1;
                cout << "Neighbours: ";
                findNeighbours(v1);
                break;

            case 9:
                cout << "Enter source: ";
                cin >> v1;
                cout << "Enter destination: ";
                cin >> v2;
                if (isConnected(v1, v2))
                    cout << "Path EXISTS between " << v1 << " and " << v2 << endl;
                else
                    cout << "NO path exists" << endl;
                break;

            case 10:
                cout << "Enter v1: ";
                cin >> v1;
                cout << "Enter v2: ";
                cin >> v2;
                if (isAdjacent(v1, v2))
                    cout << "They are adjacent" << endl;
                else
                    cout << "Not adjacent" << endl;
                break;

            case 11:
                cout << "\n--- Graph ---" << endl;
                display();
                break;
            case 12:
                if (isCyclic())
                    cout << "Graph contains a cycle\n";
                else
                    cout << "No cycle found\n";
                break;

            

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}