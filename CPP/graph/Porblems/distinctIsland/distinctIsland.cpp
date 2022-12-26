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
    int n, m;
    
    void dfs(int row, int col, vector<vector<int> >& grid, 
        vector<vector<int> > &vis, vector<pair<int, int> > &vec, int row0, int col0) {
        vis[row][col] = 1;
        vec.push_back(make_pair(row - row0, col - col0));
        for(int i = 0; i < 4; i++) {
            int nrow = row + gridX[i];
            int ncol = col + gridY[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, vec, row0, col0);
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int> >& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int> > vis(n, vector<int>(m, 0));
        set<vector<pair<int,int> > > st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int> > vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;

    return 0;
}

// INPUT
// 1 1 0 1 1
// 1 0 0 0 0
// 0 0 0 0 1
// 1 1 0 1 1
// OUTPUT
// 3

// INPUT
// 4 5
// 1 1 0 0 0 
// 1 1 0 0 0
// 0 0 0 1 1
// 0 0 0 1 1
// OUTPUT
// 1