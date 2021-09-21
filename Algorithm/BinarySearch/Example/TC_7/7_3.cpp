#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    int rc [1000000];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> rc[i];
    }
    sort(rc, rc+n);
    int l = 0, r = n-1, mid, ans, tmp;
    while(l < r) {
        tmp = 0;
        mid = (l+r)/2;
        ans = rc[mid];
        for(int i = mid+1; i < n; i++) {
            tmp += rc[i]-ans;
        }
        if(tmp == m) {
            break;
        } else if(tmp > m) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}