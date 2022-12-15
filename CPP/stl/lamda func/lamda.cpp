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

void printVector(vector<int> v) {
    // lambda expression to print vector
    for_each(v.begin(), v.end(), [](int i)
    {
        std::cout << i << " ";
    });
    cout << endl;
}


int main() {

    vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};

    printVector(v);

    sort(v.begin(), v.end(), [](int a, int b) {
        // cout << a << " " << b << " " << endl; 
        return a == b;
    });
    printVector(v);

    printVector(v);

    return 0;
}