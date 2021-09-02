/* 왕실의 나이트 */
#include <iostream>
using namespace std;

bool isInMap(char c, int r) {
    return (c >= 'a' && c < 'i' && r > 0 && r < 9);
}
int dc[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dr[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    char c;
    int r, ans = 0;
    cin >> c >> r;
    for(int i= 0; i < 8; i++){
        if(isInMap(c+dc[i], r+dr[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}