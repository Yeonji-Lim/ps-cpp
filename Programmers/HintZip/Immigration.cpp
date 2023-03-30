// 43238

// 한번에 최소 시간을 구하는 것은 무조건 시간 초과가 날 수 있다.
// 그런 경우 시점의 전환이 필요하다
// 원래 : 사람당 어떤 심사관에 대기해야 하는지
// 바꿈 : 해당 시간 안에 심사관 각각 몇명을 처리할 수 있는 지

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    long long mint = 1;
    long long maxt = (long long)(*max_element(times.begin(), times.end()))*(long long)(n);
    long long avgt;
    long long done = 0;
    while(mint <= maxt) {
        avgt = (mint+maxt)/2;
        for(int i = 0; i < times.size(); i++)
            done += avgt/(long long)(times[i]);
        if(done >= n) {
            answer = avgt;
            maxt = avgt-1;
        } else mint = avgt+1;
        done = 0;
    }
    return answer;
}