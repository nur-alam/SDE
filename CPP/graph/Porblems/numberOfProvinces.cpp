
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
        // cout << "Node : " << i << " ";
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

void dfs(int node, vector<int> adjLs[], vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adjLs[node]) {
        if(!vis[it]) {
            dfs(it, adjLs, vis);
        }
    }
}

int numProvinces(int V, vector<vector<int> > adj) {
    vector<int> adjLs[V];
    vector<vector<int> > adjVis(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if(!adjVis[i][j] && adj[i][j] == 1 && i != j) {
                adjVis[i][j] = 1;
                adjVis[j][i] = 1;
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    vector<int> vis(V, 0);
    int cnt = 0;
    for (int i = 0; i < V; i++) {
        if(!vis[i]) {
            cnt++;
            dfs(i, adjLs, vis);
        }
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
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
    cout << numProvinces(V, adj) << endl;
}