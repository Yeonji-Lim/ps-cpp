// #include <iostream>
// #include <vector>
// using namespace std;

// int N, K;
// vector<int> food_times;

// void next(int &x) {
//     if(x == N-1) x = 0;
//     else ++x;
// } 

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
    
//     cin >> N >> K;
//     food_times.resize(N, 0);
//     for(int i = 0; i < N; i++) {
//         cin >> food_times[i];
//     }

//     int cur = 0, ck = 0;
//     for(int i = 0; i < K; i++) {
//         while(food_times[cur] == 0 && ck < N) {
//             ck++;
//             next(cur);
//         }
//         if(ck == N) {
//             cur = -1;
//             break;
//         }
//         food_times[cur]--;
//         next(cur);
//     }

//     if(cur != -1) ++cur;
//     cout << cur << endl;
//     return 0;
// }

// 위와 같이 하면 시간초과..
// https://programmers.co.kr/learn/courses/30/lessons/42891

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool idxCmp (pair<int, int> x, pair<int, int> y) { return x.second < y.second; }

int solution(vector<int> food_times, long long k) {
    int size = food_times.size(), prev = 0, i;
    long long spend = 0;
    
    vector<pair<int, int>> pq;
    for(i = 0; i < size; i++) {
        pq.emplace_back(food_times[i], i+1);
        spend += food_times[i];
    }
    
    if(spend <= k) return -1;
    
    sort(pq.begin(), pq.end());
    for(i = 0; i < pq.size(); i++, size--) {
        spend = (long long)(pq[i].first - prev) * size;
        if(spend > k) break;
        k -= spend;
        prev = pq[i].first;
    }
    
    sort(pq.begin()+i, pq.end(), idxCmp);
    return pq[k%size+i].second;
}