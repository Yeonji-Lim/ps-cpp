/* 게임 개발 */
#include <iostream>
using namespace std;
int n, m;
bool visited[50][50] = {false};
int map[50][50];
int da[4] = {-1, 0, 1, 0};
int db[4] = {0, 1, 0, -1};

bool isInMap(int a, int b) { return (a > -1 && a < n && b > -1 && b < m); }
void nextD(int& d) { if(d == 0) d = 3; else d--; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b, d, ans = 0;
    cin >> n >> m;
    cin >> a >> b >> d;
    visited[a][b] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> map[i][j];
            if(!visited[i][j]) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    
    int cnt = 0, na, nb;
    while(true) {
        nextD(d);
        if(cnt == 4){
            nextD(d);
            nextD(d);
            na = a+da[d]; nb = b+db[d];
            if(!isInMap(na, nb) || map[na][nb] == 1) break;
            visited[na][nb] = true;
            a = na; b = nb;
            nextD(d);
            nextD(d);
            cnt = 0;
        }
        na = a+da[d]; nb = b+db[d];
        if(!(isInMap(na, nb) && !visited[na][nb] && map[na][nb] == 0)){
            cnt++;
        } else {
            visited[na][nb] = true;
            a = na; b = nb;
            cnt = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
