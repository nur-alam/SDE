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
    cout << endl;
}

bool detectCycle(int node, int parent, vector<int> visited, vector<int> g[]) {
    visited[node] = true;
    for(auto v : g[node]) {
        if (!visited[v]) {
            if(detectCycle(v, node, visited, g))
                return true;
        } else if (visited[v] && v != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<int> g[], int node) {
    vector<int> visited(node + 1, 0);
    for (int i = 0; i < node; i++) {
        if(!visited[i]) {
            if(detectCycle(i, -1, visited, g))
                return true;
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

    printGraph(g, node);

    // vector<int> visited(node + 1, 0);
    // cout << detectCycle(0, -1, visited, g) << endl;

    cout << isCycle(g, node) << " " << endl;

    // cout << detectCycle(g, node, 0) << endl;

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