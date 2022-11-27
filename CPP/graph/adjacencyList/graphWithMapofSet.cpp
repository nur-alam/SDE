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

void addNode(map< int, unordered_set<int> > &adj, int node) {
    unordered_set<int> ust;
    adj[node] = ust;
}

void deleteNode(map< int, unordered_set<int> > &adj, int node) {
    adj.erase(node);
    for (auto it = adj.begin(); it != adj.end(); it++) {
        if(it->second.find(node) != it->second.end()) {
            it->second.erase(node);
        }
    }
}

void addEdge(map< int, unordered_set<int> > &adj, int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

void deleteEdge(map< int, unordered_set<int> > &adj, int u, int v) {
    // for (auto &[first,sec] : adj) {
    //     if(first == u) {
    //         cout << "u " << first << " " << endl;
    //         adj[first].erase(v);
    //     }
    //     if(first == v) {
    //         cout << "v " << first << " " << endl;
    //         adj[first].erase(u);
    //     }
    // }
    adj[u].erase(v);
    adj[v].erase(u);
}

void print(map<int, unordered_set<int> >& adj) {
    for(auto &[u,v] : adj) {
        cout << "Node " << u << ": ";
        for (auto el : v) {
            cout << el << " ";
        }
        cout << endl;
    }
}

int main() {
    // adjacency list
    map< int, unordered_set<int> > adj;
    map< int, unordered_set<int> >::iterator it;
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    print(adj);
    adj.erase(8);
    // deleteEdge(adj, 1, 0);
    // deleteNode(adj, 1);
    print(adj);

    return 0;
}