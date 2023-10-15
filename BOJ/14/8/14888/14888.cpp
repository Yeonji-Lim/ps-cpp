// #include <bits/stdc++.h>
// using namespace std;
// #define MAXNUM 1000000000;
// #define MINNUM -1000000000;

// int main() {
//     int n;
//     int nums[11], tmp;
//     vector<int> ops;
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> nums[i];
//     for(int i = 0; i < 4; i++) {
//         cin >> tmp;
//         while(tmp-- != 0) ops.push_back(i);
//     }

//     int ans = nums[0]; int minans = MAXNUM; int maxans = MINNUM;
//     do {
//         for(int i = 0; i < n-1; i++) {
//             switch(ops[i]) {
//                 case 0: ans += nums[i+1]; break;
//                 case 1: ans -= nums[i+1]; break;
//                 case 2: ans *= nums[i+1]; break;
//                 case 3: ans /= nums[i+1]; break;
//             }
//         }
//         minans = min(minans, ans);
//         maxans = max(maxans, ans);
//         ans = nums[0];
//     } while(next_permutation(ops.begin(), ops.end()));
//     cout << maxans << endl << minans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// #define INF 1000000000
// using namespace std;
// vector<int> numbers(11);
// vector<int> perms;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     int n, tmp, max = -1 * INF, min = INF;
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         cin >> numbers[i];
//     }
//     for(int i = 0; i < 4; i++) {
//         cin >> tmp;
//         while(tmp != 0) {
//             perms.push_back(i);
//             tmp--;
//         }
//     }
//     do {
//         tmp = numbers[0];
//         for(int i = 1; i < n; i++) {
//             switch(perms[i-1]) {
//                 case 0: tmp += numbers[i]; break;
//                 case 1: tmp -= numbers[i]; break;
//                 case 2: tmp *= numbers[i]; break;
//                 case 3: tmp /= numbers[i]; break;
//             }
//         }
//         if(max < tmp) max = tmp;
//         if(min > tmp) min = tmp;
//     } while(next_permutation(perms.begin(), perms.end()));
//     cout << max << endl << min << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#define MINANS -1000000000
#define MAXANS 1000000000

using namespace std;
vector<int> nums;
vector<int> v;
int n, tmp, maxans = MINANS, minans = MAXANS;
int ops[4];

void go(int cnt) {
    if(cnt == n) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(v[i-1] == 0) {
                result += nums[i];
                continue;
            }
            if(v[i-1] == 1) {
                result -= nums[i];
                continue;
            }
            if(v[i-1] == 2) {
                result *= nums[i];
                continue;
            }
            if(v[i-1] == 3) {
                result /= nums[i];
                continue;
            }
        }
        maxans = max(result, maxans);
        minans = min(result, minans);
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(ops[i] != 0) {
            ops[i]--;
            v.push_back(i);
            go(cnt+1);
            v.pop_back();
            ops[i]++;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    for(int i = 0; i < 4; i++) {
        cin >> ops[i];
    }
    go(1);
    cout << maxans << '\n' << minans << '\n';
    return 0;
}