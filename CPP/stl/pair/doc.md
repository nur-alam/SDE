###### vector declaration
    pair<int, string>pair(12, "pair");
    vector<int>::iterator it;
    pair = make_pair(12, "pair");
    cout << pair.first << " " << pair.second << endl;

    pair<int, int> pair2 = { 3, 4 };

    vector < pair<int, string> > v;
    for (int i = 10; i >= 5; i--) {
        v.push_back(make_pair(i, "string"));
    }
    for(auto el : v) {
        cout << el.first << " " << el.second << "";
    }