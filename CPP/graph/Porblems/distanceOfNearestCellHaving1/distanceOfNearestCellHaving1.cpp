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
        //Function to find distance of nearest 1 in the grid for each cell.
    	vector<vector<int> >nearest(vector<vector<int> >grid) {
    	    int n = grid.size();
    	    int m = grid[0].size();
    	    vector<vector<int> > vis(n, vector<int> (m, 0));
    	    vector<vector<int> > dist(n, vector<int> (m, 0));
    	    queue<pair<pair<int, int>,int> >q;
    	    for(int i = 0; i < n; i++) {
    	        for(int j = 0; j < m; j++) {
    	            if(grid[i][j] == 1) {
    	                // q.push({{i, j}, 0});
                        q.push(make_pair(make_pair(i, j), 0));
                        vis[i][j] = 1;
                    }
    	        }
    	    }
    	    while(!q.empty()) {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                dist[row][col] = steps;
                for(int i = 0; i < 4; i++) {
                    int nrow = row + gridX[i];
                    int ncol = col + gridY[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        // q.push({{nrow, ncol},steps + 1});
                        q.push(make_pair(make_pair(nrow, ncol), steps + 1));
                    }
                }
    	    }
    	    return dist;
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
    vector<vector<int> > ans = obj.nearest(grid);
    for(auto i : ans) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}