#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* adj; // adjacency list now holds pairs of (node, weight)

    bool DLS(int v, int target, int limit, vector<int>& path, vector<bool>& visited);

public:
    Graph(int V);
    void addEdge(int v, int w, int weight);
    bool IDDFS(int v, int target, int max_depth);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int>>[V]; // list of pairs to hold node and weight
}

void Graph::addEdge(int v, int w, int weight) {
    adj[v].push_back(make_pair(w, weight)); // push (node, weight) pair
}

bool Graph::DLS(int src, int target, int limit, vector<int>& path, vector<bool>& visited) {
    path.push_back(src);
    visited[src] = true;

    if (src == target) {
        cout << "Path to target: ";
        for (int node : path)
            cout << node << " ";
        cout << endl;
        return true;
    }

    if (limit <= 0) {
        path.pop_back();
        visited[src] = false;
        return false;
    }

    // Use priority queue to explore best node first based on edge weights
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto i = adj[src].begin(); i != adj[src].end(); ++i) {
        if (!visited[i->first]) {
            pq.push(*i); // push (node, weight) pair to priority queue
        }
    }

    bool found = false;
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        if (DLS(p.first, target, limit - 1, path, visited)) {
            found = true;
            break;
        }
    }

    path.pop_back();
    visited[src] = false;

    return found;
}

bool Graph::IDDFS(int src, int target, int max_depth) {
    vector<int> path;
    vector<bool> visited(V, false);

    for (int i = 1; i <= max_depth; i++) {
        if (DLS(src, target, i, path, visited) == true)
            return true;
    }

    return false;
}

int main() {
    Graph g(10); // Adjusted size for the graph

    g.addEdge(0, 2, 3);
    g.addEdge(0, 1, 6);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 4, 3);
    g.addEdge(1, 5, 4);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 5);
    g.addEdge(3, 4, 4);
    g.addEdge(3, 5, 7);
    g.addEdge(3, 7, 9);
    g.addEdge(4, 5, 8);
    g.addEdge(4, 6, 9);
    g.addEdge(5, 6, 8);
    g.addEdge(5, 7, 9);
    g.addEdge(6, 7, 9);
    g.addEdge(6, 8, 11);
    g.addEdge(6, 9, 12);
    g.addEdge(7, 8, 14);
    g.addEdge(7, 9, 15);
    g.addEdge(8, 9, 15);

    int target = 9;
    int maxDepth = 3;
    int src = 0;

    if (g.IDDFS(src, target, maxDepth) == true)
        cout << "Target is reachable from source within max depth";
    else
        cout << "Target is NOT reachable from source within max depth";

    return 0;
}
