#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    list<int> L = {};
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        L.push_back(i);
    }
    auto iter = L.begin();
    cout << '<';
    while(!L.empty()) {
        for(int i = 1; i < k; i++) {
            if(iter != L.end()) {
                iter++;
            } else {
                iter = L.begin();
                i--;
            }
        }
        if(iter == L.end()) iter = L.begin();
        cout << *iter;
        iter = L.erase(iter);

        if(!L.empty()) cout << ", ";
        else {
            cout << ">\n";
            break;
        }
    }
}