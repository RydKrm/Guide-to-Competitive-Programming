#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>> &adj, int start, int end){
    adj[start].push_back(end);
    adj[end].push_back(start);
}

void printList(vector<vector<int>> adj){
    for (int i = 1; i < adj.size();i++){
        cout << "for " << i << " node" << " ";
        for (int j:adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

void dijkstra(vector<vector<int>> adj, vector<int>dis,int source){
    
}

int main(){
    int N = 5;
    vector<vector<int>> adj(N+1);

    vector<int> dist(N, INT_MAX);


    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    addEdge(adj, 2, 5);

    printList(adj);
    dijkstra(adj, dist, 1);

    return 0;
}