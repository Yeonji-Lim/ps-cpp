#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp, pre, pos = 0;
    cin >> n;
    vector<int> height;
    vector<int> answer;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        height.push_back(tmp);
        if(answer.empty()) {
            answer.push_back(0);
            continue; 
        }
        pos = i-1;
        while(pos > -1 && height[pos] < tmp) {
            pos = answer[pos]-1;
        }
        if(pos > -1) {
            answer.push_back(pos+1);
        } else {
            answer.push_back(0);
        } 
    }
    for(int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
}