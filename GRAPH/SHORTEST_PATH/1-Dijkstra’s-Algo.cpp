// Dijkstra’s algorithm is used to find the shortest path from a single source node to all other nodes in a weighted graph with non-negative edge weights.

// 📌 Key Concepts
// Greedy Algorithm: It picks the minimum distance node that hasn't been visited yet.
// Priority Queue (Min-Heap): Used to efficiently fetch the node with the smallest tentative distance.
// Adjacency List: Preferred for sparse graphs.

// 🧠 Steps of the Algorithm
// Set all distances to infinity (INT_MAX), except the source node which is 0.
// Use a min-priority queue to get the node with the smallest distance.
// For each neighboring node, check if a shorter path is found through the current node.
// If yes, update the distance and push the neighbor into the queue.
// Repeat until all nodes are processed.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Typedef for a pair representing (node, weight)
typedef pair<int, int> pii;

// Dijkstra's Algorithm function
void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& dist) {
    int n = graph.size();

    // Initialize all distances to infinity
    dist.assign(n, INT_MAX);
    dist[start] = 0;

    // Min-heap priority queue to get the node with the smallest distance
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start}); // (distance, node)

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If this path is longer than the already found shortest path, skip
        if (current_dist > dist[u]) continue;

        // Traverse all neighbors of the current node
        for (auto edge : graph[u]) {
            int v = edge.first;       // Neighbor node
            int weight = edge.second; // Edge weight

            // Relaxation step: if a shorter path to v is found
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int nodes = 5;

    // Adjacency list: graph[u] contains pairs (v, weight)
    vector<vector<pii>> graph(nodes);

    // Adding directed edges: u -> v with weight
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({0, 7});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    vector<int> dist; // To store shortest distances from source

    // Run Dijkstra from source node 0
    dijkstra(0, graph, dist);

    // Output shortest distances
    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < nodes; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << endl;
    }

    return 0;
}


// 🧮 Time and Space Complexity Analysis
// ✅ Time Complexity (TC):
// Let:
// V = number of vertices
// E = number of edges
// Each node is pushed and popped once → O(V log V)
// Each edge may be relaxed once → O(E log V) (due to priority queue)
// 🔸 Overall:
// O((V + E) * log V)

// ✅ Space Complexity (SC):
// Distance array → O(V)
// Priority queue → up to O(V)
// Adjacency list → O(V + E)
// 🔸 Overall:
// O(V + E)

// 📌 Notes
// Works for directed or undirected graphs (just add reverse edge if undirected).
// Only works when all edge weights are non-negative.
// You can use a set instead of a priority_queue for dynamic updates, but it's slightly slower.

// Use case: Finding the shortest or fastest route from one location to another.
// Example: Google Maps or GPS in cars uses Dijkstra (or optimized versions like A*) to calculate routes avoiding traffic or roadblocks.
// Why Dijkstra? It finds the minimum distance path in a graph of roads and intersections.

// A priority queue (min-heap) is used in Dijkstra’s algorithm to efficiently select the node with the smallest tentative distance (i.e., the closest unvisited node). This is the key step in the algorithm's greedy approach.
// 💡 Intuition
// Dijkstra’s algorithm repeatedly picks the "closest" node that hasn't been processed yet.
// A naive approach would scan all nodes every time to find the minimum distance → O(V²) time
// A priority queue gives us the node with the minimum distance in O(log V) time, greatly improving efficiency.
