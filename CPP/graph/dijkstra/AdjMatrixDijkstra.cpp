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

#define PB push_back
#define F first
#define S second

void printGraph(vector<vector<int> > g, int node) {
    for (int i = 0; i < node; i++) {
        cout << "Node " << i << " : ";
        // for (int j = 0; j < g[i].size(); j++) {
        //     cout << g[i][j] << " ";
        // }
        for(auto p : g[i]) {
            cout << p << " ";
        }
        cout << endl;
    }
}

vector<int> dijkstra(vector<vector<int> > g, int s, int node) {
    vector<int> dist(node, INT_MAX);
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        int u = pq.top().second;
        int curD = pq.top().first;
        pq.pop();
        if(dist[u] < curD) continue;
        for (int v = 0; v < node; v++) {
            if(dist[v] > curD + g[u][v]) {
                dist[v] = curD + g[u][v];
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    return dist;
}

int main() {
    freopen("input3.txt", "r", stdin);
    int node, edge, s;
    cin >> node;
    vector<vector<int> > g(node);
    // vector<vector<int> > g(node, vector<int>(node, 0));
    for (int i = 0; i < node; i++) {
        vector<int> temp(node, 0);
        g[i] = temp;
    }

    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cin >> g[i][j];
        }
    }
    cin >> s;

    vector<int> res = dijkstra(g, s, node);
    
    printGraph(g, node);

    for(auto d : res) {
        cout << d << " ";
    }

    return 0;
}

// input
// 2
// 0 25
// 25 0
// 0
// output
// 0 25

// input
// 3
// 0 1 43
// 1 0 6
// 45 6 0
// 2
// output
// 7 6 0