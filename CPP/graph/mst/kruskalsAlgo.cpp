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

class DisjointSet {
    vector<int> size, parent;
    public:
        DisjointSet(int n) {
            size.resize(n+1, 0);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int find(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = find(parent[node]);
        }
        
        void unionBySize(int uu, int vv) {
            int u = find(uu);
            int v = find(vv);
            if(u == v) return;
            if(size[u] < size[v]) {
                parent[u] = v;
                size[v] += size[u];
            } else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
};

class Mst
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int> > adj[]) {
        vector<pair<int, pair<int, int> > > edges;
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                int u = it[0];
                int wt = it[1];
                int node = i;
                // edges.push_back({wt, {i, u}});
                edges.push_back(make_pair(wt, make_pair(node, u)));
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        vector<pair<int, pair<int, int > > > mst;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.find(u) != ds.find(v)) {
                mstWt += wt;
                mst.push_back(make_pair(wt, make_pair(u, v)));
                ds.unionBySize(u, v);
            }
        }
        for (int i = 0; i < mst.size(); i ++) {
            cout << mst[i].first << " " << mst[i].second.first << " " << mst[i].second.second << endl;
        }
        return mstWt;
    }
};

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
    Mst obj;
    cout << obj.spanningTree(V, adj) << endl;

    return 0;
}