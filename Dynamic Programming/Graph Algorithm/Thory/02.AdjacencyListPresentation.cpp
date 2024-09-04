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

int main(){
    int N = 6;
    vector<vector<int>> adj(N+1);

    addEdge(adj, 4, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 5);
    addEdge(adj, 6, 3);
    addEdge(adj, 6, 2);

    printList(adj);

    return 0;
}