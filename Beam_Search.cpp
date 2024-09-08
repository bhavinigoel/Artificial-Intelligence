#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define the number of vertices
const int v = 10;
vector<pair<int, int>> graph[v];

// Node structure to hold information about each node
struct Node
{
    int cost, vertex;
    vector<int> path;
};

// Custom comparator functor for the priority queue
struct CompareNodes
{
    bool operator()(Node const &a, Node const &b)
    {
        return a.cost > b.cost;
    }
};

// Beam Search Function
void beamSearch(int source, int target, int beam_width = 2)
{
    vector<bool> visited(v, false);

    // Using the custom comparator in the priority queue
    priority_queue<Node, vector<Node>, CompareNodes> pq;

    // Push the source node into the priority queue
    pq.push({0, source, {source}});
    visited[source] = true;

    while (!pq.empty())
    {
        vector<Node> next_level;

        for (int i = 0; i < beam_width && !pq.empty(); ++i)
        {
            Node current = pq.top();
            pq.pop();

            int u = current.vertex;
            if (u == target)
            {
                cout << "\nPath: ";
                for (int node : current.path)
                {
                    cout << node << " ";
                }
                cout << endl;
                return;
            }

            // Explore the neighbors of the current node
            for (auto &neighbor : graph[u])
            {
                int v = neighbor.first;
                int cost = neighbor.second;

                if (!visited[v])
                {
                    visited[v] = true;
                    vector<int> new_path = current.path;
                    new_path.push_back(v);
                    next_level.push_back({current.cost + cost, v, new_path});
                }
            }
        }

        // Push the next level nodes into the priority queue
        for (auto &node : next_level)
        {
            pq.push(node);
        }
    }

    cout << "Target not reachable" << endl;
}

// Function to add an edge to the graph
void addedge(int x, int y, int cost)
{
    graph[x].emplace_back(y, cost);
    graph[y].emplace_back(x, cost);
}

// Main function
int main()
{
    // Adding edges
    addedge(0, 2, 3);
    addedge(0, 1, 6);
    addedge(0, 3, 1);

    addedge(1, 2, 2);
    addedge(1, 3, 6);
    addedge(1, 4, 3);
    addedge(1, 5, 4);

    addedge(2, 4, 4);
    addedge(2, 5, 5);

    addedge(3, 4, 4);
    addedge(3, 5, 7);
    addedge(3, 7, 9);

    addedge(4, 5, 8);
    addedge(4, 6, 9);

    addedge(5, 6, 8);
    addedge(5, 7, 9);

    addedge(6, 7, 9);
    addedge(6, 8, 11);
    addedge(6, 9, 12);

    addedge(7, 8, 14);
    addedge(7, 9, 15);

    addedge(8, 9, 15);

    int source = 0;
    int target = 9;
    beamSearch(source, target, 2);

    return 0;
}
