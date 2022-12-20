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
        void dfs(int row, int col, int newColor, int iniColor, vector<vector<int> > &ans, vector<vector<int> > &image) {
            ans[row][col] = newColor;
            int n = image.size();
            int m = image.size();
            for (int i = 0; i < 4; i++) {
                int nrow = row + gridX[i];
                int ncol = col + gridY[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                    dfs(nrow, ncol, newColor, iniColor, ans, image);
                }
            }
        }
        vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor) {
            int iniColor = image[sr][sc];
            vector<vector<int> > ans = image;
            dfs(sr, sc, newColor, iniColor, ans, image);
            return ans;
        }
};

int main() {
        freopen("input.txt", "r", stdin);
        int n, m;
        cin >> n >> m;
        vector<vector<int> > image(n, vector<int>(m, 0) );
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> image[i][j];
            }
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int> > ans = obj.floodFill(image, sr, sc, newColor);
        for(auto i : ans) {
            for(auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        return 0;
}

// input
// 3 3
// 1 1 1
// 1 1 0
// 1 0 1
// 1 1 2
// output 
// 2 2 2
// 2 2 0
// 2 0 1