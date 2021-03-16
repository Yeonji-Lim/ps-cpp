/* Solved - 2260KB 0ms */
//#include <iostream>
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int ans = 0;
//    int cnt = 0;
//    string str;
//    bool prevOpen;
//
//    cin >> str;
//    for(int i=0; i<str.length(); i++) {
//        if(str[i] == '(') {
//            prevOpen = true;
//            cnt++;
//        }
//        else {
//            cnt--;
//            prevOpen? ans += cnt : ans++;
//            prevOpen = false;
//        }
//    }
//    printf("%d\n", ans);
//    return 0;
//}

/* 2021.3.16 Solved - 1116KB 4ms */
#include <cstdio>

int main() {
    char ch;
    int tmp = 0, rst = 0;
    bool isLaser = true;
    scanf("%c", &ch);
    while(ch == '(' || ch == ')') {
        if(ch == '(') {
            if(!isLaser) isLaser = !isLaser;
            ++tmp;
        } else {
            if(isLaser) {
                isLaser = !isLaser;
                --tmp;
                rst += tmp;
            } else {
                --tmp;
                ++rst;
            }
        }
        scanf("%c", &ch);
    }
    printf("%d\n", rst);
    return 0;
}