/* 2021.4.2 Failed*/
//#include <cstdio>
//#include <deque>
//#include <cmath>
//using namespace std;
//
//int makeNextNum(int a, int p) {
//    int tmp = 1000, next = 0;
//    while(tmp != 0) {
//        next += pow(a/tmp, p);
//        a -= (a/tmp)*tmp;
//        tmp /= 10;
//    }
//    return next;
//}
//
//int hasDuplicateNum(deque<int> &dq, int a) {
//    int tmp = dq.front();
//    int frontItem;
//    do {
//        frontItem = dq.front();
//        if(frontItem == a) {
//            while(dq.front() != tmp) { dq.pop_front(); }
//            return dq.size();
//        }
//        dq.pop_front();
//        dq.push_back(frontItem);
//    } while(dq.front() != tmp);
//    return -1;
//}
//
//int main() {
//    int a, p, rst = 0;
//    scanf("%d %d", &a, &p);
//    if(a == 1) {
//        printf("0\n");
//        return 0;
//    }
//    deque<int> dq;
//    dq.push_back(a);
//    while(!dq.empty()) {
//        a = makeNextNum(a, p);
//        if(hasDuplicateNum(dq, a) != -1) {
//            printf("%d\n", dq.size());
//            return 0;
//        }
//        dq.push_back(a);
//    }
//    return 0;
//}

/* 2021.4.3 Solved - 2472KB 0ms */
#include <cstdio>
#include <cmath>
#define MAX 300001
int p;
int visited[MAX];

int nextNum(int a) {
    int next = 0;
    while(a) {
        next += (int)pow(a%10, p);
        a /= 10;
    }
    return next;
}

void dfs (int a) {
    visited[a]++;
    if(visited[a] == 3) { return; }
    dfs(nextNum(a));
}

int main() {
    int a, rst = 0;
    scanf("%d %d", &a, &p);
    if(a == 1) {
        printf("0\n");
        return 0;
    }
    for(int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
    dfs(a);
    for(int i = 1; i < MAX; i++) {
        if(visited[i] == 1) { rst++; }
    }
    printf("%d\n", rst);
    return 0;
}