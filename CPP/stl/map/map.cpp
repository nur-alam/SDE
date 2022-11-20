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

    map< int, unordered_set<int> > adj;
    adj[2].insert(4);
    adj[0].insert(5);
    map<int, int> m;

    m.insert(make_pair(4,3));
    m.insert(make_pair(5,6));
    m.insert(make_pair(2,2));

    // if(m.find(5)) { it's not possible cause it's return iterator then u have to access ->first/second so that there is value or not
    if(m.find(5) != m.end()) { 
        cout << m.find(5)->first << m.find(5)->second << endl;
    }

    
    map< int, unordered_set<int> > adj;
    map< int, unordered_set<int> >::iterator it;
    adj[3].insert(3);
    adj[1].insert(2);
    adj[1].insert(8);
    // it = adj.begin()->second;
    cout << adj.begin()->first << " " << adj.begin()->second.size() << endl;
    for(auto el : adj.begin()->second) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}