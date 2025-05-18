// Key Idea:
// When doing DFS on an undirected graph, if you visit a neighbor that is already visited and is NOT the parent of the current node, it means there is a cycle.

// Explanation:
// We run DFS from each unvisited node.
// While exploring neighbors, if a neighbor is already visited and not the parent node, it means a back-edge exists → cycle.
// If no such back-edge is found, the graph is acyclic.

#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect cycle in an undirected graph
bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;  // Mark current node as visited

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            // Visit the neighbor recursively
            if (dfs(neighbor, node, adj, visited))
                return true;  // Cycle found in subtree
        } else if (neighbor != parent) {
            // If neighbor is visited and not parent, cycle detected
            return true;
        }
    }
    return false;
}

// Function to check cycle in an undirected graph
bool hasCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> visited(V, 0);

    // Build adjacency list
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph: add both ways
    }

    // Check for cycle in all connected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;  // No cycle found
}

int main() {
    int V = 5;

    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}  // This contains a cycle
    };

    if (hasCycle(V, edges))
        cout << "Cycle detected in the undirected graph.\n";
    else
        cout << "No cycle found. The graph is acyclic.\n";

    return 0;
}

// Time Complexity:
// Building adjacency list: O(E)

// DFS traversal (each node and edge visited once): O(V + E)

// Space Complexity:
// Adjacency list: O(V + E)

// Visited array: O(V)

// Call stack (DFS recursion): up to O(V)