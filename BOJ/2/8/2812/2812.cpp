// #include <iostream>
// #define MS 500000
// using namespace std;

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	int n,k,maxv=-10,maxi=-1;
// 	string num;
// 	int a[MS];
// 	cin >> n >> k >> num;
	
// 	for(int i =0;i<n-1;i++){
// 		a[i] = num[i+1]-num[i];
// 		if(maxv < a[i]) {
// 			maxv = a[i];
// 			maxi = i;
// 		}
// 	}
// 	a[n-1] = 1;
// 	if(maxv < a[n-1]) {
// 		maxv = a[n-1];
// 		maxi = n-1;
// 	}
// 	int li,ri;
// 	while(k--){
// 		num[maxi] = 'x';
// 		a[maxi] = -11;
// 		for(li = maxi-1; li > -1 && num[li] == 'x'; li--);
// 		for(ri = maxi+1; ri < n && num[ri] == 'x'; ri++);
// 		if(li != -1) {
// 			if(ri == n) a[li] = 1;
// 		    else a[li] = num[ri]-num[li];
// 	    } 
// 	    maxv = -10;
// 		for(int i = 0; i < n; i++){
// 			if(num[i] == 'x') continue;
// 			if(maxv < a[i]) {
// 				maxv = a[i];
// 				maxi = i;
// 			}
// 		}
		
// 		cout << num << '\n';
// 		for(int i = 0; i < n; i++) {
// 			cout << a[i] << ' ';
// 		}
// 		cout << '\n';
// 	}
// 	for(int i = 0; i < n; i++)
// 	    if(num[i] != 'x') cout << num[i];
// 	return 0;
// }

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string num, ans = "";
	cin >> n >> k >> num;
	ans += num[0];
	for(int i = 1; i < n; i++) {
		// 현재 숫자보다 작은 앞자리 숫자 다 삭제, 계속해서 k--
		while(ans.length() && ans.back() < num[i] && k) {
			ans.pop_back();
			k--;
		}
		ans += num[i];
	}
	// 다 돌았는데도 k가 0이 아니면 뒤에서 부터 삭제
	cout << ans.substr(0, ans.length()-k) << '\n';
	return 0;
}