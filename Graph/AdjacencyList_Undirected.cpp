#include <iostream>
using namespace std;

struct Edge;

struct Vertex{
    char data;
    Vertex* vertexNext;
    Edge* edgeList;
};

struct Edge{
    Vertex* destination;
    Edge* edgeNext;
};

Vertex* graph = nullptr;

//search is vertex exist or not!

Vertex* searchVertex(char key)
{
    Vertex* temp = graph;
    while (temp)
    {
        if (temp->data == key) 
        {
            return temp; 
        }
        temp = temp->vertexNext;
    }
    return nullptr; 
}

// ---------- Add Vertex ----------
void addVertex(char data) {
    if (searchVertex(data)) {
        cout << "Vertex " << data << " already exists!" << endl;
        return;
    }

    Vertex* v = new Vertex;
    v->data = data;
    v->vertexNext = nullptr;
    v->edgeList = nullptr;

    if (!graph)
        graph = v;
    else {
        Vertex* temp = graph;
        while (temp->vertexNext)
            temp = temp->vertexNext;
        temp->vertexNext= v;
    }
}



// ---------- Add Edge ----------

void addEdge(char v1 , char v2)
{
    Vertex* source = searchVertex(v1);
    Vertex* destination = searchVertex(v2);

    if(!source || !destination)
    {
        cout<<"Vertex not found!"<<endl;
        return;
    }

    // check duplicate
    Edge* e = source->edgeList;
    while (e) {
        if (e->destination == destination) {
            cout << "Edge already exists\n";
            return;
        }
        e = e->edgeNext;
    }

    // ---------- Add edge source -> destination ----------
    Edge* edge1 = new Edge;
    edge1->destination = destination;
    edge1->edgeNext = nullptr;

    if(source->edgeList == nullptr)
    {
        source->edgeList = edge1;
    }
    else
    {
        Edge* curr = source->edgeList;
        while(curr->edgeNext)
        {
            curr = curr->edgeNext;
        }
        curr->edgeNext = edge1;
    }

    // ---------- Add edge destination -> source ----------
    Edge* edge2 = new Edge;
    edge2->destination = source;
    edge2->edgeNext = nullptr;

    if(destination->edgeList == nullptr)
    {
        destination->edgeList = edge2;
    }
    else
    {
        Edge* curr = destination->edgeList;
        while(curr->edgeNext)
        {
            curr = curr->edgeNext;
        }
        curr->edgeNext = edge2;
    }

    cout << "Edge added between " << v1 << " and " << v2 << endl;
}


// -------------------Remove edge-----------------------

void removeEdge(char v1, char v2)
{
    Vertex* source = searchVertex(v1);
    Vertex* dest = searchVertex(v2);

    if (!source || !dest)
    {
        cout << "Vertex not found!" << endl;
        return;
    }

    // ---------- remove v2 from v1 ----------
    Edge* curr = source->edgeList;
    Edge* prev = nullptr;

    while (curr)
    {
        if (curr->destination == dest)
        {
            if (prev == nullptr)
                source->edgeList = curr->edgeNext;
            else
                prev->edgeNext = curr->edgeNext;

            delete curr;
            break;
        }
        prev = curr;
        curr = curr->edgeNext;
    }

    // ---------- remove v1 from v2 ----------
    curr = dest->edgeList;
    prev = nullptr;

    while (curr)
    {
        if (curr->destination == source)
        {
            if (prev == nullptr)
                dest->edgeList = curr->edgeNext;
            else
                prev->edgeNext = curr->edgeNext;

            delete curr;
            break;
        }
        prev = curr;
        curr = curr->edgeNext;
    }

    cout << "Edge removed between " << v1 << " and " << v2 << endl;
}


//------------remove vertex------------------------------------------


void removeVertex(char key)
{
    Vertex* v = searchVertex(key);

    if (!v)
    {
        cout << "Vertex not found!" << endl;
        return;
    }

    // ---------- Step 1: Remove all edges pointing to this vertex ----------
    Vertex* temp = graph;

    while (temp)
    {
        if (temp != v)
        {
            Edge* curr = temp->edgeList;
            Edge* prev = nullptr;

            while (curr)
            {
                if (curr->destination == v)
                {
                    if (prev == nullptr)
                        temp->edgeList = curr->edgeNext;
                    else
                        prev->edgeNext = curr->edgeNext;

                    delete curr;
                    break;
                }

                prev = curr;
                curr = curr->edgeNext;
            }
        }

        temp = temp->vertexNext;
    }

    // ---------- Step 2: Delete its own edge list ----------
    Edge* e = v->edgeList;
    while (e)
    {
        Edge* next = e->edgeNext;
        delete e;
        e = next;
    }

    // ---------- Step 3: Remove vertex from vertex list ----------
    Vertex* currV = graph;
    Vertex* prevV = nullptr;

    while (currV)
    {
        if (currV == v)
        {
            if (prevV == nullptr)
                graph = currV->vertexNext;
            else
                prevV->vertexNext = currV->vertexNext;

            delete currV;
            break;
        }

        prevV = currV;
        currV = currV->vertexNext;
    }

    cout << "Vertex " << key << " removed successfully!" << endl;
}

//---------------degree---------------
int findDegree(char key)
{
    Vertex* v = searchVertex(key);

    if(!v) return 0;

    int count = 0;
    Edge* e = v->edgeList;

    while(e)
    {
        if(e->destination == v)
        {
            count+=2;
        }
        else
        {
            count+=1;
        }
        e = e->edgeNext;
    }

    return count;
}


//--------------- Display----------------------
void display() {
    Vertex* v = graph;
    if (!v) 
    {
         cout << "Graph is empty." << endl; return; 
    }
    
    cout << "\n--- Current Graph ---" << endl;
    while (v) {
        cout << v->data << " -> ";
        Edge* e = v->edgeList;
        if (!e)
        {
            cout << "NULL";
        } 
        while (e) {
            cout << e->destination->data << " ";
            e = e->edgeNext;
        }
        cout << endl;
        v = v->vertexNext;
    }
    cout << "---------------------" << endl;
}


// Main Menu
int main() {
    int choice;
    char v1, v2;

    while (true) {
        cout << "\n1. Add Vertex\n2. Add Edge\n3. Display Graph\n4. Find Degree\n5. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter vertex char: "; cin >> v1;
                addVertex(v1);
                break;
            case 2:
                cout << "Enter source: "; cin >> v1;
                cout << "Enter destination: "; cin >> v2;
                addEdge(v1, v2);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Enter vertex to find degree: "; cin >> v1;
                cout << "Degree of " << v1 << ": " << findDegree(v1) << endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}