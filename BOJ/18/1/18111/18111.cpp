#include <iostream>
#include <map>
#define MAXHOUR 256*500*500*2+1

using namespace std;
int board[500][500], hour = MAXHOUR;
map<int, int> hei;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, b, tmpb, tmphour, cb, minh = 256, maxh = 0, height = 0;
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            minh = min(minh, board[i][j]);
            maxh = max(maxh, board[i][j]);
            if(hei.find(board[i][j]) != hei.end()) hei[board[i][j]]++;
            else hei.insert({board[i][j], 1});
        }
    }
    if(hei.size() == 1) {
        cout << 0 << ' ' << hei.begin()->first << '\n'; 
        return 0;
    }
    for(int th = minh; th <= maxh; th++) {
        tmpb = b;
        tmphour = -1;
        for(auto iter: hei) {
            cb = (th-iter.first)*iter.second;
            tmpb -= cb;
            if(cb < 0) { // 타겟 높이보다 높은 곳, 인벤추가
                tmphour -= 2*cb;
            } else if (cb > 0) {
                tmphour += cb;
            }
        }
        tmphour++;
        if(tmpb >= 0 && tmphour > 0){
            if(tmphour < hour) {
                hour = tmphour;
                height = th;
            } else if (tmphour == hour && height < th) {
                height = th;
            }
        }
    }
    cout << hour << ' ' << height << '\n';
    return 0;
}