#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int has[1000000], buy[100000];

string binarySearch (int l, int r, int tar) {
    if(l > r) return "no";
    int mid = (l+r)/2;
    if(has[mid] == tar) {
        return "yes";
    } else if (has[mid] > tar) {
        return binarySearch(l, mid-1, tar);
    } else {
        return binarySearch(mid+1, r, tar);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tar;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> has[i];
    }
    sort(has, has+n);
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> tar;
        cout << binarySearch(0, n-1, tar) << ' ';
    }
    cout << '\n';
    return 0;
}