
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

void printGraph(int V, vector<vector<int> > adj) {
    for (int i = 0; i < V; i++) {
        for (auto v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

void printGraphList(int V, vector<int > adj[]) {
    for (int i = 0; i < V; i++) {
        cout << "Node : " << i << " -> ";
        for (auto v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

void dfs(int node, vector<int> &vis, vector<vector<int> >& isConnected) {
    if(vis[node]) return;
    vis[node] = 1;
    for (int i = 0; i < isConnected[0].size(); i++) {
        if(isConnected[node][i] == 1 && !vis[i]) {
            dfs(i, vis, isConnected);
        }
    }
}

int findCircleNum(vector<vector<int> >& isConnected) {
    int n = isConnected[0].size();
    vector<int> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]) {
            cnt++;
            dfs(i, vis, isConnected);
        }
    }
    return cnt;
}

int main() {
    freopen("dfsInMatrix.txt", "r", stdin);
    int V, x;
    cin >> V;
    vector<vector<int> > adj;
    for (int i = 0; i < V; i++) {
        vector<int> temp;
        for (int j = 0; j < V; j++) {
            cin >> x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }
    cout << findCircleNum(adj) << endl;
}