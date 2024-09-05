// Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

#include<iostream>
#include<vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n){
    int start = 0, end = n - 1;
    for (int i = 0; i < n / 2;i++){
        for (int j = start; j < end; j++){
            // step 01
            int temp = mat[start][start + j];
            // step 02
            mat[start][start + j] = mat[end - j][start];
            // step 03
            mat[end - j][start] = mat[end][end - j];
            // step 04
            mat[end][end - j] = mat[start + j][end];
            // step 05
            mat[start + j][end] = temp;
        }
        start++;
        end--;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> mat(n) ;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            int in;
            cin >> in;
            mat[i].push_back(in);
        }
    }
for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout<< mat[i][j]<<" ";
        }
        cout << endl;
    }
    rotateMatrix(mat, n);

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout<< mat[i][j]<<" ";
        }
        cout << endl;
    }

    return 0;
}