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

struct Q_Node
{
    Vertex* data;
    Q_Node* qnext;   
};


Vertex* graph = NULL;
Q_Node* front= nullptr;
Q_Node* rear= nullptr;



// ---------- Find Vertex ----------
Vertex* searchVertex(char key) {
    Vertex* temp = graph;
    while (temp) {
        if (temp->data == key)
            return temp;
        temp = temp->vertexNext;
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
        while (temp->vertexNext)
            temp = temp->vertexNext;
        temp->vertexNext = v;
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
        if (e->destination == dest) {
            cout << "Edge already exists\n";
            return;
        }
        e = e->edgeNext;
    }

    if(src!=nullptr && dest!=nullptr)
    {
        Edge* edge = new Edge;
        edge->destination = dest;
        edge->edgeNext = nullptr;

        if(src->edgeList == nullptr)b
        {
            src->edgeList = edge;
        }
        else{
            Edge* currEdge = src->edgeList;
            while(currEdge ->edgeNext != nullptr)
            {
                currEdge = currEdge -> edgeNext;
            }

            currEdge ->edgeNext = edge;
        }
    }

 

}


void enqueue(Vertex* v)
{
    Q_Node* temp = new Q_Node;
    temp->data = v;
    temp->qnext = nullptr;

    if (rear == nullptr)
    {
        front = rear = temp;
    }
    else
    {
        rear->qnext = temp;
        rear = temp;
    }
}

Vertex* dequeue()
{
    if (front == nullptr)
        return nullptr;

    Q_Node* temp = front;
    Vertex* v = temp->data;

    front = front->qnext;
    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return v;
}

bool isEmpty()
{
    return front == nullptr;
}

void BFS(Vertex* start)
{
    // Mark all nodes unvisited (IMPORTANT in real questions)
    Vertex* temp = graph;
    while (temp != nullptr)
    {
        temp->visited = false;
        temp = temp->vertexNext;
    }

    // Start BFS
    start->visited = true;
    enqueue(start);

    while (!isEmpty())
    {
        Vertex* current = dequeue();
        cout << current->data << " ";

        Edge* e = current->edgeList;
        while (e != nullptr)
        {
            if (!e->destination->visited)
            {
                e->destination->visited = true;
                enqueue(e->destination);
            }
            e = e->edgeNext;
        }
    }
}


int main() 
{
    // ---------- Add Vertices ----------
    addVertex('0');
    addVertex('1');
    addVertex('2');
    addVertex('3');
    addVertex('4');
    addVertex('5');
    addVertex('6');

    // ---------- Add Edges ----------
    addEdge('0', '1');
    addEdge('0', '2');
    addEdge('0', '3');
    addEdge('2', '4');
    addEdge('4', '5');
    addEdge('4', '6');

    // ---------- Run BFS ----------
    Vertex* start = searchVertex('4');

    if (start != NULL)
    {
        cout << "BFS Traversal: ";
        BFS(start);
    }
    else
    {
        cout << "Start vertex not found\n";
    }

    return 0;
}