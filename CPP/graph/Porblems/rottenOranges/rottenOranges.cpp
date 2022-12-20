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

class Solution
{
    public:
        int gridX[8] = {  0,  -1,  0,  +1, -1, -1, 1,  1 };
        int gridY[8] = { -1,  0,  +1,   0, -1,  1, 1, -1 };
        
        int orangesRotting(vector<vector<int> > &grid) {
            int n = grid.size();
            int m = grid[0].size();
            queue<pair< pair<int, int>, int > > q;
            vector<vector<int> > vis(n, vector<int>(m, 0));
            int countFresh = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(grid[i][j] == 2) {
                        q.push(make_pair(make_pair(i, j), 0));
                        vis[i][j] = 2;
                    } else {
                        vis[i][j] = 0;
                    }
                    if(grid[i][j] == 1) countFresh++;
                }
            }
            int tm = 0;
            int cnt = 0;
            while(!q.empty()) {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                q.pop();
                tm = max(tm, t);
                for (int i = 0; i < 4; i++) {
                    int nrow = r + gridX[i];
                    int ncol = c + gridY[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                        q.push(make_pair(make_pair(nrow, ncol), t + 1));
                        vis[nrow][ncol] = 2;
                        cnt++;
                    }
                }
            }
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++) {
            //         if(vis[i][j] != 2 && grid[i][j] == 1)
            //             return -1;
            //     }
            // }
            if(countFresh != cnt) return -1;
            return tm;
        }
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << "\n";
}