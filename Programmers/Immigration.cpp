// 43238
#include <string>
#include <vector>
#define MT 1000000000

using namespace std;

long long solution(int n, vector<int> times) {
    int s = times.size();
    int min_time = MT;
    int min_t;
    vector<int> wait(s, 1);
    for(int i = 0; i < n; i++) {
        for(int t = 0; t < s; t++) {
            if(min_time > times[t]*wait[t]) {
                min_time = times[t]*wait[t];
                min_t = t;
            }
        }
        wait[min_t]++;
        if(i == n-1) break;
        min_time = MT;
    }
    return min_time;
}