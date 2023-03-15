// 42862
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) { return a > b? a: b; }

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    bool donan = false;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for(int i = 0; i < reserve.size(); i++) {
        for(int j = 0; j < lost.size(); j++) {
            if(reserve[i] == lost[j]) {
                lost.erase(lost.begin() + j);
                reserve.erase(reserve.begin() + i);
                i--;
                break;
            }
        }
    }
    vector<int> temp = lost;
    for(int i = 0; i < reserve.size(); i++) {
        for(int j = 0; j < temp.size(); j++) {
            if(temp[j] == reserve[i]+1 || temp[j] == reserve[i]-1) {
                temp.erase(temp.begin() + j);
                break;
            }
        }
    }
    answer = n-temp.size();
    for(int i = 0; i < reserve.size(); i++) {
        for(int j = lost.size()-1; j > -1; j--) {
            if(lost[j] == reserve[i]+1 || lost[j] == reserve[i]-1) {
                lost.erase(lost.begin() + j);
                break;
            }
        }
    }
    answer = max(answer, n-lost.size());
    return answer;
}