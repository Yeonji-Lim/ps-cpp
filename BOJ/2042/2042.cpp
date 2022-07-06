#include <bits/stdc++.h>
using namespace std;
vector<long long> it(1024*1024*2);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    long long a, b, c, i, tmpn = 1, com;
    cin >> n >> m >> k;
    for(i = n; i > 0; i = i >> 1) tmpn = tmpn << 1;
    for(i = 0; i < n; i++) {
        cin >> it[i+tmpn];
    }
    for(i = (tmpn << 1)-1; i > 0; i-=2) {
        it[i>>1] = it[i]+it[i-1];
    }
    for(i = 0; i < m+k; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            b += tmpn-1;
            com = c-it[b];
            for(int j = b; j > 0; j = j>>1) it[j] += com;
        } else {
            com = 0;
            b += tmpn-1;
            c += tmpn-1;
            while(b <= c) {
                if((b&1) == 1) com += it[b];
                if((c&1) == 0) com += it[c];
                b = (b+1) >> 1;
                c = (c-1) >> 1;
            }
            cout << com << '\n';
        }
    }
}