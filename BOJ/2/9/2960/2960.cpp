#include <bits/stdc++.h>
using namespace std;
vector<bool> num(1001, true);

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    for(int i = 2; i <= n; i++) {
        if(num[i]){
            for(int j = i; j <= n; j+=i) {
                if(!num[j]) continue;
                num[j] = false;
                cnt++;
                if(cnt == k) {
                    cout << j << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}