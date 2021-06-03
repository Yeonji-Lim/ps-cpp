#include <cstdio>
using namespace std;
int r, c, ci = 0, cj = 0;
int map[1001][1001];
bool visited[1001][1001];
int v[4][2] = {{0, 1000}, {0, 0}, {1000, 0}, {0, 0}};

bool isInMap(int i, int j) { return i > -1 && j > -1 && i < r && j < c; }
void U() { printf("U"); visited[--ci][cj] = true; }
void D() { printf("D"); visited[++ci][cj] = true; }
void L() { printf("L"); visited[ci][--cj] = true; }
void R() { printf("R"); visited[ci][++cj] = true; }

void goToRight() {
    int di = v[0][0], dj = v[0][1];
    while(visited[di][dj]) {
        di++;
        if(di == r) {
            di = v[0][0];
            dj--;
            if(dj == 0) return;
        }
    }
    v[0][0] = di; v[0][1] = dj;

    while(!(ci == di && cj == dj)) {
        if(isInMap(ci-1, cj) && !visited[ci-1][cj]) U();
        else if(isInMap(ci, cj+1) && !visited[ci][cj+1]) R();
        else if(isInMap(ci+1, cj)) D();
    }
    if(isInMap(ci+1, cj)) D();
}

void goToLeft() {
    int di = v[1][0], dj = v[1][1];
    while(visited[di][dj]) {
        di++;
        if(di == r) {
            di = v[1][0];
            dj++;
            if(dj == c) return;
        }
    }
    v[1][0] = di; v[1][1] = dj;

    while(!(ci == di && cj == dj)) {
        if(isInMap(ci-1, cj) && !visited[ci-1][cj]) U();
        else if(isInMap(ci, cj-1) && !visited[ci][cj-1]) L();
        else if(isInMap(ci+1, cj)) D();
    }
}

void goToDown() {
    int di = v[2][0], dj = v[2][1];
    while(visited[di][dj]) {
        dj++;
        if(dj == c) {
            dj = v[2][1];
            di--;
            if(di == 0) return;
        }
    }
    v[2][0] = di; v[2][1] = dj;

    while(!(ci == di && cj == dj)) {
        if(isInMap(ci, cj-1) && !visited[ci][cj-1]) L();
        else if(isInMap(ci+1, cj) && !visited[ci+1][cj]) D();
        else if(isInMap(ci, cj+1)) R();
    }
    if(isInMap(ci, cj+1)) R();
}

void goToUp() {
    int di = v[3][0], dj = v[3][1];
    while(visited[di][dj]) {
        dj++;
        if(dj == c) {
            dj = v[3][1];
            di++;
            if(di == r) return;
        }
    }
    v[3][0] = di; v[3][1] = dj;

    while(!(ci == di && cj == dj)) {
        if(isInMap(ci, cj-1) && !visited[ci][cj-1]) L();
        else if(isInMap(ci-1, cj) && !visited[ci-1][cj]) U();
        else if(isInMap(ci, cj+1)) R();
    }
}

int main() {
    int i, j;
    scanf("%d %d", &r, &c);
    v[0][1] = c-1; v[2][0] = r-1;

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
                    mi = i; mj = j;
                }
            }
        }
        visited[ci][cj] = true;
        visited[mi][mj] = true;
        i = 0;
        //이동
        while(!(ci == r-1 && cj == c-1)) {
            switch(i%4) {
                case 0: goToRight(); break;
                case 1: goToLeft(); break;
                case 2: goToDown(); break;
                case 3: goToUp(); break;
            }
            i++;
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