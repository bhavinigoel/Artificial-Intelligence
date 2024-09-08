#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<int> BestFirstSearch(const vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> visitedOrder;
    vector<bool> visited(graph.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    visited[start] = true;

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        visitedOrder.push_back(node);

        for (const auto& neighbor : graph[node]) {
            int cost = neighbor.first;
            int nextNode = neighbor.second;
            if (!visited[nextNode]) {
                pq.push({cost, nextNode});
                visited[nextNode] = true;
            }
        }
    }

    return visitedOrder;
}

int main() {
    int n, startNode;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter the edges with costs (enter -1 -1 -1 to stop):\n";
    while (true) {
        int u, v, cost;
        cin >> u >> v >> cost;
        if (u == -1 && v == -1 && cost == -1) break;
        graph[u].push_back({cost, v});
        graph[v].push_back({cost, u}); // Assuming undirected graph
    }

    cout << "Enter the starting node: ";
    cin >> startNode;

    vector<int> result = BestFirstSearch(graph, startNode);

    cout << "Nodes visited in order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
