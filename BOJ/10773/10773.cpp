#include <bits/stdc++.h>
using namespace std;
int st[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, tmp, pos = 0, answer = 0;
    cin >> k;
    while(k--) {
        cin >> tmp;
        if(tmp == 0) {
            if(pos > 0) pos--;
        } else {
            st[pos] = tmp;
            pos++;
        }
    }
    for(int i = 0; i < pos; i++) {
        answer += st[i];
    }
    cout << answer;
}