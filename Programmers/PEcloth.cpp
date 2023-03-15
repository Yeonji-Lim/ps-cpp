// 42862
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool donan = false;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(int i = 0; i < reserve.size(); i++) {
        for(int j = 0; j < lost.size(); j++) {
            if(reserve[i] == lost[j]) {
                lost.erase(lost.begin() + j);
                donan = true;
                break;
            }
        }
        if(donan) {
            donan = false;
            continue;
        }
        for(int j = 0; j < lost.size(); j++) {
            if(lost[j] == reserve[i]+1 || lost[j] == reserve[i]-1) {
                lost.erase(lost.begin() + j);
                break;
            }
        }
    }
    answer = n-lost.size();
    return answer;
}