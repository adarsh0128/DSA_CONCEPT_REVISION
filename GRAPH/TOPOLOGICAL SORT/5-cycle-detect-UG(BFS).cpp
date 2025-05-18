// Here's a BFS-based approach to detect a cycle in an undirected graph using a queue and parent tracking. This method works because in an undirected graph, a cycle exists if you can find a visited node again through a different path (not the parent).

// Explanation:
// Use a queue for BFS traversal.
// Keep track of the parent node for each visited node.
// If during BFS, you visit an adjacent node which is already visited and is not the parent, then a cycle exists.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to detect cycle in an undirected graph using BFS
bool isCycle(int V, vector<vector<int>>& edges) {
    // Build adjacency list representation of the graph
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);   // Add edge u -> v
        adj[v].push_back(u);   // Add edge v -> u (undirected graph)
    }

    vector<bool> visited(V, false);  // Track visited nodes

    // Check each connected component of the graph
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {  // If node not visited yet
            queue<pair<int, int>> q; // Queue stores pairs of (node, parent)
            q.push({i, -1});          // Start BFS from node i with no parent
            visited[i] = true;        // Mark node as visited

            while (!q.empty()) {
                int node = q.front().first;    // Current node
                int parent = q.front().second; // Parent of current node
                q.pop();

                // Traverse all adjacent nodes
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        // If neighbor not visited, mark visited and add to queue
                        visited[neighbor] = true;
                        q.push({neighbor, node});
                    }
                    else if (neighbor != parent) {
                        // If neighbor is visited and not parent, cycle detected
                        return true;
                    }
                }
            }
        }
    }

    // If no cycle found after BFS on all components
    return false;
}

int main() {
    int V = 5;

    // Example edges (undirected graph)
    // Contains a cycle: 0-1-2-3-0
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, {3, 4}
    };

    if (isCycle(V, edges))
        cout << "Cycle detected in the undirected graph.\n";
    else
        cout << "No cycle found in the undirected graph.\n";

    return 0;
}


// Time Complexity:
// Building adjacency list: O(E)

// BFS visits each vertex once and edges once: O(V + E)

// Space Complexity:
// Adjacency list: O(V + E)

// Visited array and queue: O(V)