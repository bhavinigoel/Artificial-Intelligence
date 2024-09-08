#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Function to perform BFS on a graph represented by an unordered_map
vector<char> BFS(const unordered_map<char, vector<char>>& graph, char start) {
    vector<char> visitedOrder;
    unordered_set<char> visited;
    queue<char> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        visitedOrder.push_back(node);

        for (char neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) { // If not visited
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    return visitedOrder;
}

int main() {
    // Graph represented as an adjacency list
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C', 'D'}},
        {'B', {'C', 'D', 'E', 'F'}},
        {'C', {'E', 'F', 'G'}},
        {'D', {'E', 'F', 'G', 'H'}},
        {'E', {'F', 'G', 'H'}},
        {'F', {'G', 'H'}},
        {'G', {'H', 'I', 'J'}},
        {'H', {'I', 'J'}},
        {'I', {}},
        {'J', {}}
    };

    char start = 'A';  // Starting node for BFS
    vector<char> result = BFS(graph, start);

    // Print nodes visited in order
    cout << "Nodes visited in order: ";
    for (char node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
