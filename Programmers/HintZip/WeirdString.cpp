// 12930
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool isWord;
    int j;
    for(int i = 0; i < s.size(); i++) {
        if(isWord) {
            if(s[i] == ' ') {
                isWord = false;
            } else {
                if(j%2) {
                    if(s[i] < 'a') s[i] -= 'A' - 'a';
                } else {
                    if(s[i] >= 'a') s[i] -= 'a' - 'A';
                }
                j++;
            }
        } else if(s[i] != ' ') {
            isWord = true;
            j = 0;
            i--;
        }
    }
    return s;
}