#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Function to perform BFS
vector<int> BFS(const vector<vector<int>>& graph, int start) {
    vector<int> visitedOrder;
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visitedOrder.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return visitedOrder;
}

// Function to perform DFS
vector<int> DFS(const vector<vector<int>>& graph, int start) {
    vector<int> visitedOrder;
    vector<bool> visited(graph.size(), false);
    stack<int> s;

    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        visitedOrder.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return visitedOrder;
}

int main() {
    int n, startNode, option;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    vector<vector<int>> graph(n);
    cout << "Enter the edges (enter -1 -1 to stop):\n";
    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming undirected graph
    }

    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "Enter the Search Method \n 1)Breadth First Search \n 2)Depth First Search \n ";
    cin >> option;

    vector<int> result;
    if (option == 1) {
        result = BFS(graph, startNode);
    } else if (option == 2) {
        result = DFS(graph, startNode);
    } else {
        cout << "Invalid option!" << endl;
        return 1;
    }

    cout << "Nodes visited in order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
