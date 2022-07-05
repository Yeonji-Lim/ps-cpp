#include <bits/stdc++.h>
#define M 1000000
using namespace std;
typedef unsigned long long ull;

vector<vector<ull>> vectorSquared(vector<vector<ull>> a, vector<vector<ull>> b) {
    vector<vector<ull>> ret(2, vector<ull>(2, 0));
    ret[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % M;
    ret[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % M;
    ret[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % M;
    ret[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % M;
    return ret;
}

int main() {
    long long n;
    cin >> n;
    if(n < 2) {
        cout << n << endl;
        return 0;
    }
    n-=2;
    vector<vector<ull>> a = {{1, 1}, {1, 0}};
    vector<vector<ull>> b = {{1, 0}, {0, 1}};
    for(int i = n; i > 0; i = i >> 1) {
        if(i & 1) {
            b = vectorSquared(a, b);
        }
        a = vectorSquared(a, a);
    }
    cout << b[0][0] << endl;
    return 0;
}