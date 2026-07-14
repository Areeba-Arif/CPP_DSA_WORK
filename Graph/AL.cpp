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

    Edge* newEdge = new Edge{dest, src->edgeList};
    src->edgeList = newEdge;
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

// ---------- DFS ----------
void DFS(Vertex* v, bool visited[]) {
    visited[v->data - 'A'] = true;

    Edge* e = v->edgeList;
    while (e) {
        int idx = e->dest->data - 'A';
        if (!visited[idx])
            DFS(e->dest, visited);
        e = e->next;
    }
}

// ---------- Path Exists ----------
bool pathExists(char v1, char v2) {
    bool visited[26] = {false};

    Vertex* start = searchVertex(v1);
    if (!start) return false;

    DFS(start, visited);
    return visited[v2 - 'A'];
}

// ---------- Cycle Detection (Directed) ----------
bool cycleUtil(Vertex* v, bool visited[], bool rec[]) {
    int idx = v->data - 'A';

    visited[idx] = true;
    rec[idx] = true;

    Edge* e = v->edgeList;
    while (e) {
        int d = e->dest->data - 'A';

        if (!visited[d] && cycleUtil(e->dest, visited, rec))
            return true;
        else if (rec[d])
            return true;

        e = e->next;
    }

    rec[idx] = false;
    return false;
}

bool isCyclic() {
    bool visited[26] = {false};
    bool rec[26] = {false};

    Vertex* temp = graph;

    while (temp) {
        int idx = temp->data - 'A';
        if (!visited[idx]) {
            if (cycleUtil(temp, visited, rec))
                return true;
        }
        temp = temp->next;
    }
    return false;
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
        cout << "\n--- MENU ---\n";
        cout << "1 Add Vertex\n2 Add Edge\n3 Remove Vertex\n4 Remove Edge\n";
        cout << "5 Neighbours\n6 OutDegree\n7 InDegree\n8 Path Exists\n";
        cout << "9 Cycle Check\n10 Display\n0 Exit\n";

        cin >> choice;

        switch (choice) {
            case 1:
                cin >> v1;
                addVertex(v1);
                break;

            case 2:
                cin >> v1 >> v2;
                addEdge(v1, v2);
                break;

            case 3:
                cin >> v1;
                removeVertex(v1);
                break;

            case 4:
                cin >> v1 >> v2;
                removeEdge(v1, v2);
                break;

            case 5:
                cin >> v1;
                findNeighbours(v1);
                break;

            case 6:
                cin >> v1;
                cout << findOutDegree(v1) << endl;
                break;

            case 7:
                cin >> v1;
                cout << findInDegree(v1) << endl;
                break;

            case 8:
                cin >> v1 >> v2;
                cout << (pathExists(v1, v2) ? "Yes\n" : "No\n");
                break;

            case 9:
                cout << (isCyclic() ? "Cyclic\n" : "Acyclic\n");
                break;

            case 10:
                display();
                break;
        }

    } while (choice != 0);

    return 0;
}