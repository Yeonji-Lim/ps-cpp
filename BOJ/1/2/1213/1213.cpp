#include <iostream>
using namespace std;
int alpha[26];
int odd = 0, oddi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        alpha[str[i]-'A']++;
    }
    for(int i = 0; i < 26; i++) {
        if(alpha[i]%2) {
            odd++;
            oddi = i;
        }
    }
    if(odd > 1) cout << "I'm Sorry Hansoo\n";
    else {
        str = "";
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < alpha[i]/2; j++) {
                str += (char)(i+'A');
            }
        }
        if(odd) str += (char)(oddi+'A');
        for(int i = 25; i > -1; i--) {
            for(int j = 0; j < alpha[i]/2; j++) {
                str += (char)(i+'A');
            }
        }
        cout << str << '\n';
    }
    
}