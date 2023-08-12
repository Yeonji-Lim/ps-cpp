#include <iostream>

using namespace std;

int n,h,t,mini;
int u[500001], d[500001], 
    ansl[500001], jans[200001];

int main(){
	cin >> n >> h;
	for(int i = 0; i < n; i++){
		cin >> t;
		if (i%2==0) u[t]++;
		else d[t]++;
	}
	for(int i = 1; i < h; i++){
		ansl[0] += u[i];
	}
	jans[ansl[0]]++;
	mini=ansl[0];
	for(int i = 1; i < h; i++){
		ansl[i] = ansl[i-1]-u[i]+d[h-i];
		jans[ansl[i]]++;
		mini = min(mini, ansl[i]);
	}
	cout << mini << ' ' << jans[mini] << '\n';
	return 0;
}