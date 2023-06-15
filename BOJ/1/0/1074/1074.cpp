#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c, ans = 0;
    cin >> n >> r >> c;

    int cal = pow(2, n-1); // 좌표 위치 파악에 이용할 값
    int num = pow(cal, 2); // 최종 답 계산에 이용할 값

    while(cal) {
        if(r < cal) {
            if(c >= cal) {
                c -= cal;
                ans += num;
            }
        } else {
            r -= cal;
            if(c < cal) {
                ans += num*2;
            } else {
                c -= cal;
                ans += num*3;
            }
        }
        num /= 4;
        cal /= 2;
    }
    cout << ans << '\n';
    return 0;
}