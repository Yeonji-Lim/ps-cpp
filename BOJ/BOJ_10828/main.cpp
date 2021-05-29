/* Solved - 5032KB 16ms */
//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main() {
//    int N;
//    string command;
//    stack<int> S;
//    int data;
//    cin >> N;
//    for(int i=0; i<N; i++) {
//        cin >> command;
//        if(command == "push") {
//            cin >> data;
//            S.push(data);
//        } else if(command == "pop") {
//            if(!S.empty()) {
//                printf("%d\n", S.top());
//                S.pop();
//            } else {
//                printf("-1\n");
//            }
//        } else if(command == "top") {
//            if(!S.empty()) {
//                printf("%d\n", S.top());
//            } else {
//                printf("-1\n");
//            }
//        } else if(command == "size") {
//            printf("%d\n", S.size());
//        } else if(command == "empty") {
//            printf("%d\n", S.empty());
//        }
//    }
//    return 0;
//}

/* 2021.3.12 Solved - 1228KB 4ms */
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack<int> s;

int main() {
    int n, tmp;
    char str[6];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(strcmp("push", str) == 0) {
            scanf("%d", &tmp);
            s.push(tmp);
        } else if(strcmp("pop", str) == 0) {
            if(s.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", s.top());
                s.pop();
            }
        } else if(strcmp("size", str) == 0) {
            printf("%d\n", s.size());
        } else if(strcmp("empty", str) == 0) {
            printf("%d\n", s.empty());
        } else if(strcmp("top", str) == 0) {
            if(s.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", s.top());
            }
        }
    }
    return 0;
}