#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, K, C;

int gcd(int a, int b) {
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

ll euclidean(ll s, ll t, ll r, ll s1, ll t1, ll r1) {
    if(r1 == 1) return s1 == 0? t1+K: t1;
    if(r1 == -1) return s1 == 0? -t1+K: -t1;
    ll q = r/r1, r2 = r%r1;
    return euclidean(s1, t1, r1, s-s1*q, t-t1*q, r2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    int div; ll e;
    for(int t = 0; t < T; t++) {
        cin >> K >> C;
        div = gcd(-K, C);
        if(div == 1 || div == -1) {
            e = euclidean(1, 0, -K, 0, 1, C);
            if(e <= 0) e += K;
            if(e > 1000000000) {
                cout << "IMPOSSIBLE\n";
                continue;
            }
            cout << e << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}