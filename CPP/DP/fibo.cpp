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
// 0 1 2 3 5 8 13 21 34
// int fib(int n) {
//     if(n <= 1)
//         return n;
//     return fib(n - 1) + fib(n - 2);
// }
int memo[100];
int fib(int n) {
    if(n <= 1)
        return n;
    if(memo[n] != 0)
        return memo[n];
    else 
        return memo[n] = fib(n - 1) + fib(n - 2);
    // return memo[n];
}

int main() {

    int n = 9;
    cout << fib(n) << endl;
    return 0;
}