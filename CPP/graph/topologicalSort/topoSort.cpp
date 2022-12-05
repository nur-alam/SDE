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

void printGraph(vector<int> g[], int node) {
    for (int i = 0; i < node; i++) {
        cout << "Node " << i << " : ";
        for (auto v : g[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
    vis[node] = 1;
    for(auto v : adj[node]) {
        if(!vis[v]) {
            dfs(v, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int node, vector<int> adj[]) {
    int vis[node];
    for (int i = 0; i < node; i++) vis[i] = 0;
    stack<int> st;
    for (int i = 0; i < node; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> tmp;
    while(!st.empty()) {
        tmp.push_back(st.top());
        st.pop();
    }
    return tmp;
}

int main() {
    freopen("input.txt","r", stdin);
    int T;
    cin >> T;
    while(T--) {
        int node, edge;
        int u, v;
        cin >> node >> edge;
        vector<int> adj[node];
        for (int i = 0; i < edge; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        printGraph(adj, node);
        vector<int> topo = topoSort(node, adj);
        for (int i = 0; i < topo.size(); i++) {
            cout << topo[i] << " ";
        }
        // cout << "yo" << endl;
    }

    return 0;

}

// input 
// 4 3
// 1 0
// 2 0
// 3 0
// adj 
// Node 0 : 
// Node 1 : 0 
// Node 2 : 0 
// Node 3 : 0 

// intput 
// 6 6
// 1 3
// 2 3
// 4 0
// 4 1
// 5 0
// 5 2
// topo sort 5 4 2 1 3 0
// adj 
// Node 0 : 
// Node 1 : 3 
// Node 2 : 3 
// Node 3 : 
// Node 4 : 0 1 
// Node 5 : 0 2 