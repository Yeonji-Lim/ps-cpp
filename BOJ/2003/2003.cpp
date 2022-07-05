#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;

int main() {
    int n, m, tmp, ans = 0, l = 0, r = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    tmp = nums[l];
    while(r < nums.size()) {
        if(tmp == m) {
            ans++;
            tmp -= nums[l];
            l++; r++;
            tmp += nums[r];
        } else if(tmp < m) {
            r++;
            tmp += nums[r];
        } else {
            tmp -= nums[l];
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}