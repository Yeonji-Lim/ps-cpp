#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> v;

void go(int li, int cnt) {
    if(cnt == m) {
        for(int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = li; i <= n; i++) {
        v.push_back(i);
        go(i, cnt+1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    go(1, 0);
    return 0;
}