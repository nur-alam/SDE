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

void printGraph(vector<int> adj[], int K) {
    for (int i = 0; i < K; i++) {
        cout << "Node " << i << " : ";
        for (auto it : adj[i]) {
            cout << char(it + 'a') << " ";
        }
        cout << endl;
    }
}

vector<int> topoSort(int size, vector<int> adj[]) {
    int indegree[size];
    memset(indegree, 0, sizeof(indegree));
    for (int i = 0; i < size; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < size; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++) {
            char c1 = s1[ptr], c2 = s2[ptr];
            if (c1 != c2) {
                // int sn1 = c1 - 'a';
                // int sn2 = c2 - 'a';
                adj[c1 - 'a'].push_back(c2 - 'a');
                break;
            }
        }
    }
    // printGraph(adj, K);
    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for(auto it : topo) {
        ans = ans + char(it + 'a');
    }
    return ans;
}

int main() {
    freopen("input2.txt","r", stdin);
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];
        cout << findOrder(dict, N, K) << endl;
    }

    return 0;
}

// input 
// 1
// 3 3 
// caa
// aaa
// aab
// adj 
// output
// bdac
// Node 0 : 1 
// Node 1 : 
// Node 2 : 0 

// intput 
// 1
// 5 4
// baa
// abcd
// abca
// cab
// cad