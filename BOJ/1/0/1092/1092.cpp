// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n, m, tmp, ans = 0;
//     vector<int> crane;
//     vector<int> item;
//     vector<int> cover;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         cin >> tmp;
//         crane.push_back(tmp);
//     }
//     sort(crane.begin(), crane.end());
//     cin >> m;
//     for(int i = 0; i < m; i++) {
//         cin >> tmp;
//         item.push_back(tmp);
//     }
//     sort(item.begin(), item.end());
//     int cur_crane, l, r, mid;
//     for(int i = 0; i < crane.size(); i++) {
//         cur_crane = crane[i];
//         cout << cur_crane << '\n';
//         l = 0; r = item.size()-1;
//         while(l + 1 < r) {
//             // cout << l << ' ' << r << '\n';
//             mid = (l + r)/2;
//             if(item[mid] > cur_crane) { // mid 값이 큼, 그 값을 포함해서 작은 부분 보기
//                 r = mid;
//             } else {
//                 l = mid;
//             }
//         }
//         mid = (l+r)/2;
//         // cout << l << ' ' << r << ' ' << mid << '\n';
//         if(item[r] <= cur_crane) cover.push_back(r);
//         else if(item[mid] <= cur_crane) cover.push_back(mid);
//         else cover.push_back(l);
//     }
//     // cout << cover[cover.size()-1] << '\n';
//     if(cover[cover.size()-1] != item.size()-1) {
//         cout << "-1\n";
//         return 0;
//     }
//     ans = 1;
//     for(int i = cover.size()-1; i > 0; i--) {
        
//         cover[i] -= cover[i-1];cout << cover[i] << ' ';
//         ans = max(ans, cover[i]);
//     }
//     cout << "ans : " <<  ans << '\n';
//     tmp = cover[0]%crane.size()? 1: 0;
//     cout << '\n'<< cover[0]/(int)crane.size()+tmp << '\n';
//     ans += cover[0]/(int)crane.size()+tmp;
//     cout << ans << '\n';
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, tmp, ans = 0;
    vector<int> crane;
    vector<int> item;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        crane.push_back(tmp);
    }
    sort(crane.rbegin(), crane.rend());
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        item.push_back(tmp);
    }
    sort(item.rbegin(), item.rend());
    if(item[0] > crane[0]) {
        cout << "-1\n";
        return 0;
    }
    while(!item.empty()) {
        // cout << item.size() << '\n';
        for(int i = 0; i < crane.size(); i++) {
            tmp = 0;
            for(int j = 0; j < item.size(); j++) {
                if(crane[i] >= item[j]) {
                    item.erase(item.begin()+j);
                    tmp = 1;
                    break;
                }
            }
            if(tmp==0) {
                crane.erase(crane.begin()+i);
                i--;
                break;
            }
        }
        ans++;
    }
    cout << ans << '\n';
    return 0;
}