#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

const int max = 10;
// vector<int> g[100];
bool visited[100];

void dfs(vector<int> g[], int node) {
    visited[node] = 1;
    for (int child : g[node]) {
        if(visited[child] != 1)
            dfs( &g[child], child );
    }
}

int main() {
    freopen("input.txt","r", stdin);
    int node, edge;
    cin >> node >> edge;
    vector<int> g[100];
    for (int i = 1; i <= edge; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }

    for (int i = 1; i <= node; i++) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    dfs(g, 1);

    return 0;
}