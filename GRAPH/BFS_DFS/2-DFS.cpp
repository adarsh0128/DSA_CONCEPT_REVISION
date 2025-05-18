// ✅ What is DFS?
// Depth-First Search is a graph traversal technique that goes deep into a branch before backtracking.
// It uses recursion or an explicit stack.

// Use Case	Why DFS?
// File System Traversal	Goes deep into folder structure
// Solving Puzzles (like mazes)	Explore all paths before backtracking

#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS function
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& result) {
    vis[node] = 1;               // Mark current node as visited
    result.push_back(node);      // Add node to traversal result

    // Visit all unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, adj, vis, result);
        }
    }
}

// DFS traversal of a connected graph starting from node 0
vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);       // Visited array
    vector<int> result;          // Stores the DFS traversal

    dfs(0, adj, vis, result);    // Start DFS from node 0

    return result;
}

int main() {
    int V = 5;  // Number of vertices

    // Adjacency list for the graph
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Perform DFS
    vector<int> result = dfsOfGraph(V, adj);

    // Output the DFS traversal
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

// 🧮 Time & Space Complexity
// Time Complexity: O(V + E)
// Each vertex and edge is visited once.

// Space Complexity:
// Visited array → O(V)
// Recursive call stack → up to O(V)
// Adjacency list (input) → O(V + E)
// So, total SC = O(V + E)

// Goal / Problem	Use
// Shortest path (unweighted graph)	✅ BFS
// Path existence, full exploration	✅ DFS
// Cycle detection (Directed graph)	✅ DFS
// Topological sorting (DAG)	✅ DFS (or Kahn's)
// Space optimization (less memory needed)	✅ DFS
// Level-wise node traversal	✅ BFS