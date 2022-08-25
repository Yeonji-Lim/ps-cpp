#include <bits/stdc++.h>
using namespace std;
int n, x, tmp;
bool num[2000001];
// x가 2000000까지 갈 수 있다. -> x-i도 1999999까지 참조할 수 있음

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
    for(int i = 1; i < (x+1)/2; i++) { // i < (x+1)/2로 두면 짝수여서 두 수가 같은 경우에 대한 처리를 해주지 않아도 된다.
        if(num[i] && num[x-i]) tmp++;
    }
    cout << tmp;
}