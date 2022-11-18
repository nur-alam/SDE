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
    sort(v.begin(), v.end());
    sort(v.begin(), v.begin() + 2);
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // int a[5] = {4, 5, 1, 2, 3};
    // sort(a, a + 3);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    return 0;
}