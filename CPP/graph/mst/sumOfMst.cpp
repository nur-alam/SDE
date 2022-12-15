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

// https://practice.geeksforgeeks.org/problems/reverse-delete-algorithm-for-minimum-spanning-tree1158/1

int spanningTree(int V, vector<vector<int> > adj[]) {
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
    vector<int> vis(V, 0);
    pq.push(make_pair(0, 0)); //{w,node}
    int sum = 0;
    while(!pq.empty()) {
        auto pqTop = pq.top();
        pq.pop();
        int node = pqTop.second;
        int wt = pqTop.first;
        if(vis[node] == 1) continue;
        // mst.push_back(make_pair());
        vis[node] = 1;
        sum += wt;
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int adjW = it[1];
            if(!vis[adjNode]) {
                pq.push(make_pair(adjW, adjNode));
            }
        }
    }
    return sum;
}

int main() {
    freopen("input.txt","r", stdin);
    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj[V];
    int i = 0;
    while(i++ < E) {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    cout << spanningTree(V, adj) << endl;
    cout << "yo" << endl;

    return 0;
}