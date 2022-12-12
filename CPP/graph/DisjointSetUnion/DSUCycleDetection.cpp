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

void make_set(int node, vector<int> &parent, vector<int> &size) {
    parent[node] = node;
    size[node] = 1;
}

int find(int node, vector<int> &parent) {
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node], parent);
}

void dsu(int u, int v, vector<int> &parent, vector<int> &size) {
    u = find(u, parent);
    v = find(v, parent);
    if(u != v) {
        if(size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
}

int main() {
    freopen("input.txt","r", stdin);
    int node, edge;
    cin >> node >> edge;
    vector<int> parent(node + 1);
    vector<int> size(node + 1);
    for (int i = 0; i <= node; i++) {
        make_set(i, parent, size);
    }
    vector<vector<int> > edges;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);
    }
    bool cycle = false;
    for (auto it : edges) {
        cout << it[0] << " " << it[1] << endl;
        int u = find(it[0], parent);
        int v = find(it[1], parent);
        if(u == v) {
            cycle = true;
            break;
        } else {
            dsu(u, v, parent, size);
        }
    }
    cout << cycle << endl;

    return 0;
}