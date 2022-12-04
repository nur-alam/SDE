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

bool checkBipartite(int startingNode, int size, int color[], vector<int> g[]) {
    queue<int> q;
    q.push(startingNode);
    color[startingNode] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(color[v] == -1) {
                color[v] = !color[u];
                q.push(v);
            } else if(color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int node, vector<int> g[]) {
    int color[node];
    for (int i = 0; i < node; i++)
        color[i] = -1;
    for (int i = 0; i < node; i++) {
        if (color[i] == -1) {
            if (checkBipartite(i, node, color, g) == false) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    while(tc--) {
        int node, edge;
        cin >> node >> edge;
        vector<int> g[node];
        for (int i = 0; i < edge; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << isBipartite(node, g) << endl;
    }

    return 0;
}

// memset(color,-1,sizeof color);
// 6 5
// 0 3
// 0 4
// 0 5
// 1 3
// 4 5
// output
//0

// input
// 4 4
// 0 2
// 0 3
// 2 3
// 3 1
// output
// 0

// input
// 3 2
// 0 1
// 1 2
// output
// 1