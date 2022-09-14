/* 2021.4.13 시간 초과 */
//#include <cstdio>
//#include <queue>
//using namespace std;
//int m, n, box[1000][1000];
//bool spread[1000][1000];
//int di[4] = {-1, 0, 0, 1};
//int dj[4] = {0, -1, 1, 0};
//
//int main() {
//    int i, j, k, ni, nj, rst = 0;
//    bool done = true;
//    queue<pair<int, int>> q;
//    scanf("%d %d", &m, &n);
//    for(i = 0; i < n; i++) {
//        for(j = 0; j < m; j++) {
//            scanf("%d", &box[i][j]);
//            if(box[i][j] == 0) done = false;
//            spread[i][j] = false;
//        }
//    }
//    if(done) {
//        printf("0\n");
//        return 0;
//    }
//    while(true) {
//        for(i = 0; i < n; i++) {
//            for(j = 0; j < m; j++) {
//                if(!spread[i][j] && box[i][j] == 1) {
//                    spread[i][j] = true;
//                    for(k = 0; k < 4; k++) {
//                        ni = i + di[k];
//                        nj = j + dj[k];
//                        if(ni > -1 && ni < n && nj > -1 && nj < m
//                            && box[ni][nj] == 0) q.push(make_pair(ni, nj));
//                    }
//                }
//            }
//        }
//        if(!q.empty()) {
//            rst++;
//            while(!q.empty()) {
//                box[q.front().first][q.front().second] = 1;
//                q.pop();
//            }
//        } else break;
//    }
//    for(i = 0; i < n; i++) {
//        for(j = 0; j < m; j++) {
//            if(box[i][j] == 0) {
//                printf("-1\n");
//                return 0;
//            }
//        }
//    }
//    printf("%d\n", rst);
//    return 0;
//}

/* 2021.4.13 Solved - 9176KB 116ms*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int m, n, i, j, k, ni, nj, box[1000][1000];
    int di[4] = {-1, 0, 0, 1};
    int dj[4] = {0, -1, 1, 0};
    queue<pair<int, int>> q;
    scanf("%d %d", &m, &n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &box[i][j]);
            if(box[i][j] == 1) q.push(make_pair(i, j));
        }
    }
    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        for(k = 0; k < 4; k++) {
            ni = i + di[k];
            nj = j + dj[k];
            if(ni > -1 && ni < n && nj > -1 && nj < m
                && box[ni][nj] == 0) {
                q.push(make_pair(ni, nj));
                box[ni][nj] = box[i][j] + 1;
            }
        }
        q.pop();
    }
    k = 1;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(box[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
            if(box[i][j] > k) k = box[i][j];
        }
    }
    if(k == 1) printf("0\n");
    else printf("%d", k-1);
    return 0;
}