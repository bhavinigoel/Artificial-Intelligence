#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
    int V; 
    list<int> *adj; 
  
    bool DLS(int v, int target, int limit, vector<int>& path, vector<bool>& visited); 
  
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
    bool IDDFS(int v, int target, int max_depth); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
  
bool Graph::DLS(int src, int target, int limit, vector<int>& path, vector<bool>& visited) 
{ 
    path.push_back(src);
    visited[src] = true;

    if (src == target) 
    { 
        cout << "Path to target: ";
        for (int node : path) 
            cout << node << " ";
        cout << endl;
        return true; 
    }
  
    if (limit <= 0) 
    {
        path.pop_back();
        visited[src] = false;
        return false;
    }

    bool found = false;
    for (auto i = adj[src].begin(); i != adj[src].end(); ++i) 
    {
        if (!visited[*i]) 
        {
            if (DLS(*i, target, limit-1, path, visited)) 
            {
                found = true;
                break;
            }
        }
    }

    path.pop_back();
    visited[src] = false;

    return found;
} 
  
bool Graph::IDDFS(int src, int target, int max_depth) 
{ 
    vector<int> path; 
    vector<bool> visited(V, false); 
  
    for (int i = 1; i <= max_depth; i++) 
    {
        if (DLS(src, target, i, path, visited) == true) 
            return true;
    }
  
    return false;
} 
  
int main() 
{ 
    Graph g(21);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 9);
    g.addEdge(6, 10);
    g.addEdge(7, 11);
    g.addEdge(8, 12);
    g.addEdge(9, 13);
    g.addEdge(10, 14);
    g.addEdge(11, 15);
    g.addEdge(12, 16);
    g.addEdge(13, 17);
    g.addEdge(14, 18);
    g.addEdge(15, 19);
    g.addEdge(16, 20);

    int target = 20;
    int maxDepth = 3;
    int src = 0;
    
    if (g.IDDFS(src, target, maxDepth) == true) 
        cout << "Target is reachable from source within max depth"; 
    else
        cout << "Target is NOT reachable from source within max depth"; 
    
    return 0; 
}
