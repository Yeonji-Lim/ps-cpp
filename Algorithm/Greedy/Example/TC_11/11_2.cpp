#include <iostream>
using namespace std;

int max(int a, int b) { return a > b? a: b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S;

    cin >> S;
    int rst = S[0]-'0';
    for(int i = 1; i < S.length(); i++) {
        rst = max(rst+S[i]-'0', rst*(S[i]-'0'));
    }
    cout << rst << endl;
    
    return 0;
}