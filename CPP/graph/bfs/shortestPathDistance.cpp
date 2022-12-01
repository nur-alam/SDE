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
}

int max = INT_MAX;
int visited[10], dist[10], parent[10];

void bfs(vector<int> g[], int node) {
    int source = 0;
    visited[source] = 1; dist[source] = 0; parent[source] = -1;
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : g[u]) {
            if(!visited[v]) {
                dist[v] = dist[u] + 1;
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void getNodesDistance(int node) {
    for (int i = 0; i < node; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

vector<int> getPath(int node) {
    vector<int> paths;
    paths.push_back(node);
    while (parent[node] != -1) {
        node = parent[node];
        paths.push_back(node);
    }
    reverse(paths.begin(), paths.end());
    for (auto path : paths) {
        cout << path << " ";
    }
    cout << endl;
    return paths;
}

int main() {

    freopen("input.txt", "r", stdin);

    int node, edge;
    vector<int> g[10];
    cin >> node >> edge;
    while(edge--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(g, node);
    getNodesDistance(node);
    getPath(5);
    // printGraph(g, node);
    // cout << endl << "yo" << endl;

    return 0;
}

// input 
// 6 6
// 0 1
// 0 2
// 0 3
// 2 4
// 2 5
// 3 5
// output
// 0 1 1 1 2 2 
// 0 2 5 