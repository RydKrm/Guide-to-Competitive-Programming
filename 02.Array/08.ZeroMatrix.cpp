// * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
#include<iostream>
#include<map>
#include<vector>
using namespace std;

void transformMatrix(vector<vector<int>> &mat){
    map<int, int> row, col;
    for (int i = 0; i < mat.size();i++){
        for (int j = 0; j < mat[0].size();j++){
            if(mat[i][j]==0){
                row[i]++;
                col[j]++;
            }
        }
    }

    for (int i = 0; i < mat.size();i++){
        for (int j = 0; j < mat[0].size();j++){
            if((row.count(i) || col.count(j)) && mat[i][j]){
                mat[i][j] = 0;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            int in;
            cin >> in;
            mat[i].push_back(in);
        }
    }

    transformMatrix(mat);

    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }


}