/* 2021.6.3 Failed */
//#include <cstdio>
//using namespace std;
//int r, c, ci, cj;
//int map[1001][1001];
//bool visited[1001][1001];
//int v[4][2] = {{0, 1000}, {0, 0}, {1000, 0}, {0, 0}};
//
//bool isInMap(int i, int j) { return i > -1 && j > -1 && i < r && j < c; }
//void U() { printf("U"); visited[--ci][cj] = true; }
//void D() { printf("D"); visited[++ci][cj] = true; }
//void L() { printf("L"); visited[ci][--cj] = true; }
//void R() { printf("R"); visited[ci][++cj] = true; }
//
//void goToRight() {
//    int di = v[0][0], dj = v[0][1];
//    while(visited[di][dj]) {
//        di++;
//        if(di == r) {
//            di = v[0][0];
//            dj--;
//            if(dj == 0) return;
//        }
//    }
//    v[0][0] = di; v[0][1] = dj;
//
//    while(!(ci == di && cj == dj)) {
//        if(isInMap(ci-1, cj) && !visited[ci-1][cj]) U();
//        else if(isInMap(ci, cj+1) && !visited[ci][cj+1]) R();
//        else if(isInMap(ci+1, cj)) D();
//    }
//    if(isInMap(ci+1, cj)) D();
//}
//
//void goToLeft() {
//    int di = v[1][0], dj = v[1][1];
//    while(visited[di][dj]) {
//        di++;
//        if(di == r) {
//            di = v[1][0];
//            dj++;
//            if(dj == c) return;
//        }
//    }
//    v[1][0] = di; v[1][1] = dj;
//
//    while(!(ci == di && cj == dj)) {
//        if(isInMap(ci-1, cj) && !visited[ci-1][cj]) U();
//        else if(isInMap(ci, cj-1) && !visited[ci][cj-1]) L();
//        else if(isInMap(ci+1, cj)) D();
//    }
//}
//
//void goToDown() {
//    int di = v[2][0], dj = v[2][1];
//    while(visited[di][dj]) {
//        dj++;
//        if(dj == c) {
//            dj = v[2][1];
//            di--;
//            if(di == 0) return;
//        }
//    }
//    v[2][0] = di; v[2][1] = dj;
//
//    while(!(ci == di && cj == dj)) {
//        if(isInMap(ci, cj-1) && !visited[ci][cj-1]) L();
//        else if(isInMap(ci+1, cj) && !visited[ci+1][cj]) D();
//        else if(isInMap(ci, cj+1)) R();
//    }
//    if(isInMap(ci, cj+1)) R();
//}
//
//void goToUp() {
//    int di = v[3][0], dj = v[3][1];
//    while(visited[di][dj]) {
//        dj++;
//        if(dj == c) {
//            dj = v[3][1];
//            di++;
//            if(di == r) return;
//        }
//    }
//    v[3][0] = di; v[3][1] = dj;
//
//    while(!(ci == di && cj == dj)) {
//        if(isInMap(ci, cj-1) && !visited[ci][cj-1]) L();
//        else if(isInMap(ci-1, cj) && !visited[ci-1][cj]) U();
//        else if(isInMap(ci, cj+1)) R();
//    }
//}
//
//int main() {
//    int i, j;
//    scanf("%d %d", &r, &c);
//    v[0][1] = c-1; v[2][0] = r-1;
//
//    for(i = 0; i < r; i++) {
//        for(j = 0; j < c; j++) {
//            scanf("%d", &map[i][j]);
//            visited[i][j] = false;
//        }
//    }
//
//    if(r%2 == 0 && c%2 == 0) {
//        int min = 1000;
//        for(i = 0; i < r; i++) {
//            for(j = 0; j < c; j++) {
//                if((i == 0 && j == 0) || (i == r-1 && j == c-1)) continue;
//                if((i+j)%2 == 1 && min > map[i][j]) {
//                    min = map[i][j];
//                    ci = i; cj = j;
//                }
//            }
//        }
//        visited[ci][cj] = true;
//        ci = 0; cj = 0;
//        visited[ci][cj] = true;
//        i = 0;
//
//        while(!(ci == r-1 && cj == c-1)) {
//            switch(i%4) {
//                case 0: goToRight(); break;
//                case 1: goToLeft(); break;
//                case 2: goToDown(); break;
//                case 3: goToUp(); break;
//            }
//            i++;
//        }
//
//    } else if(c%2 == 0) {
//        for(j = 0; j < c; j++) {
//            if(j%2 == 0) for(i = 1; i < r; i++) printf("R");
//            else for(i = 1; i < r; i++) printf("L");
//            if(j != c-1) printf("D");
//        }
//
//    } else {
//        for(i = 0; i < r; i++) {
//            if(i%2 == 0) for(j = 1; j < c; j++) printf("D");
//            else for(j = 1; j < c; j++) printf("U");
//            if(i != r-1) printf("R");
//        }
//    }
//    return 0;
//}

/* 2021.6.4 Failed */
#include <iostream>
#include <algorithm>
using namespace std;
int map[1001][1001];

string vPath (int r) {
    string ret = "";
    for(int j = 0; j < 2; j++) {
        for(int i = 1; i < r; i++) {
            if(j%2 == 0) ret += "D";
            else ret += "U";
        }
        ret += "R";
    }
    return ret;
}
string hPath (int c) {
    string ret = "";
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < c; j++) {
            if(i%2 == 0) ret += "R";
            else ret += "L";
        }
        ret += "D";
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    string rst = "", htmp, vtmp;
    if(r%2 == 0 && c%2 == 0) {
        int min = 1000, mi, mj;
        for(int i = 0; i < r; i++) { for(int j = 0; j < c; j++) {
            if((i == 0 && j == 0) || (i == r-1 && j == c-1)) continue;
            if((i+j)%2 == 0 && min > map[i][j]){
                min = map[i][j];
                mi = i; mj = j;
            }
        }}

        string mid = "DR";
        if(mi%2 == 1) mid = "RD";

        htmp = hPath(c);
        for(int i = 0; i < mi/2; i++) rst += htmp;
        vtmp = vPath(2);
        for(int i = 0; i < mj/2; i++) rst += vtmp;

        rst += mid;
        reverse(vtmp.begin(), vtmp.end());
        for(int i = 0; i < (c-1-mj)/2; i++) rst += vtmp;
        reverse(htmp.begin(), htmp.end());
        for(int i = 0; i < (r-1-mi)/2; i++) rst += htmp;

    } else if(r%2 == 0) {
        vtmp = vPath(r);
        for(int i = 0; i < c/2; i++) rst += vtmp;
        for(int i = 1; i < r; i++) rst += "D";
    } else {
        htmp = hPath(c);
        for(int i = 0; i < r/2; i++) rst += htmp;
        for(int i = 1; i < c; i++) rst += "R";
    }
    cout << rst;
}