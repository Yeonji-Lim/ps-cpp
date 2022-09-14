#include <bits/stdc++.h>
#define MXS 301
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, tar, fp, bp, ans = 0;
    cin >> n >> m;
    int dq[MXS], h = MXS/2, t = MXS/2;
    bool exist[MXS], left;
    for(int i = 1; i <= n; i++) {
        dq[t++] = i;
        exist[i] = true;
    }
    while(m--) {
        cin >> tar;

        if(dq[h] == tar) {
            exist[dq[h]] = false;
            h++;
            continue;
        }

        left = false;
        fp = 0;
        bp = 0;

        if(dq[h] < tar) {
            for(int i = dq[h]; i < tar; i++) {
                if(exist[i]) fp++;
            }
        } else {
            for(int i = dq[h]; i <= n; i++) {
                if(exist[i]) fp++;
            }
            for(int i = 1; i < tar; i++) {
                if(exist[i]) fp++;
            }
        }

        if(tar <= dq[t-1]) {
            for(int i = tar; i <= dq[t-1]; i++) {
                if(exist[i]) bp++;
            }
        } else {
            for(int i = tar; i <= n; i++) {
                if(exist[i]) bp++;
            }
            for(int i = 1; i <= dq[t-1]; i++) {
                if(exist[i]) bp++;
            }
        }
        
        if(fp < bp) left = true;
        if(left) {
            while(fp--) {
                dq[t++] = dq[h++];
                ans++;
            }
        } else {
            while(bp--) {
                dq[--h] = dq[--t];
                ans++;
            }
        }

        exist[dq[h]] = false;
        h++;
    }
    cout << ans << '\n';
}

/**
 * @brief 
 * 내부 원소들이 연속으로 되어있지 않은 상태를 생각
 * 그 사이에 수가 몇 개 있는지 알려줄 필요가 있다.
 * -> 인덱스 트리..?
 * 그런데 n은 50이니까 인덱스트리 안써도 2초 안에 들 수 있을 거 같음
 * 
 * 그리디로 풀어도 되는 건가?
 * 
 * 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 */