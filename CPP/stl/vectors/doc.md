    // Create a vector of size 5 with
    // all values as 10.
    
    vector<int> v(5, 10);
    
    // This vector initializes with the values: 10, 20, and 30
    
    vector<int> v{ 10, 20, 30 }; 

    // iterator 
    vector<int> v;
    vector<int>::iterator it;
    for (int i = 0; i <= 5; ++i) {
        v.push_back(i);
    }
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }