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

vector <int> graph[100];
int main() {
    freopen("input.txt","r", stdin);
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    for(int i = 0; i < node; i++) {
        cout << "node " << i << ": ";
        for(auto e : graph[i]) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
// output
// node 0 -> 1 2 3 
// node 1 -> 0 2 
// node 2 -> 0 1 
// node 3 -> 0 