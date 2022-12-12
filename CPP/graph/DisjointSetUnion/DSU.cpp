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

void make_set(int v, int parent[], int size[]) {
    parent[v] = v;
    size[v] = 1;
}

int find(int node, int parent[], int size[]) {
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node], parent, size);
}

void Union(int u, int v, int parent[], int size[]) {
    u = find(u, parent, size);
    v = find(v, parent, size);
    if (u != v) {
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
    int parent[node + 1];
    int size[node + 1];
    for (int i = 0; i <= node; i++) {
        parent[i] = i;
        size[i] = 1;
        make_set(i, parent, size);
    }
    while(edge--) {
        int u, v;
        cin >> u >> v;
        Union(u, v, parent, size);
    }

    cout << find(0, parent, size) << endl;
    cout << find(2, parent, size) << endl;
    cout << find(3, parent, size) << endl;
    cout << find(4, parent, size) << endl;

    return 0;
}