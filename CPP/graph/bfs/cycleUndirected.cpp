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
int dist[100];
int parent[100];

bool detectCycle(vector<int> g[], int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    int flag = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int child : g[u]) {
            if(visited[child] && parent[u] != child) {
                flag = 1;
                return flag;
            }
            else if (!visited[child]) {
                q.push(child);
                parent[child] = u;
                visited[child] = 1;
                dist[child] = dist[u] + 1;
            }
        }
    }
    return flag;
}

int main() {
    freopen("input.txt","r", stdin);
    int node, edge;
    cin >> node >> edge;
    vector<int> g[node];
    
    for (int i = 0; i < edge; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << detectCycle(g, 0) << endl;

    return 0;
}


// input 
// 5 5
// 1 0
// 1 2
// 0 2
// 0 3
// 3 4
// output
// 1


// input 
// 6 6
// 0 1
// 0 2
// 0 3
// 2 4
// 2 5
// 3 5
// output
// 1