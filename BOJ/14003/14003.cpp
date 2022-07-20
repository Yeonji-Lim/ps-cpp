#include <bits/stdc++.h>
#define SIZE 1000001
using namespace std;
int nums[SIZE];
int d[SIZE];
int p[SIZE];
deque<int> ans;
int n, num;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];

    d[0] = 1; p[0] = -1;
    int a = 0, a_i = -1;
    int b = 1, b_i = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j > -1; j--) {
            if(nums[j] < nums[i] && nums[j] > a) {
                a = nums[j];
                a_i = j;
            }
        }
        if(a_i != -1) d[i] = d[a_i]+1;
        else d[i] = 1;
        p[i] = a_i;
        if(d[i] > b) {
            b = d[i];
            b_i = i;
        }
        a = 0; a_i = -1;
    }
    cout << b << '\n';
    while(b_i != -1) {
        ans.push_back(nums[b_i]);
        b_i = p[b_i];
    }
    while(!ans.empty()) {
        cout << ans.back() << " ";
        ans.pop_back();
    }
    cout << '\n';
    return 0;
}