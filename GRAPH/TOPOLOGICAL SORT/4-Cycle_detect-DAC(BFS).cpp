// 🔁 Cycle Detection in a Directed Graph (DAG Check) using BFS (Kahn’s Algorithm)
// If you’re using Kahn’s Algorithm (BFS-based topological sort), you can detect cycles in a directed graph by checking whether all nodes are processed or not.

// ✅ Key Idea:
// If a cycle exists, at least one node will never reach indegree = 0, so it will never be added to the queue.
// So, if the number of nodes added to the topological order is less than the total number of nodes (V) → the graph has a cycle.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to detect cycle using Kahn's Algorithm (BFS-based topological sort)
bool hasCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);       // Adjacency list representation of the graph
    vector<int> indegree(V, 0);       // Array to store in-degrees of all vertices

    // Build the graph and calculate in-degrees
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);          // Add edge from u -> v
        indegree[v]++;                // Increase in-degree of destination node
    }

    queue<int> q;                     // Queue for nodes with in-degree 0
    int count = 0;                    // Count of processed nodes

    // Push all nodes with in-degree 0 to the queue
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Process the nodes using BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;                      // Increment count of processed nodes

        // Decrease in-degree of all adjacent nodes
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);     // If in-degree becomes 0, add to queue
            }
        }
    }

    // If not all nodes were processed, a cycle exists
    return count != V;
}

int main() {
    int V = 4; // Number of vertices

    // List of directed edges (u -> v)
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}  // Creates a cycle: 1 → 2 → 3 → 1
    };

    // Check for cycle
    if (hasCycle(V, edges))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle found. It's a DAG.\n";

    return 0;
}
