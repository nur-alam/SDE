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

void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adjT[]) {
    vis[node] = 1;
    for(auto it : adjT[node]) {
        if(!vis[it]) {
            dfs2(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
    vector<int> adjT[V];
    for (int i = 0; i < V; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }
    int scc = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc += 1;
            dfs2(node, vis, adjT);
        }
    }
    return scc;
}

int main() {
    freopen("input.txt", "r", stdin);
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << kosaraju(V, adj) << endl;
    return 0;
}