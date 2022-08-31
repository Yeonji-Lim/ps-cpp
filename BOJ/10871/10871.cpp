#include <bits/stdc++.h>
using namespace std;
int n, x, tmp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(tmp < x) {
            cout << tmp << " ";
        }
    }
}