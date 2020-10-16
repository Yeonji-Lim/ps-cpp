#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int L;
    int data;
    deque<pair<int, int>> DQ;

    cin >> N >> L;
    for(int i=0; i<N; i++) {
        cin >> data;
        while(!DQ.empty() && DQ.back().first > data) DQ.pop_back(); // 지금 들어오는 거보다 큰 거 뒤에서 부터 지워버림
        DQ.push_back(make_pair(data, i));
        while(!DQ.empty() && DQ.front().second < i - L + 1) DQ.pop_front(); // 범위에 안맞는거 앞에서 부터 지워버림
        printf("%d ", DQ.front().first);
    }
    return 0;
}