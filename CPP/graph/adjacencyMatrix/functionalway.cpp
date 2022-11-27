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
int totalNode = 4;

void displayMatrix() {
    int i, j;
    for(i = 0; i < totalNode; i++) {
        for(j = 0; j < totalNode; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

void addEdge(int u, int v) {
    adjMat[u][v] = 1;
    adjMat[v][u] = 1;
}

void removeEdge(int u, int v) {
    adjMat[u][v] = 0;
    adjMat[v][u] = 0;
}

void addNode() {
    totalNode++;
    for (int i = 0; i < totalNode; i++) {
        adjMat[i][totalNode - 1] = 0;
        adjMat[totalNode - 1][i] = 0;
    }
}

void removeNode(int node) {
    while(node < totalNode) {
        for (int i = 0; i < totalNode; i++) {
            adjMat[i][node] = adjMat[i][node + 1];
        }
        for (int i = 0; i < totalNode; i++) {
            adjMat[node][i] = adjMat[node + 1][i];
        }
        node++;
    }
    totalNode--;
}

int main() {
    //there are 6 node/vertices in the graph
    // int node = 6; 
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);

    // addEdge(0, 1);
    // addEdge(0, 2);
    // addEdge(1, 2);
    // addEdge(2, 3);

    // addNode();

    // addEdge(4, 1);
    // addEdge(4, 3);
    displayMatrix();
    cout << endl;
    removeNode(1);
    displayMatrix();
}