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

bool dfs(int node, int visited[], vector<int> g[]) {
    visited[node] = 1;
    for(auto v : g[node]) {
        if(visited[v] == 0) {
            if(dfs(v, visited, g) == true) return true;
        } else if (visited[v] == 1) {
            return true;
        }
    }
    visited[node] = 2; // 2 means marking when backtrack
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    int visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, adj) == true)
                return true;
        }
    }
    return false;
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
        }
        cout << isCyclic(node, g) << endl;
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
// 0

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