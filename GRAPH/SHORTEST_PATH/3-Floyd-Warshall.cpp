// 📌 What is Floyd-Warshall Algorithm?
// The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph.

// ✅ Works on:
// Directed or undirected graphs
// Positive or negative weights
// ❌ Does not work if the graph contains negative weight cycles

// 🧠 Concept (Dynamic Programming)
// The core idea is:
// If vertex k is an intermediate point between i and j,
// then the shortest path from i to j is:
// dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
// Repeat this check for every pair (i, j) and for every intermediate vertex k.


#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9  // Use a large number to represent infinity
#define V 4      // Number of vertices

// Function to run Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>>& graph) {
    // Step 1: Create a distance matrix initialized with the input graph
    vector<vector<int>> dist = graph;

    // Step 2: Apply the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {         // Intermediate vertex
        for (int i = 0; i < V; i++) {     // Source vertex
            for (int j = 0; j < V; j++) { // Destination vertex
                // If a shorter path exists through vertex k, update it
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative weight cycle!\n";
            return;
        }
    }

    // Step 4: Print the shortest path matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

// int main() {
    // Graph represented as adjacency matrix
    // vector<vector<int>> graph = {
    //     {0,   5,   INF, 10},
    //     {INF, 0,   3,   INF},
    //     {INF, INF, 0,   1},
    //     {INF, INF, INF, 0}
    // };

    // Run the algorithm
//     floydWarshall(graph);

//     return 0;
// }

// ⏱️ Time Complexity (TC)
// Explanation:
// The algorithm uses 3 nested loops over all vertices → O(V³)
// ✅ Total Time Complexity:
// O(V³)

// 📦 Space Complexity (SC)
// Explanation:
// It uses a 2D matrix of size V x V to store distances → O(V²)
// ✅ Total Space Complexity:
// O(V²)

