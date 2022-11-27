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

void bfs(vector<int> g[], int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
        int top = q.front();
        cout << top << " ";
        q.pop();
        for (int child : g[top]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = 1;
                level[child] = level[child] + 1;
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
    cout << " yo " << g[0][0] << endl;
    return 0;
}