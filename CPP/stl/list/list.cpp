// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include<algorithm>
#include<list>
using namespace std;

int main() {

    list<int> ll;
    list<int>::iterator it;
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_front(0);
    ll.pop_back();
    for (auto el : ll)
    {
        cout << el << " ";
    }
    cout << endl;
    it = find(ll.begin(), ll.end(), 3);
    cout << *it << endl;
    return 0;
}