// 42627
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) { return a[1] > b[1]; }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    vector<int> item;
    int time = 0, i = 0, s = jobs.size();
    while(1) {
        if(i == s) {
            while(!pq.empty()) {
                item = pq.top();
                time += item[1];
                answer += time - item[0];
                pq.pop();
            }
            break;
        }
        while(i < s) {
            if(jobs[i][0] > time) break;
            pq.push(jobs[i]);
            i++;      
        }
        if(pq.empty()) {
            pq.push(jobs[i++]);
            time = pq.top()[0];
        }
        item = pq.top();
        time += item[1];
        answer += time - item[0];
        pq.pop();
    }
    answer /= s;
    return answer;
}