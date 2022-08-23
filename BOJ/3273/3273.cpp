#include <bits/stdc++.h>
using namespace std;
int n, x, tmp;
bool num[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> tmp;
        num[tmp] = true;
    }
    cin >> x;
    tmp = 0;
    for(int i = 1; i <= x/2; i++) {
        if(num[i] && num[x-i]) tmp++;
    }
    cout << tmp;
}