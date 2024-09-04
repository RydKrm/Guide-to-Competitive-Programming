#include <iostream>
#include <vector>

using namespace std;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

bool dfs(int v, vector<vector<int>>& adj, vector<int>& color) {
    color[v] = GRAY;
    for (int u : adj[v]) {
        if (color[u] == GRAY) {
            return true;
        }
        if (color[u] == WHITE && dfs(u, adj, color)) {
            return true;
        }
    }
    color[v] = BLACK; 
    return false;
}

bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> color(n, WHITE);

    for (int i = 0; i < n; ++i) {
        if (color[i] == WHITE) {
            if (dfs(i, adj, color)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> adj(n);

    // Example graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    // adj[2].push_back(0);
    adj[2].push_back(3);

    if (hasCycle(n, adj)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
