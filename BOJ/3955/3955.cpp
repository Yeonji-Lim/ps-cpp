#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int euclidean(int s, int t, int r, int s1, int t1, int r1) {
    if(r == 1) return t;
    if(r == -1) return -1*t;
    int q = r/r1, r2 = r%r1;
    return euclidean(s1, t1, r1, s-s1*q, t-t1*q, r2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int T, K, C, div, e;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> K >> C;
        K *= -1;
        div = gcd(K, C);
        if(div == 1 || div == -1) {
            e = euclidean(1, 0, K, 0, 1, C);
            if(e < 0) e -= K;
            div *= e;
            if(div < 0) div *= -1;
            cout << div << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}