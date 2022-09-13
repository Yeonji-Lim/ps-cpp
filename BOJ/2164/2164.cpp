#include <bits/stdc++.h>
#define MXS 1000001
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int q[MXS], h = 0, t = 0;
    for(; t < n; t++) {
        q[t] = t+1;
    }
    while(t-h > 1) {
        h++;
        q[t++] = q[h];
        h++;
    }
    cout << q[t-1];
}