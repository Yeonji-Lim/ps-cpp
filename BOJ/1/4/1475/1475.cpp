#include <bits/stdc++.h>
using namespace std;
int n, idx, answer = 0, maxidx;
int num[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n != 0) {
        idx = n%10;
        num[idx]++;
        if(answer < num[idx]) {
            answer = num[idx];
            maxidx = idx;
        } else if(answer == num[idx]) {
            if((maxidx == 6 || maxidx == 9) && (idx != 6 && idx != 9)) maxidx = idx;
        }
        n /= 10;
    }
    if(maxidx == 6 || maxidx == 9) {
        answer = num[6] + num[9];
        if(answer&1) answer++;
        answer = answer >> 1;
    }
    cout << answer;
}