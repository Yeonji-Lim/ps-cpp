#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool first = true;
    for(int i = 0; i < s.length(); i++) {
        if(first) {
            if(s[i]  >= 'a' && s[i] <='z') 
                s[i] -= 'a'-'A';
            first = false;
        } else {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] -= 'A'-'a';
        }
        if(s[i] == ' ')
            first = true;
    }
    return s;
}