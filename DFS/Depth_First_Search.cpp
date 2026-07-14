#include <iostream>
using namespace std;

struct Edge;
struct Vertex
{
    char data;
    Edge* edgeList;
    Vertex* vertexNext;
    bool visited;
};

struct Edge
{
    Vertex* destination;
    Edge* edgeNext;
};

struct S_Node
{
    Vertex* data;
    S_Node* next;
};

Vertex* graph = NULL;
S_Node* top = nullptr;

// ---------- Find Vertex ----------
Vertex* searchVertex(char key)
{
    Vertex* temp = graph;
    while (temp)
    {
        if (temp->data == key)
            return temp;
        temp = temp->vertexNext;
    }
    return NULL;
}

// ---------- Add Vertex ----------
void addVertex(char data)
{
    if (searchVertex(data))
    {
        cout << "Vertex already exists\n";
        return;
    }

    Vertex* v = new Vertex;
    v->data = data;
    v->edgeList = NULL;
    v->vertexNext = NULL;
    v->visited = false;

    if (!graph)
        graph = v;
    else
    {
        Vertex* temp = graph;
        while (temp->vertexNext)
            temp = temp->vertexNext;
        temp->vertexNext = v;
    }
}

// ---------- Add Edge ----------
void addEdge(char v1, char v2)
{
    Vertex* src = searchVertex(v1);
    Vertex* dest = searchVertex(v2);

    if (!src || !dest)
    {
        cout << "Vertex not found\n";
        return;
    }

    Edge* e = src->edgeList;
    while (e)
    {
        if (e->destination == dest)
        {
            cout << "Edge already exists\n";
            return;
        }
        e = e->edgeNext;
    }

    Edge* edge = new Edge;
    edge->destination = dest;
    edge->edgeNext = NULL;

    if (!src->edgeList)
        src->edgeList = edge;
    else
    {
        Edge* curr = src->edgeList;
        while (curr->edgeNext)
            curr = curr->edgeNext;
        curr->edgeNext = edge;
    }
}

// ---------- Stack Operations ----------
void push(Vertex* v)
{
    S_Node* temp = new S_Node;
    temp->data = v;
    temp->next = top;
    top = temp;
}

Vertex* pop()
{
    if (!top)
        return NULL;

    S_Node* temp = top;
    Vertex* v = temp->data;

    top = top->next;
    delete temp;

    return v;
}

bool isStackEmpty()
{
    return top == NULL;
}

// ---------- DFS (Stack) ----------
void DFS_Stack(Vertex* start)
{
    Vertex* temp = graph;
    while (temp)
    {
        temp->visited = false;
        temp = temp->vertexNext;
    }

    push(start);

    while (!isStackEmpty())
    {
        Vertex* current = pop();

        if (!current->visited)
        {
            current->visited = true;
            cout << current->data << " ";

            Edge* e = current->edgeList;
            while (e)
            {
                if (!e->destination->visited)
                    push(e->destination);

                e = e->edgeNext;
            }
        }
    }
}


/*// ---------- DFS (Recursive - Backtracking Style) ----------

void resetVisited()
{
    Vertex* temp = graph;
    while (temp)
    {
        temp->visited = false;
        temp = temp->vertexNext;
    }
}

void DFS_Recursive(Vertex* node)
{
    if (node == NULL)
        return;

    // mark visited
    node->visited = true;

    // print current node
    cout << node->data << " ";

    // go to neighbors ONE BY ONE (your thinking)
    Edge* e = node->edgeList;
    while (e)
    {
        if (!e->destination->visited)
        {
            // go deep first
            DFS_Recursive(e->destination);
        }
        e = e->edgeNext;
    }
}*/

// ---------- MAIN ----------
int main()
{
    addVertex('0');
    addVertex('1');
    addVertex('2');
    addVertex('3');
    addVertex('4');
    addVertex('5');
    addVertex('6');
    addVertex('7');

    addEdge('0', '1');
    addEdge('0', '2');
    addEdge('0', '3');
    addEdge('1', '4');
    addEdge('1', '5');
    addEdge('2', '6');
    addEdge('3', '7');

    Vertex* start = searchVertex('0');

    if (start)
    {
        cout << "DFS Traversal: ";
        DFS_Stack(start);
    }
    else
    {
        cout << "Start vertex not found\n";
    }

    return 0;
}