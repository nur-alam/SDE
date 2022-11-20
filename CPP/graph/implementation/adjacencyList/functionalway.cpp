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

// print the graph
void printGraph(vector<int> adj[], int v) {
    for(int node = 0; node < v; node++) {
        cout << "Node " << node << ": ";
        for(auto el : adj[node]) {
        cout << " " << el << " ";
        }
        cout << endl;
    }
}

// add edge
void addEdge(vector<int> adj[], int n, int m) {
    adj[n].push_back(m);
    adj[m].push_back(n);
}

int main() {

    int v = 4;

    vector<int>adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);

    printGraph(adj, v);

    cout << "\n" << adj[0].size() << endl;

    return 0;

}