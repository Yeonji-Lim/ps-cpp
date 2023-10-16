#include <iostream>
#include <deque>

using namespace std;
deque<pair<int, int>> dq;
int vst[5] = {0,};
int cham, dir, tmp, ans = 1;

int main() {
    cin >> cham;
    for(int i = 0; i < 6; i++) {
        cin >> dir >> tmp;
        dq.push_back({dir, tmp});
        vst[dq[i].first]++;
    }
    tmp = 0;
    while(tmp < 4) {
        if(vst[dq.front().first] == 1) {
            ans *= dq.front().second;
            dq.pop_front();
            continue;
        }
        tmp++;
        dq.push_back(dq.front());
        dq.pop_front();
    }
    ans -= dq[1].second * dq[2].second;
    cout << ans*cham << '\n';
    return 0;
}

/*
그냥 반시계
1, 4, 2, 3
서쪽 <- 2  동쪽 -> 1
순서 고정은 아니지만 방향은 항상 같다.
ㄱ 
4, 2, 3, 1*, 3*, 1
2, 3, 1*, 3*, 1, 4
3, 1*, 3*, 1, 4, 2
1*, 3*, 1, 4, 2, 3
3*, 1, 4, 2, 3, 1*
1, 4, 2, 3, 1*, 3*

|-
2, 3, 1, 4, 1, 4

_| 
1, 4, 2, 4, 2, 3

|_ 
2, 4, 1, 3, 1, 3

*/