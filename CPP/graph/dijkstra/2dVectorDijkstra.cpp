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

void printGraph(vector<vector<int> > g[], int node) {
    for (int i = 0; i < node; i++) {
        cout << "Node " << i << " : ";
        for(auto child : g[i]) {
            cout << child[0] << " ";
        }
        cout << endl;
    }
}

vector<int> dijkstra(int node, vector<vector<int> > g[], int s) {
    vector<int> dist(node, INT_MAX);
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        int u = pq.top().second;
        int curD = pq.top().first;
        pq.pop();
        if(curD > dist[u]) continue;
        for(auto child : g[u]) {
            int v = child[0];
            int w = child[1];
            if(dist[v] > curD + w) {
                dist[v] = curD + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    int node, edge, u, v, w;
    cin >> node >> edge;
    vector<vector<int> > g[node];
    int i = 0;
    while (i++ < edge) {
        vector<int> v1, v2;
        cin >> u >> v >> w;
        v1.push_back(v);
        v1.push_back(w);
        g[u].push_back(v1);
        v2.push_back(u);
        v2.push_back(w);
        g[v].push_back(v2);
    }

    vector<int> res = dijkstra(node, g, 2);

    for (int i = 0; i < node; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    printGraph(g, node);

    return 0; 
}

// examble input
// 3 3
// 0 1 1
// 0 2 6
// 1 2 3
// 2
// output 
// 4 3 0

// 2 1
// 0 1 9
// 0
// output 
// 0 9