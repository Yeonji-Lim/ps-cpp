/* Solved - 1988KB 0ms */
//#include <iostream>
//#include <deque>
//#include <queue>
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int N;
//    queue<int> q;
//    string command;
//    int data;
//
//    cin >> N;
//    for(int i=0; i<N; i++) {
//        cin >> command;
//        if(command == "push") {
//            cin >> data;
//            q.push(data);
//        } else if (command == "pop") {
//            if(q.empty()) {
//                printf("-1\n");
//            } else {
//                printf("%d\n", q.front());
//                q.pop();
//            }
//        } else if (command == "front") {
//            if(q.empty()) {
//                printf("-1\n");
//            } else {
//                printf("%d\n", q.front());
//            }
//        } else if (command == "back") {
//            if(q.empty()) {
//                printf("-1\n");
//            } else {
//                printf("%d\n", q.back());
//            }
//        } else if (command == "size") {
//            printf("%d\n", q.size());
//        } else if (command == "empty") {
//            printf("%d\n", q.empty());
//        }
//    }
//    return 0;
//}

//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int N;
//    deque<int> dq;
//    string command;
//    int data;
//
//    cin >> N;
//    for(int i=0; i<N; i++) {
//        cin >> command;
//        if(command == "push") {
//            cin >> data;
//            dq.push_back(data);
//        } else if (command == "pop") {
//            if(dq.empty()) {
//                cout << -1 << endl;
//            } else {
//                cout << dq.front() << endl;
//                dq.pop_front();
//            }
//        } else if (command == "front") {
//            if(dq.empty()) {
//                cout << -1 << endl;
//            } else {
//                cout << dq.front() << endl;
//            }
//        } else if (command == "back") {
//            if(dq.empty()) {
//                cout << -1 << endl;
//            } else {
//                cout << dq.back() << endl;
//            }
//        } else if (command == "size") {
//            cout << dq.size() << endl;
//        } else if (command == "empty") {
//            cout << (dq.empty()?1:0) << endl;
//        }
//    }
//
//    return 0;
//}

/* 2021.3.16 Solved - 1228KB 0ms */
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n, tmp;
    char cmd[6];
    queue<int> q;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", cmd);
        switch(cmd[1]) {
            case 'u':
                scanf("%d", &tmp);
                q.push(tmp);
                break;
            case 'o':
                if(q.empty()) {
                    printf("-1\n");
                } else {
                    printf("%d\n", q.front());
                    q.pop();
                }
                break;
            case 'i':
                printf("%d\n", q.size());
                break;
            case 'm':
                printf("%d\n", q.empty());
                break;
            case 'r':
                if(q.empty()) {
                    printf("-1\n");
                } else {
                    printf("%d\n", q.front());
                }
                break;
            case 'a':
                if(q.empty()) {
                    printf("-1\n");
                } else {
                    printf("%d\n", q.back());
                }
                break;
        }
    }
    return 0;
}