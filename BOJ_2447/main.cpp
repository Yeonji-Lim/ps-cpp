//#include <iostream>
//#include <vector>
//using namespace std;
//
//void MakeSquare (vector<vector<char>> &result, int num) {
//
//    if(num == 1) {
//        result[0].push_back('*');
//        return;
//    }
//    for (int i = 0; i < 3; i++) {
//        for(int j = 0; j < 3; j++) {
//            if(i == 1 && j == 1) {
//                result[0].push_back(' ');
//            }
//        }
//    }
//
//
//    return;
//}
//
//void PrintSquare (bool isBlank, int num) {
//    if(num == 1 && !isBlank) {
//        cout << "*";
//        return;
//    }
//    else if(isBlank) {
//        for(int i = 1; i <= num; i++)
//            cout << "-";
//        return;
//    }
//    for (int i = 1; i <= 9 ; i++) {
//        if(i == 5) {
//            PrintSquare(true, num/3);
//            cout << endl;
//            continue;
//        }
//        PrintSquare(false, num/3);
//        if(!(i%3)) cout << endl;
//    }
//    return;
//}
//
//void draw (int i, int j, int N, bool star, vector<char> &map) {
//    if(N == 1 && star) {
//        map.push_back('*');
//        return;
//    } else if (N == 1 && !star){
//        map.push_back(' ');
//    }
//
//    int smallN = N/3;
//    for(int i = 0; i < 3; i++) {
//        for(int j = 0; j < 3; j++) {
//            if(i == 1 && j == 1 && star) {
//                draw(i,j,smallN,!star,map);
//            } else if(i == 1 && j == 1) {
//
//            } else {
//                draw(i,j,smallN,star,map);
//            }
//        }
//    }
//
//}
//
//int main() {
//    int num;
//    cin >> num;
//    vector<vector<char>> square(num, vector<char>(num,' '));
//
//
//    return 0;
//}

/* 2021.5.10 Failed - 시간 초과 */
//#include <cstdio>
//#include <cstring>
//bool isStar[6561][6561];
//
//void fillFalse(int sx, int sy, int n) {
//    for(int i = 0; i < n; i++) { for(int j = 0; j < n; j++) {
//        isStar[sx+i][sy+j] = false;
//    } }
//}
//
//void findStar(int sx, int sy, int n) {
//    if(n == 3) {
//        isStar[sx+1][sy+1] = false;
//        return;
//    }
//    for(int i = 0; i < 3; i++) { for(int j = 0; j < 3; j++) {
//        if(i == 1 && j == 1) fillFalse(sx+n/3, sy+n/3, n/3);
//        else findStar(sx+i*n/3, sy+j*n/3, n/3);
//    } }
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    for(int i = 0; i < 729; i++) {
//        memset(isStar, true, sizeof(isStar));
//    }
//    findStar(0, 0, n);
//    for(int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (isStar[i][j]) printf("*");
//            else printf(" ");
//        }
//        printf("\n");
//    }
//    return 0;
//}

/* 2021.5.10 Solved - 1116KB 96ms */
#include <cstdio>

void printStar(int n, int i, bool print) {
    // 기저사례
    if(n == 1) {
        if(print) printf("*");
        else printf(" ");
        return;
    }
    // n/3이 봤을 때 몇번째 줄인건지 넘겨줄 ni
    int ni = i;
    if(i >= 2*n/3) ni = i-2*n/3;
    else if(i >= n/3) ni = i-n/3;
    //세 번으로 나눠서 출력
    for(int j = 0; j < 3; j++) {
        if(!print) // 빈칸을 출력해야 하는 경우
            printStar(n/3, ni, print);
        else printStar(n/3, ni, !(i >= n/3 && i < 2*n/3 && j == 1));
        // 넘겨줄 print는 n/3에게 빈칸 출력을 명령해야 하는 경우 (n이 볼 때 가운데 위치인 경우)
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { // 줄 별로 출력
        printStar(n, i, true);
        printf("\n");
    }
    return 0;
}