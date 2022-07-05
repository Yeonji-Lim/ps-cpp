#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
int n, m, len;

bool isValid(int height) {
    int l = 0, r = n-1, tot = 0, mid;
    while(l <= r) {        
        mid = (l+r)/2;
        if(tree[mid] == height){
            break;
        } else if(tree[mid] > height) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    if(l > r) mid = (l+r)/2+1;
    for(int i = mid; i < n; i++) 
        tot += tree[i]-height;
    if(tot >= m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> len;
        tree.push_back(len);
    }
    sort(tree.begin(), tree.end());
    int l = 0, r = tree[n-1], mid, ans = 0;
    while(l <= r) {
        mid = (l+r)/2;
        if(isValid(mid)) {
            l = mid+1;
            ans = max(ans, mid);
        } else {
            r = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}