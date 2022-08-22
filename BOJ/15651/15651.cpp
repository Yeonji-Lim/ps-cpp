#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;

void bt(int si) {
    v.push_back(si);
    if(v.size() == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
    }else {
        for(int i = 0; i <= n; i++) {
            bt(i);
        }
    }
    v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        bt(i);
    }
}