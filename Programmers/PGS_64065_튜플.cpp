#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string tmp = "";
    int num[101010] = {0,};
    vector<pair<int, int>> counter;
    for(char ch : s) {
        if(ch >= '0' && ch <= '9') {
            tmp += ch;
        } else if(tmp.length()) {
            num[stoi(tmp)]++, tmp.clear();
        }
    }
    for(int i = 1; i < 101010; i++) {
        if(num[i]) {
            counter.emplace_back(num[i], i);
        }
    }
    sort(counter.begin(), counter.end());
    reverse(counter.begin(), counter.end());
    for(int i = 0; i < counter.size(); i++) {
        answer.push_back(counter[i].second);
    }
    return answer;
}