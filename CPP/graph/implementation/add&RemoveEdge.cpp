#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <utility>
#include<algorithm>
using namespace std;

void printGraph(vector<int> graph[]) {
    for (int i = 0; i < 4; i++) {
        cout << "Node " << i << " : ";
        for(auto el : graph[i]) {
            cout << el << " ";
        }
        cout << endl;
    }
}

void addEdge(vector<int> graph[], int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void delEdge(vector<int> graph[], int u, int v) {
    vector<int> temp;
    for (int i = 0; i < graph[u].size(); i++) {
        if(graph[u][i] == v) {
            graph[u].erase(graph[u].begin() + i);
        }
    }
    for (int i = 0; i < graph[v].size(); i++) {
        if(graph[v][i] == u) {
            graph[v].erase(graph[v].begin() + i);
        }
    }
}

int main() {
    int node = 4;
    int edge = 7;
    vector<int> graph[node];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    delEdge(graph, 0, 1);
    delEdge(graph, 0, 2);
    printGraph(graph);
    return 0;
}