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

bool detectCycle(vector<int> g[], int totalNode, int node) {
    vector<int> visited(totalNode + 1, 0);
    queue<pair<int, int> > q;
    q.push(make_pair(node, -1));
    visited[node] = true;
    while (!q.empty()) {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int child : g[u]) {
            if(!visited[child]) {
                visited[child] = true;
                q.push(make_pair(child, u));
            } else if (parent != child) {
                return true;
            }
        }
    }
    return false;
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

    cout << detectCycle(g, node, 0) << endl;

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