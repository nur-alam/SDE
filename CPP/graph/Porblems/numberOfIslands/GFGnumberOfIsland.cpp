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

int gridX[] = {  0,  -1,  0,  +1, -1, -1, 1,  1 };
int gridY[] = { -1,  0,  +1,   0, -1,  1, 1, -1 };
    
void dfs(int row, int col, vector<vector<int> > &grid) {
    if(row < 0 || row >= grid.size() || col < 0 ||
        col >= grid[0].size() || grid[row][col] == 0) {
        return;
    }
    grid[row][col] = 0;
    for(int i = 0; i < 4; i++) {
        int drow = row + gridX[i];
        int dcol = col + gridY[i];
        dfs(drow, dcol, grid);
    }
}

vector<int> numOfIslands(int n, int m, vector<vector<int> > &operators) {
    vector<vector<int> > grid(n, vector<int>(m, 0));
    vector<int >res;
    for(auto it : operators) {
        grid[it[0]][it[1]] = 1;
        vector<vector<int> >newGrid(n, vector<int>(m, 0));
        newGrid = grid;
        int ans = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(newGrid[row][col] == 1) {
                    ans++;
                    dfs(row, col, newGrid);
                }
            }
        }
        res.push_back(ans);
    }
    return res;
}

int main() {
    freopen("GFGnumberOfIsland.txt", "r", stdin);
    int n, m, k, x;
    cin >> n >> m >> k;
    vector<vector<int > > grid;
    for (int i = 0; i < k; i++) {
        vector<int> temp;
        for (int j = 0; j < 2; j++) {
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    vector<int> ans = numOfIslands(n, m, grid);
    for(auto it : ans) {
        cout << it << " ";
    }
    // cout << numOfIslands(n, m, grid) << endl;
}

// input
// 1 1 1 1 1 0 1 1 1 1
// 1 0 1 0 1 1 1 1 1 1
// 0 1 1 1 0 1 1 1 1 1
// 1 1 0 1 1 0 0 0 0 1
// 1 0 1 0 1 0 0 1 0 1
// 1 0 0 1 1 1 0 1 0 0
// 0 0 1 0 0 1 1 1 1 0
// 1 0 1 1 1 0 0 1 1 1
// 1 1 1 1 1 1 1 1 0 1
// 1 0 1 1 1 1 1 1 1 0
// output 
// 2

// input
// 4 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 1 0 0
// 0 0 0 1 1
// output
// 3

// input
// 4 5
// 1 1 1 1 0
// 1 1 0 1 0
// 1 1 0 0 0
// 0 0 0 0 0
// output 
// 1


