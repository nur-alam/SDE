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

bool compare(vector<int>& a, vector<int>& b) {
    return (a[2] < b[2]);
}

class DisjointSet {
    vector<int> size, parent;
    public:
        DisjointSet(int n) {
            size.resize(n+1, 0);
            parent.resize(n+1);
            for(int i = 0; i<=n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int find(int node) {
            if(node == parent[node])
                return node;
            return parent[node] = find(parent[node]);
        }
        
        void unionBySize(int uu, int vv) {
            int u = find(uu);
            int v = find(vv);
            if(u == v) return;
            if(size[u] < size[v]) {
                parent[u] = v;
                size[v] += size[u];
            } else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
};

int RevDelMST(int Arr[], int V, int E) {
    vector<vector<int> > edges;
    for (int i = 0; i < 3 * E; i+=3) {
        int u = Arr[i];
        int v = Arr[i + 1];
        int w = Arr[i + 2];
        edges.push_back({ u, v, w });
    }
    sort(edges.begin(), edges.end(), compare);
    // sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {return a[2] < b[2];});
    int sum = 0;
    DisjointSet ds(V);

    for (int i = 0; i < edges.size(); i++) {
        int w = edges[i][2];
        int u = edges[i][0];
        int v = edges[i][1];
        if(ds.find(u) != ds.find(v)) {
            sum += w;
            ds.unionBySize(u, v);
        }
    }
    return sum;
};

int main() {
    freopen("reverseDeleteMst.txt","r", stdin);
    int V, E;
    cin >> V >> E;
    int Arr[3 * E];
    for (int i = 0; i < 3 * E; i++) {
        cin >> Arr[i];
    }
    cout << RevDelMST(Arr, V, E) << endl;

    return 0;
}