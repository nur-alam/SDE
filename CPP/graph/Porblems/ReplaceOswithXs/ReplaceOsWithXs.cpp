#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int gridX[8] = {  0,  -1,  0,  +1, -1, -1, 1,  1 };
    int gridY[8] = { -1,  0,  +1,   0, -1,  1, 1, -1 };
    
    void dfs(int row, int col, vector<vector<int > > &vis, vector<vector<char > > &mat) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < 4; i++) {
            int nrow = row + gridX[i];
            int ncol = col + gridY[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && 
            !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                // vis[nrow][ncol] = 1;
                dfs(nrow, ncol, vis, mat);
            }
        }
    }
    
    vector<vector<char> > fill(int n, int m, vector<vector<char> > mat) {
        vector<vector<int> > vis(n, vector<int>(m, 0));
        // traverse first row && last row
        for(int j = 0; j < m; j++) {
            // first row
            if(!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat);
            }
            // last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O') {
                dfs(n-1, j, vis, mat);
            }
        }
        // traverse first column && last column
        for(int i = 0; i < n; i++) {
            // first column
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat);
            }
            // last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i, m-1, vis, mat);
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<char> > mat(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    // Solution obj;
    // vector<vector<char> > ans = obj.fill(n, m, mat);
    // for (auto i : ans) {
    //     for(auto j : i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    int i = 0, j = 1;

    if(i == 0 || j == 0) {
        cout << i << " " << j << endl;
    }

    return 0;
}

// INPUT
// 5 4
// X X X X
// X O X X
// X O O X
// X O X X
// X X O O
// OUTPUT
// X X X X
// X X X X
// X X X X
// X X X X
// X X O O

// INPUT
// 4 5
// X X X X X
// O X X X O
// O X X O X
// X X X O O
// OUTPUT
// X X X X X 
// O X X X O 
// O X X O X 
// X X X O O