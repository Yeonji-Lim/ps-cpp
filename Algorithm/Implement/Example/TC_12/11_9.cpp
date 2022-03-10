#include <string>
#include <vector>

using namespace std;

int min(int a, int b) { return a < b? a: b; }

int solution(string s) {
    int answer, len = s.length(), cnt;
    string tmp, comps;
    
    answer = len;
    for(int u = 1; u <= len/2; u++) {
        cnt = 1;
        comps = "";
        for(int start = 0; start < u; start++) {
            tmp = s.substr(start, u);
            for(int i = start+u; i <= len-u; i += u) {
                if(s.substr(i, u) == tmp) { cnt++; }
                else {
                    if(cnt != 1) {
                        comps += to_string(cnt);
                        cnt = 1;
                    }
                    comps += tmp;
                    tmp = s.substr(i, u);
                }
            }
        }
        if(cnt != 1) comps += to_string(cnt);
        comps += tmp;
        answer = min(comps.length(), answer);
    }
    
    return answer;
}