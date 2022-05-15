// https://programmers.co.kr/learn/courses/30/lessons/60062

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void fixing (int start, int dist, vector<int> weak, vector<bool> &fixed) {
    int end = start + dist;
    int real_size = weak.size()/2;
    for(int i = 0; i < weak.size(); i++) {
        if(start <= weak[i] && weak[i] <= end) {
            fixed[i%real_size] = true;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size();
    bool done = true;
    
    vector<bool> fixed (weak.size(), false);
    for(int i = 0; i < weak.size(); i++) { weak.push_back(weak[i] + n); }
    
    do {
        for(int d = 2; d <= answer; d++) {
            // 기존의 answer보다 적은 친구들로 성공하면 answer 갱신
            for(int i = 0; i < d; i++) {
                // 이부분을 어떻게 구현해야 할 지 모르겠음..
                // 친구가 두명이면 첫번째 친구가 끝마친 곳부터 체크하고, 그거보다 한칸 더가서 체크하고,, 이런 식으로 하면 되지 않을 까 생각했는데
                // 그렇게 되면 3명부터 골치아파짐 어떻게 구현할 지.. 

                // d 명의 친구로 성공했는지 여부 체크 -> 이거 i for문 나가야 할 지 모르겠음 
                for(int j = 0; j < fixed.size(); j++) {
                    if(!fixed[j]) {
                        done = false;
                        break;
                    }
                }
            }
            if(done) { answer = d; break; }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    return answer;
} 