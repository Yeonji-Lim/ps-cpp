/* Parametric Search */

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
    
//     int n, m, l = 0, r = 0, mid, sum;
//     int rc [1000000];
//     cin >> n >> m;
//     for(int i = 0; i < n; i++) {
//         cin >> rc[i];
//         if(r < rc[i]) r = rc[i];
//     }
//     while(l < r) {
//         sum = 0;
//         mid = (l+r)/2;
//         for(int i = 0; i < n; i++) {
//             if(rc[i] > mid) sum += rc[i]-mid;
//         }
//         if(sum == m) {
//             break;
//         } else if(sum > m) {
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }
//     cout << mid << '\n';
//     return 0;
// }

#include <iostream>
using namespace std;
int N, M;
int dd[1000000];

int BS(int prem, int l, int r) {
    if(l > r) return prem;
    int m = (l+r)/2;
    int rem = 0;
    for(int i = 0; i < N; i++) {
        if(dd[i] > m) rem += dd[i] - m;
    }

    if(rem < M) return BS(prem, l, m-1);
    else if (rem > M) return BS(m, m+1, r);
    else return m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> dd[i];
        if(r < dd[i]) r = dd[i];
    }
    r = BS(-1, 0, r);
    cout << r << endl;
    return 0;
}