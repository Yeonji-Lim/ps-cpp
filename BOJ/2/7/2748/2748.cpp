#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> vectorSquared(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> ret(2, vector<long long>(2, 0));
    ret[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    ret[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    ret[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    ret[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    return ret;
}

int main() {
    int n;
    cin >> n;
    n-=2;
    vector<vector<long long>> a = {{1, 1}, {1, 0}};
    vector<vector<long long>> b (2, vector<long long>(2, 1));
    for(int i = n; i > 0; i = i >> 1) {
        if(i & 1) {
            b = vectorSquared(a, b);
        }
        a = vectorSquared(a, a);
    }
    cout << b[0][0] << endl;
    return 0;
}