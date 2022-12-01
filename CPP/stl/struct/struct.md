Let us consider an example. Consider a Linked List in which each node is represented by:

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x){
        val = x;
        next = NULL;
     }
};
To initialize a node with value 5 and next pointer pointing to NULL you can write the code snippet as:

ListNode node = new ListNode();
node.val = 5;
node.next = NULL;
or

ListNode node = new ListNode(5);
Another fancy declaration can be made as

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
Here ListNode(int x): val(x), next(NULL) is a constructor which initializes the value of the struct ListNode.

Hope this make things more clear and easy. :)


#### another example
```
\#include \<iostream>
using namespace std;

struct A{
     int a;
     A(int i=0) : a(i) { 
          cout << "A" << endl; 
     }
     ~A() { 
          cout << "Bye A" << endl; 
     }
     int foo() { 
          return a; 
     }
};
struct B{
     int b;
     B(int i=0) : b(i) { 
          cout << "B" << endl; 
     }
     ~B() { 
          cout << "Bye B" << endl; 
     }
     int bar() { return b; }
};
struct C : B, A {
    C(int i=0) : B(foo()), A(i) {}
};

int main() {
    cout << C(10).bar() << endl;
    return 0;
}
```
