#include <bits/stdc++.h>
using namespace std;
int n, x, tmp;
bool num[2000001];

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
        if(i == x-i) break;
        if(num[i] && num[x-i]) tmp++;
    }
    // x가 2000000까지 갈 수 있다. -> x-i도 1999999까지 참조할 수 있음
    cout << tmp;
}