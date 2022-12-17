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

void bfs(int row, int col, vector<vector<int> > &vis, vector<vector<char> >& grid) {
    vis[row][col] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(row, col));
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nrow = row + gridX[i];
            int ncol = col + gridY[i];
            if(nrow >= 0 && nrow < n &&  ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                vis[nrow][ncol] = 1;
                q.push(make_pair( nrow, ncol ));
            }
        }
    }
}

void dfs(int row, int col, vector<vector<int> > &vis, vector<vector<char> > grid, int n, int m) {
    if(vis[row][col] == 1 || grid[row][col] == '0') return;
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int drow = row + gridX[i];
        int dcol = col + gridY[i];
        if(drow >= 0 && drow < n && dcol >= 0 && dcol < m && vis[drow][dcol] == 0 && grid[drow][dcol] == '1') {
            dfs(drow, dcol, vis, grid, n, m);
        }
    }
}

int numIslands(vector<vector<char> >& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if(!vis[row][col] && grid[row][col] == '1') {
                cnt++;
                dfs(row, col, vis, grid, n, m);
                // bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    char ch;
    cin >> n >> m;
    vector<vector<char > > grid;
    for (int i = 0; i < n; i++) {
        vector<char> temp;
        for (int j = 0; j < m; j++) {
            cin >> ch;
            temp.push_back(ch);
        }
        grid.push_back(temp);
    }
    cout << numIslands(grid) << endl;
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


