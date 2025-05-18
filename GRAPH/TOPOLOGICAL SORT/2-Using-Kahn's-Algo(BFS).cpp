// Kahn's algorithm is an iterative method for topological sorting. It works by repeatedly removing nodes with in-degree = 0 (no incoming edges) and updating the in-degrees of their neighbors.

// 🧠 Steps of Kahn's Algorithm
// Calculate in-degrees of all vertices.
// Push all nodes with in-degree 0 into a queue.
// While the queue is not empty:
// Pop a node, add it to the topological order.
// Reduce the in-degree of its neighbors by 1.
// If any neighbor’s in-degree becomes 0, push it to the queue.
// If the result has all V nodes, it’s a valid topological order.
// Otherwise, a cycle exists (and topological sort is not possible).

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform Topological Sort using Kahn's Algorithm (BFS)
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);       // Adjacency list to represent the graph
    vector<int> indegree(V, 0);       // Array to store in-degrees of all vertices

    // Build the graph (adjacency list) and compute in-degrees
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);          // Edge from u -> v
        indegree[v]++;                // Increment in-degree of destination vertex
    }

    queue<int> q;                     // Queue to store vertices with in-degree 0
    vector<int> result;              // Vector to store topological order

    // Push all vertices with in-degree 0 into the queue
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Process nodes with in-degree 0 and reduce in-degrees of neighbors
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);       // Add current node to topological order

        // Reduce the in-degree of all adjacent vertices
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);     // If in-degree becomes 0, add to queue
            }
        }
    }

    // If result contains all vertices, a valid topological sort exists
    if (result.size() != V) {
        cout << "Cycle detected! Topological sort not possible.\n";
        return {};
    }

    return result; // Return the topological sort order
}

int main() {
    int V = 6; // Number of vertices

    // List of directed edges: each pair represents an edge from edge[0] to edge[1]
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };

    // Get topological sort order
    vector<int> topoOrder = topoSort(V, edges);

    // Print the result
    cout << "Topological Sort (Kahn's Algorithm): ";
    for (int node : topoOrder) {
        cout << node << " ";
    }

    return 0;
}



// Time Complexity (TC)
// Building adjacency list and indegree array:
// Iterates over all edges once → O(E)

// Processing nodes with in-degree 0:
// Each node is pushed and popped from the queue once → O(V)
// Each edge is checked exactly once when decreasing in-degree → O(E)

// Total time complexity:
// O(V + E)

// Space Complexity (SC)
// Adjacency list: Stores all edges → O(V + E)

// Indegree array: Stores indegree for each vertex → O(V)

// Queue: Stores nodes with in-degree zero (max size O(V)) → O(V)

// Result vector: Stores all vertices in topological order → O(V)

// Total space complexity:
// O(V + E)

