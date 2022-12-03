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

bool check(int start, int V, vector<int>adj[], int color[]) {
    queue<int> q;
    q.push(start); 
    color[start] = 0; 
    while(!q.empty()) {
        int node = q.front();
        q.pop(); 
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = !color[node]; 
                q.push(it); 
            }
            else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool isBipartite(int V, vector<int>adj[]){
    int color[V]; 
    for(int i = 0;i<V;i++) color[i] = -1; 
    for(int i = 0;i<V;i++) {
        if(color[i] == -1) {
            if(check(i, V, adj, color)) {
                return true; 
            }
        }
    }
    return false; 
}

int main() {
    freopen("input.text", "r", stdin);
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
