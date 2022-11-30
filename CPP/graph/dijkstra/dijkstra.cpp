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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;  // vector<vector<int>>
typedef vector<vl> vvl;  // vector<vector<long long>>
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi; // vector<pair<int, int>>
typedef vector<pll> vpl; // vector<pair<ll, ll>>

#define PB push_back
#define F first
#define S second

void printGraph(vpi g[] ,int node) {
    for (int i = 0; i < node; i++) {
        cout << "Node " << i << " : ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << "(" << g[i][j].first << " " << g[i][j].second << ")" << " ";
        }
        cout << endl;
    }
}

void dijkstra(int s, int node, vpi g[], ll dist[]) {
    for (int i = 0; i <= node; i++)
        dist[i] = LLONG_MAX;
    dist[s] = 0; // initializing source distance
    priority_queue< pair<long long, long long>, vector< pair<long long, long long> >, greater< pair<long long, long long> > > pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        int u = pq.top().second;
        int curD = pq.top().first;
        pq.pop();
        if(curD > dist[u]) continue;
        for(auto &[v, w] : g[u]) {
            // int v = p.first;
            // ll w = p.second;
            if(curD + w < dist[v]) {
                dist[v] = curD + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    freopen("input2.txt", "r", stdin);
    // vector<pair<int, int> > g[100];
    vpi g[100];
    ll dist[100];
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    dijkstra(1, node, g, dist);

    printGraph(g, node);

    for (ll i = 1; i <= node; i++) {
        cout << dist[i] << " ";
    }

    return 0; 
}


// input
// 3 4
// 1 2 6
// 1 3 2
// 3 2 3
// 1 3 4

// output
// 0 5 2