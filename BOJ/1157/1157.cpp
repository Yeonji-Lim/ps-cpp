#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     
    int A[26] = {0}, max, maxIdx = 0;
    string str;
    cin >> str;
    for(int i =0; i<str.length(); i++){
        if(str[i] >= 'a') A[str[i]-'a']++;
        else A[str[i]-'A']++;
    }
    max = A[0];
    for(int i=1; i < 26; i++){
        if(A[i] > max) {
            max = A[i];
            maxIdx = i;
        }
    }
    for(int i=1; i < 26; i++){
        if(i != maxIdx && A[i] == max) {
            cout << '?' << endl; return 0;
        }
    }
    char c = 'A'+maxIdx;
    cout << c << endl;
    return 0;
}