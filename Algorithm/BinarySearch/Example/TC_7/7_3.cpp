#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, l = 0, r = 0, mid, sum;
    int rc [1000000];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> rc[i];
        if(r < rc[i]) r = rc[i];
    }
    while(l < r) {
        sum = 0;
        mid = (l+r)/2;
        for(int i = 0; i < n; i++) {
            if(rc[i] > mid) sum += rc[i]-mid;
        }
        if(sum == m) {
            break;
        } else if(sum > m) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << mid << '\n';
    return 0;
}