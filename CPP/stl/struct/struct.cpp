#include<iostream>

using namespace std;

int main() {
    struct Node {
        Node *yo[2];
        bool flag;
        Node() : flag(false){}
    };
    Node s;

    struct foo {
        int bar;
        foo(int x) : bar(x) {}   //look, a constructor
        int getBar() { 
            return bar; 
        }
    };
    foo f(4);
    int y = f.getBar(); // y is 3

    // struct ListNode {
    //     int val;
    //     ListNode *next;
    //     ListNode(int x) : val(x), next(NULL) {}
    // };
    // ListNode node(4);
    // cout << y  endl;
    return 0;
}