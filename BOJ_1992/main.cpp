#include <cstdio>
#include <queue>
using namespace std;
int video[64][64];
queue<char> rstQ;

void quadTree(int sx, int sy, int n) {
    int i, j, ret = video[sx][sy];
    bool isEqual = true;
    for(i = sx; i < sx+n; i++) {
        for(j = sy; j < sy+n; j++) {
            if(ret != video[i][j]) {
                isEqual = false;
                break;
            }
        }
    }
    if(isEqual) {
        rstQ.push(ret+'0');
        return;
    }
    if(n == 2) {
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                rstQ.push(video[i][j]+'0');
            }
        }
        return;
    }
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            rstQ.push('(');
            quadTree(sx+i*n/2, sy+j*n/2, n/2);
            rstQ.push(')');
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &video[i][j]);
        }
    }
    rstQ.push('(');
    quadTree(0, 0, n);
    rstQ.push(')');
    while(!rstQ.empty()) {
        printf("%c ", rstQ.front());
        rstQ.pop();
    }
    return 0;
}