#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
int n, m, len;

long long cutRst(int height) {
    long long ret = 0, tmp;
    for(int i = 0; i < n; i++) {
        tmp = tree[i]-height;
        if(tmp > 0) ret += tmp;
    }
    return ret;
}

int main() {
    int tmp = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> len;
        tree.push_back(len);
        tmp = max(len, tmp);
    }
    int l = 0, r = tmp, mid, ans = 0;
    long long com;
    while(l <= r) {
        mid = (l+r)/2;
        com = cutRst(mid);
        if(com == m) {
            ans = mid;
            break;
        } else if(com > m) {
            l = mid+1;
            ans = max(ans, mid);
        } else {
            r = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}