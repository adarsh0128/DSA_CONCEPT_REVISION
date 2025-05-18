// 🔁 Cycle Detection in Directed Graph using DFS
// When detecting cycles in a directed graph (DAG check) using DFS, the key idea is to track recursion stack (i.e., the current path of DFS). If during traversal we revisit a node that’s already on the current recursion path, a cycle exists.

#include <iostream>
#include <vector>
using namespace std;

// DFS function to detect a cycle
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsVis) {
    vis[node] = 1;       // Mark node as visited
    dfsVis[node] = 1;    // Mark node as part of current DFS path

    // Visit all neighbors
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            // If neighbor not visited, recur
            if (dfs(neighbor, adj, vis, dfsVis))
                return true;
        } else if (dfsVis[neighbor]) {
            // If neighbor is in current DFS path → cycle
            return true;
        }
    }

    dfsVis[node] = 0;    // Backtrack: remove from current DFS path
    return false;
}

// Main function to check for cycle in a directed graph
bool hasCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);      // Adjacency list
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);         // Directed edge from u -> v
    }

    vector<int> vis(V, 0), dfsVis(V, 0);  // Visited and recursion stack arrays

    // Call DFS from every unvisited node
    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, dfsVis))
                return true;  // Cycle detected
        }
    }

    return false;  // No cycle found
}

int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}  // Creates a cycle: 1 → 2 → 3 → 1
    };

    if (hasCycle(V, edges))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle found. It's a DAG.\n";

    return 0;
}
