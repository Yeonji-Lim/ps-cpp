#include <bits/stdc++.h>
using namespace std;

// 10**10을 1,000,000,007로 나눈 나머지를 반환하는 함수
// a와 mod가 int인 경우 overflow
// a를 long long으로 바꾸거나 10을 long long으로 강제 형변환 해주면 overflow를 해결할 수 있다.
// mod만을 long long으로 변환해주는 것은 overflow를 해결하지 못한다.
int func() {
    int a = 10;
    int mod = 1e9+7;
    for(int i = 0; i < 10; i++) {
        a = 10 * a % mod;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << func() << '\n';
    return 0;
}