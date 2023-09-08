#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> p, int l) {
    int answer = 0, k;
    pair<int, int> t;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    for(int i = 0; i < p.size(); i++) {
        pq.push(p[i]);
        q.push({p[i], i});
    }
    while(!pq.empty()) {
        k = pq.top();
        while(k != q.front().first) {
            t = q.front();
            q.pop();
            q.push(t);
        }
        pq.pop();
        answer++;
        if(q.front().first == p[l] && q.front().second == l) break;
        q.pop();
    }
    return answer;
}

/*
우선순위 큐에 같이 넣어가지고 우선순위 제일 높은게 지금거가 아니면 다시
*/