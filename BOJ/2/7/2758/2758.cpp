#include <iostream>

using namespace std;

int t,n,m,ans;
int dp[11][2001];

int choose(int tn, int tm) {
    if(tn > tm) return -1;
	if(dp[tn][tm]!=0) return dp[tn][tm];
	if(tn == 1) dp[tn][tm] = tm;
	else {
	    for(int i=0; 2*i+1 < tm && tn <= tm-2*i; i++) {
	    	dp[tn][tm] += choose(tn-1,tm-2*i-1);
	    }
	}
	return dp[tn][tm];
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		ans = choose(n,m);
        if(ans > 0) cout << ans << '\n';
        else cout << "-1\n";
	}
	return 0;
}