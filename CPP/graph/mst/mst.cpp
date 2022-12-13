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

int spanningTree(int V, vector<vector<int> > adj[]) {
    priority_queue< pair<int, pair<int,int > >, vector< pair<int, pair<int,int > > >, greater< pair<int, pair<int,int> > > > pq;
    vector<int> vis(V, 0);
    vector<pair<int, pair<int, int> > > mst;
    pq.push(make_pair(0, make_pair(0, -1))); //{w,node}
    int sum = 0;
    while(!pq.empty()) {
        auto pqTop = pq.top();
        pq.pop();
        int node = pqTop.second.first;
        int parent = pqTop.second.second;
        int wt = pqTop.first;
        if(vis[node] == 1) continue;
        mst.push_back(make_pair(wt, make_pair(node, parent)));
        vis[node] = 1;
        sum += wt;
        for(auto it : adj[node]) {
            int adjNode = it[0];
            int adjW = it[1];
            if(!vis[adjNode]) {
                pq.push(make_pair(adjW, make_pair(adjNode, node)));
            }
        }
    }
    for (int i = 0; i < mst.size(); i++){
        cout << mst[i].first << " " << mst[i].second.second << " " << mst[i].second.first << endl;
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