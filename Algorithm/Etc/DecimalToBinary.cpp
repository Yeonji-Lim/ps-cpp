#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 7; i >= 0; i--) {
        if((n >> i) & 1) cout << "1";
        else cout << "0";
    }
}