#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Function to perform beam search
vector<int> beamSearch(const vector<vector<int>>& graph, int start, int goal, int beamWidth, bool isLevelWidth) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<vector<int>> q;
    q.push({start});
    visited[start] = true;

    while (!q.empty()) {
        vector<vector<int>> levelNodes;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            vector<int> path = q.front();
            q.pop();
            int node = path.back();

            // Goal node found, return the path
            if (node == goal) {
                return path;
            }

            // Explore neighbors
            for (int neighbor = 0; neighbor < n; ++neighbor) {
                if (graph[node][neighbor] && !visited[neighbor]) {
                    vector<int> newPath = path;
                    newPath.push_back(neighbor);
                    levelNodes.push_back(newPath);
                }
            }
        }

        // Sort the level nodes based on the path length
        sort(levelNodes.begin(), levelNodes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a.size() < b.size();
        });

        // Adjust width for level and node cases
        int width = isLevelWidth ? beamWidth : min(beamWidth, (int)levelNodes.size());

        for (int i = 0; i < width; ++i) {
            q.push(levelNodes[i]);
            visited[levelNodes[i].back()] = true;
        }
    }

    // Return empty path if goal is not found
    return {};
}

// Function to test beam search with different width configurations
void testBeamSearch(const vector<vector<int>>& graph, int start, int goal, const string& graphName) {
    vector<int> widths = {1, 2, 3};

    cout << "Testing on " << graphName << ":" << endl;
    for (int w : widths) {
        cout << "Testing with beam width (level), Wl=" << w << endl;
        vector<int> result = beamSearch(graph, start, goal, w, true);
        if (!result.empty()) {
            cout << "Path found: ";
            for (int node : result) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            cout << "No path found" << endl;
        }

        cout << "Testing with beam width (node), Wn=" << w << endl;
        result = beamSearch(graph, start, goal, w, false);
        if (!result.empty()) {
            cout << "Path found: ";
            for (int node : result) {
                cout << node << " ";
            }
            cout << endl;
        } else {
            cout << "No path found" << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph10 = {
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}
    };

    vector<vector<int>> graph12 = {
        {0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
    };

    testBeamSearch(graph10, 0, 9, "10-node graph");
    testBeamSearch(graph12, 0, 11, "12-node graph");

    return 0;
}
