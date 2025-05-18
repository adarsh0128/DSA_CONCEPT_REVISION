// Topological Sorting is an ordering of the vertices of a Directed Acyclic Graph (DAG) such that for every directed edge u → v, vertex u comes before v in the ordering.

// 🔧 When is it Used?
// Task scheduling (e.g., prerequisites)
// Compilation order of files
// Dependency resolution

// ✅ Key Properties
// Only for DAGs (Directed Acyclic Graphs)
// May not be unique (can be multiple valid topological orders)

// 🧠 Algorithms to Perform Topological Sort
// 1. DFS-Based Approach (using recursion and a stack)
// Logic:
// Start DFS from each unvisited node.
// After visiting all descendants, push the node onto a stack.
// When all nodes are processed, pop from stack to get topological order.


// Topological sort is used when you need to process tasks in a specific order, based on dependencies. It applies only to Directed Acyclic Graphs (DAGs).



#include <bits/stdc++.h>
using namespace std;

// Global adjacency list to represent the graph
unordered_map<int, vector<int>> adj;

// DFS function to perform topological sort
void f(int node, vector<int>& vis, stack<int>& st) {
    vis[node] = 1; // Mark the current node as visited

    // Visit all unvisited adjacent nodes
    for (auto it : adj[node]) {
        if (!vis[it]) {
            f(it, vis, st); // Recursive DFS call
        }
    }

    st.push(node); // Push the node to stack after visiting all descendants
}

// Main function to perform topological sort
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // Build the adjacency list from edges
    for (auto it : edges) {
        int x = it[0], y = it[1];
        adj[x].push_back(y); // Directed edge from x to y
    }

    stack<int> st;           // Stack to store the topological order
    vector<int> vis(V, 0);   // Visited array to keep track of visited nodes

    // Call DFS for each unvisited node
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            f(i, vis, st);
        }
    }

    // Extract topological order from the stack
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans; // Return the final topological order
}

int main(){
   int V = 6;
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };

    vector<int> topoOrder = topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }

    return 0;
}


// Time Complexity (TC)
// Building adjacency list:
// Iterates over all edges once → O(E)

// DFS traversal:
// Each vertex is visited once → O(V)
// For each vertex, all its adjacent edges are explored once → O(E)

// Total time complexity:
// O(V + E)

// Space Complexity (SC)
// Adjacency list: Stores all edges → O(V + E)

// Visited array: Stores visited status for each node → O(V)

// Call stack for DFS recursion: In worst case, recursion depth can be O(V) → O(V)

// Stack to store topological order: Stores all nodes → O(V)

// Total space complexity:
// O(V + E)
