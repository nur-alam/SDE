// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    vector<int>::iterator it;
    for (int i = 0; i <= 5; ++i) {
        v.push_back(i);
    }
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}