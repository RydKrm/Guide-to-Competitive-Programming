#include <iostream>
#include <vector>

using namespace std;

const int V = 4;
void DFS(int u, int v, vector<vector<int>>& tc, vector<int> adj[]) {
    tc[u][v] = 1;
    for (int i : adj[v]) {
        if (!tc[u][i]) {
            DFS(u, i, tc, adj);
        }
    }
}

void transitiveClosure(vector<vector<int>>& tc, vector<int> adj[]) {
    for (int i = 0; i < V; i++) {
        DFS(i, i, tc, adj);
    }
}

int main() {
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    vector<vector<int>> tc(V, vector<int>(V, 0));
    transitiveClosure(tc, adj);    
    cout << "Transitive Closure Matrix is:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << tc[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
