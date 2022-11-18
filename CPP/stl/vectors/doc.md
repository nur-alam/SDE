###### vector declaration
    // Create a vector of size 5 with
    // all values as 10.
    vector<int> v(5, 10);

    // Uniform initialization
    vector<int> v{ 10, 20, 30 }; 

    // Initializer list
    vector<int> v = {1, 2, 3, 4, 5};

###### vector iteration
    // iterator 
    vector<int> v;
    vector<int>::iterator it;
    for (int i = 0; i <= 5; ++i) {
        v.push_back(i);
    }
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
###### sort
    sort(v.begin(), v.end());
    sort(v.begin(), v.begin() + 2);
###### Access Elements of a Vector
    vector<int> num {1, 2, 3, 4, 5};
    cout << num.at(0) << endl;
###### Changing Vector element
    v.at(1) = 9;
    v.at(4) = 7
    v[0] = 12;
###### Inserting in a Vector
    v.insert(v.begin() + 3, 100);
    
    assigns new values to the vector elements by replacing old ones
    vectorname.assign(int size, int initializeValue)
    v.assign(7, 100); 

    int a[] = { 1, 2, 3 };
    v1.assign(a, a + 2);

    // modify the elements
    v.assign(v.begin(), v.begin() + 3);
###### Methods
    v.clear();

    v.erase(iterator);
    v.erase(it1, it2);

    vec.resize(12);
    vec.resize(12, 9); // initialize with 9
    
    v.capacity(); 0(1)
    v.reserve(N); O(n)
    v.empty(); O(1)
    v.size()