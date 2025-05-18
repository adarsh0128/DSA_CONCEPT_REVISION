// ✅ What is BFS?
// Breadth-First Search traverses the graph level by level.
// It uses a queue and a visited array to avoid revisiting nodes.
// Best for shortest path (unweighted graphs) or exploring neighbors first.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal of the graph
vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
    vector<int> bfs;         // Stores the BFS traversal result
    vector<int> vis(V, 0);   // Visited array to keep track of visited nodes
    queue<int> q;            // Queue for BFS

    vis[0] = 1;              // Start BFS from node 0
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node); // Process current node

        // Visit all adjacent unvisited nodes
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;   // Mark as visited
                q.push(neighbor);    // Add to queue for further exploration
            }
        }
    }

    return bfs;
}

int main() {
    int V = 5; // Number of vertices

    // Adjacency list for the graph
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Perform BFS
    vector<int> result = bfsOfGraph(V, adj);

    // Output the result
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


// ⏱ Time Complexity (TC): O(V + E)
// Each vertex is visited once → O(V)
// Each edge is traversed once (from both ends in undirected graph) → O(E)
// Total: O(V + E)

// 🧠 Space Complexity (SC):
// visited array → O(V)
// queue for BFS → up to O(V) in worst case
// adj list for graph → O(V + E) for storage
// 👉 Total SC: O(V + E)


// 🔥 Common Uses of Graphs
// 1. Social Networks
// Represent users as nodes.

// Friendships or connections as edges.

// Used for friend suggestions, community detection, influence spreading.

// 2. Maps and Navigation
// Cities/locations = nodes.

// Roads/paths = edges.

// Find shortest path (GPS), route optimization, traffic flow.

// 3. Web Page Linking (Web Graph)
// Web pages = nodes.

// Hyperlinks = directed edges.

// Used by search engines (Google’s PageRank algorithm).
