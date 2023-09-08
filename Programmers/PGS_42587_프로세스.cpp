#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> p, int l) {
    int answer = 0, t, k;
    priority_queue<int> pq;
    queue<int> q;
    for(int i = 0; i < p.size(); i++) {
        pq.push(p[i]);
        q.push(p[i]);
    }
    while(!pq.empty()) {
        k = pq.top();
        while(k != q.front()) {
            t = q.front();
            q.pop();
            q.push(t);
        }
        pq.pop();
        answer++;
        if(k == p[l]) break;
    }
    return answer;
}

/*
우선순위 큐에 같이 넣어가지고 우선순위 제일 높은게 지금거가 아니면 다시
*/