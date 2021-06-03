#include <cstdio>
using namespace std;
int r, c;
int map[1001][1001];
bool visited[1001][1001];
int ci = 0, cj = 0;

bool isInMap(int i, int j) { return i > -1 && j > -1 && i < r && j < c; }

void U() { printf("U"); visited[--ci][cj] = true; }

void D() { printf("D"); visited[++ci][cj] = true; }

void L() { printf("L"); visited[ci][--cj] = true; }

void R() { printf("R"); visited[ci][++cj] = true; }

void goToRight() {
    int di = ci, dj = c - 1;
    while(visited[di][dj]) di++;
    while(!(ci == di && cj == dj)) {
        if(isInMap(ci-1, cj) && !visited[ci-1][cj]) U();
        else if(!visited[ci][cj+1]) R();
        else D();
    }
    D();
}

void goToDown() {
    int di = r - 1, dj = cj;
    while(visited[di][dj]) dj++;
    while(!(ci == di && cj == dj)) {
        if(isInMap(ci, cj-1) && !visited[ci][cj-1]) L();
        else if(!visited[ci+1][cj]) D();
        else R();
    }
    R();
}

void goToUp() {
    int di = 0, dj = cj;
    while(visited[di][dj]) di++;
    if(di == r) return;
    if(!visited[di][dj-1]) dj--;
    while(!(ci == di && cj == dj)) {
        if(!visited[ci][cj-1]) L();
        else if(!visited[ci-1][cj]) U();
        else R();
    }
}

void goToLeft() {
    int di = ci, dj = 0;
    while(visited[di][dj]) dj++;
    if(!visited[di-1][dj]) di--;
    while(!(ci == di && cj == dj)) {
        if(!visited[ci-1][cj]) U();
        else if(!visited[ci][cj-1]) L();
        else if(visited[ci][cj-1]) D();
    }
}

int main() {
    int i, j;
    scanf("%d %d", &r, &c);
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &map[i][j]);
            visited[i][j] = false;
        }
    }

    if(r%2 == 0 && c%2 == 0) {
        // 최소 찾기
        int min = 1000, mi, mj;
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                if((i == 0 && j == 0) || (i == r-1 && j == c-1)) continue;
                if((i+j)%2 == 1 && min > map[i][j]) {
                    min = map[i][j];
                    mi = i;
                    mj = j;
                }
            }
        }
        visited[ci][cj] = true;
        visited[mi][mj] = true;
        i = 0;
        //이동
//        while(!(ci == r-1 && cj == c-1)) {
//            switch(i%4) {
//                case 0:
//                    goToRight();
//                    break;
//                case 1:
//                    goToLeft();
//                    break;
//                case 2:
//                    goToDown();
//                    break;
//                case 3:
//                    goToUp();
//                    break;
//            }
//            if(ci == r-1 && cj == c-1) break;
//            i++;
//        }
        goToRight();
        goToLeft();
        goToDown();
        goToUp();
    } else if(r%2 == 0) {
        for(i = 0; i < r; i++) {
            if(i%2 == 0) for(j = 1; j < c; j++) printf("D");
            else for(j = 1; j < c; j++) printf("U");
            if(i != r-1) printf("R");
        }
    } else if(c%2 == 0) {
        for(i = 0; i < c; i++) {
            if(i%2 == 0) for(j = 1; j < r; j++) printf("R");
            else for(j = 1; j < r; j++) printf("L");
            if(i != c-1) printf("D");
        }
    } else {
        for(i = 0; i < r; i++) {
            if(i%2 == 0) for(j = 1; j < c; j++) printf("D");
            else for(j = 1; j < c; j++) printf("U");
            if(i != r-1) printf("R");
        }
    }
    return 0;
}
