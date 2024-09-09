#include<iostream>
#include<vector>
using namespace std;

bool isDetectedCycle(int source,vector<vector<int>> adj, vector<bool> &visited, int parent){
    visited[source] = true;
    for(int v:adj[source]){
        if(!visited[v]){
          if(isDetectedCycle(v,adj, visited, source)){
            return true;
          }
        } else if(v != parent){
           return true;
        }
    }
    return false;
}

bool isCyclic(int V,vector<vector<int>> &adj){
    vector<bool> visited(V, false);
    for (int i = 0; i < visited.size();i++){
        if(!visited[i]){
            if(isDetectedCycle(i,adj,visited,-1)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 3;
    vector<vector<int>> adj(V);

    adj[1].push_back(0);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);

    isCyclic(V, adj) ? cout << "Contains cycle\n"
                     : cout << "No Cycle\n";

    V = 3;
    vector<vector<int>> adj2(V);

    adj2[0].push_back(1);
    adj2[1].push_back(0);
    adj2[1].push_back(2);
    adj2[2].push_back(1);

    isCyclic(V, adj2) ? cout << "Contains Cycle\n"
                      : cout << "No Cycle\n";

    return 0;
}