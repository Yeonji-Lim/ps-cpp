#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int qn_info[17];

void put_qn(int row) {
    for(int col = 1; col <= n; col++) {
        // col이 적합한지 체크
        // 해당 세로줄에 이미 퀸이 있는 경우
        if(qn_info[col] != 0) continue;

        // 대각선이 겹치는 경우
        bool valid = true;
        for(int j = 1; j <= n; j++) {
            if(qn_info[j] != 0 && (qn_info[j]+j == row+col || qn_info[j]-j == row-col)) {
                valid = false;
                break;
            }
        }
        if(!valid) continue;

        // (row, col)이 적합한 위치인 경우
        qn_info[col] = row; // 위치 기록
        if(row == n) ans++; // 마지막 줄에서는 ans++
        else put_qn(row+1); // 다음 줄로 넘어가기
        qn_info[col] = 0; // 원상복귀
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    put_qn(1);
    cout << ans << '\n';
    return 0;
}