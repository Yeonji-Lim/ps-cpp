int lonelyinteger(vector<int> a) {
    set<int> s;
    for(int num: a) {
        if(s.empty() || s.find(num) == s.end()) {
            s.insert(num);
        } else {
            s.erase(s.find(num));
        }
    }
    return *s.begin();
}