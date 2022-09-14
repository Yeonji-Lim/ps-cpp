#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int x = a*d+c*b, y = b*d;
    int div = gcd(x, y);
    cout << x/div << " " << y/div << '\n';
    // int div = gcd(a, b);
    // a /= div; b /= div;
    // div = gcd(c, d);
    // c /= div; d /= div;
    // div = gcd(b, d);
    // cout << (a*d+c*b)/div << " " << (b*d)/div << '\n';
    return 0;
}