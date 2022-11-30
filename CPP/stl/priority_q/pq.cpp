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


int main() {

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(make_pair(10, 500));
    pq.push(make_pair(20, 400));
    pq.push(make_pair(5, 300));

    while (!pq.empty())
    {
        cout << pq.top().first << " ";
        pq.pop();
    }

    return 0;

}