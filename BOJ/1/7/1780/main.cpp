//#include <iostream>
//#include <vector>
//using namespace std;
//vector<vector<int>> V;
//int a=0, b=0, c=0;
//
//void calculate(int x, int y, int n) {
//    bool equal = true;
//    for(int i = x; i<n+x; i++) {
//        for(int j = y; j<n+y; j++) {
//            if(V[i][j] != V[x][y]) equal = false;
//        }
//    }
//    if(equal) {
//        if(V[x][y] == -1) a++;
//        else if(V[x][y] == 0) b++;
//        else c++;
//        return;
//    }
//    n = n/3;
//    for(int i=0; i<3; i++) {
//        for(int j=0; j<3; j++) {
//            calculate(x+i*n, y+j*n, n);
//        }
//    }
//    return;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    int N, data;
//    vector<int> smlV;
//    cin >> N;
//    for(int i=0; i<N; i++) {
//        for(int j=0; j<N; j++) {
//            cin >> data;
//            smlV.push_back(data);
//        }
//        V.push_back(smlV);
//        smlV.clear();
//    }
//    calculate(0,0,N);
//    printf("%d\n%d\n%d",a,b,c);
//    return 0;
//}

/* 2021.5.4 Failed - 접근은 괜찮았는데 쿼드트리 알고리즘으로 해야함 그리고 이렇게 하면 같은 걸 몇 번씩 반복함
 *                   차라리 전체적으로 보다가 아니면 바로 브레이크 걸고 나누기 하는게 나음 */
//#include <cstdio>
//#define SIZE 2187
//int rst[3] = {0, 0, 0}, v[SIZE][SIZE];
//
//int isEqual(int sx, int sy, int n) {
//    int ret = v[sx][sy], tmp, i, j;
//    if(n == 1) return ret;
//    for(i = 0; i < 3; i++) {
//        for(j = 0; j < 3; j++) {
//            tmp = isEqual(sx+i*n/3, sy+j*n/3, n/3);
//            if(tmp == 2 || ret != tmp) return 2;
//        }
//    }
//    return ret;
//}
//
//void calculRst(int sx, int sy, int n) {
//    int i, j, tmp = isEqual(sx, sy, n);
//    if(tmp != 2) {
//        rst[tmp+1]++;
//        return;
//    }
//    for(i = 0; i < 3; i++) {
//        for(j = 0; j < 3; j++) {
//            tmp = isEqual(sx+i*n/3, sy+j*n/3, n/3);
//            if(tmp == 2) calculRst(sx, sy, n / 3);
//            else rst[tmp+1]++;
//        }
//    }
//}
//
//int main() {
//    int n, i, j;
//    scanf("%d", &n);
//    for(i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            scanf("%d", &v[i][j]);
//        }
//    }
//    calculRst(0, 0, n);
//    for(i = 0; i < 3; i++) printf("%d\n", rst[i]);
//    return 0;
//}