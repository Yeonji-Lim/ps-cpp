#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    cin >> word;
    int ans = 0;
    for(int i = 0; i < word.length(); i++){
        if(word[i] < 'D') ans += 3; else if(word[i] < 'G') ans += 4;
        else if(word[i] < 'J') ans += 5; else if(word[i] < 'M') ans += 6;
        else if(word[i] < 'P') ans += 7; else if(word[i] < 'T') ans += 8;
        else if(word[i] < 'W') ans += 9; else ans += 10;
    } 
    cout << ans << endl;
}