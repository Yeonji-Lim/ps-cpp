#include <bits/stdc++.h>
using namespace std;
#define MAXNUM 1000000000;
#define MINNUM -1000000000;

int main() {
    int n;
    int nums[11], tmp;
    vector<int> ops;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < 4; i++) {
        cin >> tmp;
        while(tmp-- != 0) ops.push_back(i);
    }

    int ans = nums[0]; int minans = MAXNUM; int maxans = MINNUM;
    do {
        for(int i = 0; i < n-1; i++) {
            switch(ops[i]) {
                case 0: ans += nums[i+1]; break;
                case 1: ans -= nums[i+1]; break;
                case 2: ans *= nums[i+1]; break;
                case 3: ans /= nums[i+1]; break;
            }
        }
        minans = min(minans, ans);
        maxans = max(maxans, ans);
        ans = nums[0];
    } while(next_permutation(ops.begin(), ops.end()));
    cout << maxans << endl << minans << endl;
    return 0;
}