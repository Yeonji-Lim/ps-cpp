#include <iostream>
#define MS 500000
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,maxv=-10,maxi=-1;
	string num;
	int a[MS];
	cin >> n >> k >> num;
	
	for(int i =0;i<n-1;i++){
		a[i] = num[i+1]-num[i];
		if(maxv < a[i]) {
			maxv = a[i];
			maxi = i;
		}
	}
	a[n-1] = 1;
	if(maxv < a[n-1]) {
		maxv = a[n-1];
		maxi = n-1;
	}
	int li,ri;
	while(k--){
		num[maxi] = 'x';
		a[maxi] = -11;
		for(li = maxi-1; li > -1 && num[li] == 'x'; li--);
		for(ri = maxi+1; ri < n && num[ri] == 'x'; ri++);
		if(li != -1) {
			if(ri == n) a[li] = 1;
		    else a[li] = num[ri]-num[li];
	    } 
	    maxv = -10;
		for(int i = 0; i < n; i++){
			if(num[i] == 'x') continue;
			if(maxv < a[i]) {
				maxv = a[i];
				maxi = i;
			}
		}
		
		cout << num << '\n';
		for(int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	for(int i = 0; i < n; i++)
	    if(num[i] != 'x') cout << num[i];
	return 0;
}
