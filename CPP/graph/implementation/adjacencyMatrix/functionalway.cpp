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


 //the adjacency matrix initially 0 because global initialization
int adjMat[100][100];

void displayMatrix(int v) {
    int i, j;
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

void addEdge(int u, int v) {
    adjMat[u][v] = 1;
    adjMat[v][u] = 1;
}

int main() {
    //there are 6 node/vertices in the graph
    int node = 6; 
    addEdge(0, 4);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 5);
    addEdge(5, 3);
    addEdge(5, 4);
    displayMatrix(node);
}