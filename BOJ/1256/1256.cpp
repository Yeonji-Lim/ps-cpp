#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, cnt = 1;
    cin >> n >> m >> k;
    vector<bool> perm(n+m, false);
    fill(perm.end()-m, perm.end(), true); // true : z
    do {
        if(cnt == k) {
            for(int i = 0; i < n+m; i++) {
                if(!perm[i]) cout << 'a';
                else cout << 'z';
            }
            cout << '\n';
            break;
        }
        cnt++;
    } while(next_permutation(perm.begin(), perm.end()));
    return 0;
}