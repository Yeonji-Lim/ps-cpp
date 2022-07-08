#include <bits/stdc++.h>
using namespace std;
vector<int> joyaks(50, 0);

int main() {
    int m, k;
    double bunmo = 0, bunja = 0, tmp, tmp1;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> joyaks[i];
        bunmo += joyaks[i];
    }
    cin >> k;
    tmp = bunmo-1;
    for(int i = 1; i < k; i++) {
        bunmo *= tmp;
        tmp--;
    }
    for(int i = 0; i < m; i++) {
        tmp = joyaks[i];
        tmp1 = tmp-1;
        for(int j = 1; j < k; j++) {
            tmp *= tmp1;
            tmp1--;
        }
        bunja += tmp;
    }
    cout << fixed;
    cout.precision(18);
    cout << bunja/bunmo << '\n';
    return 0;
}