#include <iostream>
#include <stack>

using namespace std;
string str;
string res="";
stack<char> st;

void reverseAppend() {
	while(!st.empty()) {
		res += st.top();
		st.pop();
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin, str);
	bool tag = false;
	for(char ch : str){
		if(ch== '<') {
			tag = true;
			reverseAppend();
		}
		if(tag) res += ch;
		else if(ch== ' ') {
			reverseAppend();
			res += ch;
		}
		else st.push(ch);
		if(ch == '>') tag = false;
	}
	reverseAppend();
	cout << res << '\n';
}