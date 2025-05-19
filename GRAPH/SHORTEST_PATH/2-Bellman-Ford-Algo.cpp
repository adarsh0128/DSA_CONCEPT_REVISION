// Bellman-Ford is a single-source shortest path algorithm that can handle graphs with negative edge weights, unlike Dijkstra’s algorithm.

// 🧠 When to Use Bellman-Ford
// Condition	Bellman-Ford
// Negative weights	✅ Yes
// Detect negative weight cycles	✅ Yes
// Faster on sparse graphs than Dijkstra	❌ No
// Graph type	Directed or Undirected (convert undirected to directed by adding both directions)

// ⚠️ Difference Between Bellman-Ford and Dijkstra
// Feature	Bellman-Ford	Dijkstra
// Handles Negative Weights	✅ Yes	❌ No
// Detects Negative Cycles	✅ Yes	❌ No
// Faster for Non-negative Weights	❌ No	✅ Yes (with heap)
// Time Complexity	O(V * E)	O((V + E) log V)

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge from u to v with a given weight
struct Edge {
    int u, v, weight;
};

// Bellman-Ford function
void bellmanFord(int V, int E, int src, vector<Edge>& edges) {
    // Step 1: Initialize distances from source to all vertices as infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 2: Relax all edges (V - 1) times
    // This ensures shortest distances are computed considering all possible paths
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].weight;

            // If the distance to u is not infinite and a shorter path to v is found
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int wt = edges[j].weight;

        // If we can still relax an edge, then a negative cycle exists
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Step 4: Print the shortest distances
    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << "\tINF" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges

    // Create edge list
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0; // Source vertex

    // Call Bellman-Ford algorithm
    bellmanFord(V, E, source, edges);

    return 0;
}

// ⏱️ Time Complexity (TC)
// Main operations:
// Relaxation of all edges (V-1 times) → O(V * E)
// Final check for negative weight cycle → O(E)
// ✅ Total Time Complexity:
// O(V * E)
// V = number of vertices
// E = number of edges

// 📦 Space Complexity (SC)
// Memory usage:
// Distance array → O(V)
// Edge list → O(E)
// ✅ Total Space Complexity:
// O(V + E)

