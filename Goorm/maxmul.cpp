#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t, cur = 1, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        t = i;
        while(t) {
            cur *= t%10;
            if(!cur) break;
            t /= 10;
        }
        ans = max(cur, ans);
        cur = 1;
    }
    cout << ans;
    return 0;
}