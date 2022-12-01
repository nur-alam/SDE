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

int visited[100];
int level[100];
int parent[100];

void bfs(vector<int> g[], int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int child : g[u]) {
            if(!visited[child]) {
                q.push(child);
                parent[child] = u;
                visited[child] = 1;
                level[child] = level[u] + 1;
            }
        }
    }
}

int main() {
    freopen("input.txt","r", stdin);
    int node, edge;
    vector<int> g[100];
    cin >> node >> edge;
    
    for (int i = 0; i < edge; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    bfs(g, 0);

    return 0;
}