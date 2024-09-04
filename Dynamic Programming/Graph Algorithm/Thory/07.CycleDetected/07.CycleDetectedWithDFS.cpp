#include <iostream>
#include <vector>
using namespace std;

bool isCyclicUtil(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[u]) {
        visited[u] = true;
        recStack[u] = true;
        for (int x : adj[u]) {
            if (!visited[x] && 
                isCyclicUtil(adj, x, visited, recStack))
                return true;
            else if (recStack[x])
                return true;
        }
    }
    recStack[u] = false;
    return false;
}

bool  isCyclic(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i] && 
            isCyclicUtil(adj, i, visited, recStack))
            return true;
    }
    return false;
}

// Driver function
int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    // Function call
    if (isCyclic(adj, V))
        cout << "Contains Cycle" << endl;
    else
        cout << "No Cycle" << endl;

    return 0;
}
