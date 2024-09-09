// * https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

bool detectNegativeCycle(int V, int E, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: Check for negative-weight cycles.
    // If we can still relax an edge, then there is a negative cycle.
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return true;
        }
    }

    cout << "No negative weight cycle found" << endl;
    return false;
}

int main() {
    int V = 5; 
    int E = 8; 

    // edges[i] = {u, v, w} represents an edge from vertex u to v with weight w
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    int src = 0;

    detectNegativeCycle(V, E, edges, src);

    return 0;
}
