// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include<algorithm>
using namespace std;

int main() {
    vector<int> v;
    vector<int>::iterator it;
    for (int i = 10; i >= 5; i--) {
        v.push_back(i);
    }
    // sort(v.begin(), v.end());
    // v.erase(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}