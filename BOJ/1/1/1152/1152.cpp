#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio();
	cin.tie();
	int ans = 0;
	bool start = false;
	string str;
	getline(cin, str);
	str += ' ';
	for(int i = 0; i<str.length(); i++){
		if(!start) {
			start = true;
		} else {
			if(str[i]==' ') ans++;
		}
	}
	cout << ans;
}