#include<iostream>
#include<vector>
#include<queue>
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

void BFS(vector<vector<int>> &adj, vector<bool> &visited, int source ){
    queue<int> que;
    visited[source] = true;
    que.push(source);

    while(!que.empty()){
        int curr = que.front();
        que.pop();
        cout << curr << " ";
        for(int x:adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                que.push(x);
            }
        }
    }
}

void BFSHelper(vector<vector<int>> &adj, vector<bool> &visited){
    for (int i = 0; i < visited.size();i++){
        if(visited[i]==false){
            BFS(adj, visited, i);
        }
    }
}

int main(){
    int N = 6;
    vector<vector<int>> adj(N+1);

    addEdge(adj, 4, 1);
    addEdge(adj, 5, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 3, 5);

    printList(adj);

    // * Start BFS Code here
    vector<bool> visited(N, false);
    int source = 1;
    BFSHelper(adj, visited);
    

    return 0;
}