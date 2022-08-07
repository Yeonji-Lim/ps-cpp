#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, less<int>> small;
priority_queue<int, vector<int>, greater<int>> big;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n, num, mid, si = 0, bi = 0, com;
    cin >> n;
    cin >> num;
    cout << num << '\n';
    mid = num;
    for(int i = 1; i < n; i++) {
        cin >> num;
        if(num > mid) {
            big.push(num);
            bi++;
        } else {
            small.push(num);
            si++;
        }
        com = si-bi;
        if(com > 0) {
            big.push(mid);
            bi++;
            mid = small.top();
            small.pop();
            si--;
        } else if(com < -1) {
            small.push(mid);
            si++;
            mid = big.top();
            big.pop();
            bi--;
        }
        cout << mid << '\n';
    }
    return 0;
}