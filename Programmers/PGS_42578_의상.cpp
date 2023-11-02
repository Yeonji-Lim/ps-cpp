#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(vector<string> cl : clothes) {
        if(m.find(cl[1]) == m.end()) 
            m.insert({cl[1], 1});
        else
            m[cl[1]]++;
    }
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        answer *= (iter->second)+1;
    }
    return answer-1;
}