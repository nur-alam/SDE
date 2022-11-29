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


int main() {
    freopen("input.txt", "r", stdin);
    int adjMat[10][10];
    int node, edge;
    cin >> node >> edge;

    int n1, n2;
    for(int i = 0; i < edge; i++) {
        cin >> n1 >> n2;
        adjMat[n1][n2] = 1;
        adjMat[n2][n1] = 1;
    }
    // input line equal to edge
    for(int i = 0; i < node; i++) {
        for(int j = 0; j < node; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
// output
// node 0 -> 1 2 3 
// node 1 -> 0 2 
// node 2 -> 0 1 
// node 3 -> 0 