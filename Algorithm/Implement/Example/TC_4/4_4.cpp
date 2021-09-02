/* 게임 개발 */
#include <iostream>
using namespace std;
int n, m;
bool vstd[50][50] = {false};
int map[50][50];
int da[4] = {-1, 0, 1, 0};
int db[4] = {0, 1, 0, -1};

bool isInMap(int a, int b) { return (a > -1 && a < n && b > -1 && b < m); }
void turnLeft(int& d) { if(d == 0) d = 3; else d--; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b, d, ans = 1;
    cin >> n >> m;
    cin >> a >> b >> d;
    vstd[a][b] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ; j++) {
            cin >> map[i][j];
        }
    }
    int turn = 0, na, nb;
    while(true) {
        turnLeft(d);
        if(turn == 4){
            turnLeft(d); turnLeft(d);
            na = a+da[d]; nb = b+db[d];
            if (!isInMap(na, nb) || (isInMap(na, nb) && map[na][nb] == 1))
                break;
            vstd[na][nb] = true;
            a = na; b = nb;
            turnLeft(d); turnLeft(d);
            turn = 0;
        }
        na = a+da[d]; nb = b+db[d];
        if (isInMap(na, nb) && !vstd[na][nb] && map[na][nb] == 0){
            vstd[na][nb] = true;
            a = na; b = nb;
            turn = 0;
            ans++;
        } else turn++;
    }
    cout << ans << endl;
    return 0;
}
