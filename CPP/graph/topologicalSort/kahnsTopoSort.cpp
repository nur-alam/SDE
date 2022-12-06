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

vector<int> topoSort(int size, vector<int> adj[]) {
    int indegree[size];
    for (int i = 0; i < size; i++) indegree[i] = 0;
    for (int i = 0; i < size; i++) {
        for(auto v : adj[i]) {
            indegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < size; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto v : adj[node]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
    return topo;
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