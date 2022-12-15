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
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[],int firstVis[], int lowVis[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        firstVis[node] = lowVis[node] = timer;
        timer++;
        for(auto it : adj[node]) {
            if(it == parent) continue;
            if(vis[it] == 0) {
                dfs(it, node, vis, adj, firstVis, lowVis, bridges);
            }
            lowVis[node] = min(lowVis[node], lowVis[it]);
            if(lowVis[it] > firstVis[node]) {
                bridges.push_back({node, it});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int firstVis[n], lowVis[n];
        vector<vector<int>> bridges;
        for(int i = 0; i < n; i++) {
            if(!vis[i])
                dfs(i, -1, vis, adj, firstVis, lowVis, bridges);
        }
        return bridges;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj.push_back({u, v});
    }
    Solution obj;
    vector<vector<int> > criticalPoints = obj.criticalConnections(V, adj);
    for(auto it : criticalPoints) {
        cout << it[0] << " " << it[1] << endl;
    }
    return 0;
}