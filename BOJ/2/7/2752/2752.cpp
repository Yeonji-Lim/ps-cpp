#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num[3];
    for(int i = 0; i < 3; i++) {
        cin >> num[i];
    }
    sort(num, num + 3);
    for(int i = 0; i < 3; i++) {
        cout << num[i] << ' ';
    }
}