#include <iostream>

using namespace std;

int t,n,m;
long long ans = 0, tmp;
long long dp[11][2001];

long long choose(int tn, int tm) {
    if(tm <= 0) return 0;
    if(dp[tn][tm] != 0) return dp[tn][tm];
    if(tn == 1) dp[tn][tm] = 1;
    else if(tm == 1) dp[tn][tm] = 0;
    else dp[tn][tm] = choose(tn-1, tm/2) + choose(tn, tm-2);
    return dp[tn][tm];
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
        for(int i = m; i > -1; i--) {
            tmp = choose(n, i);
            if(tmp == 0) break;
            ans += tmp;
        }
        cout << ans << '\n';
        ans = 0;
	}
	return 0;
}