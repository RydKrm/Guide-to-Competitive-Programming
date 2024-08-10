#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cout << "Enter the number of node" << endl;
    cin >> N;
    vector<vector<int>> mat(N+1, vector<int>(N+1, 0));
    int edge;
    cout << "Enter the number of node" << endl;
    cin >> edge;
    while(edge--){
        int start, end;
        cout << "Enter connected two node" << endl;
        cin >> start >> end;
        mat[start][end] = 1;
        mat[end][start] = 1;
    }
    cout << "Matrix " << endl;
    for (int i = 1; i <= N;i++){
        for (int j = 1; j <= N;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}