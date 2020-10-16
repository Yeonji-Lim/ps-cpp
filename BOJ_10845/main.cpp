#include <iostream>
//#include <deque>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    queue<int> q;
    string command;
    int data;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> command;
        if(command == "push") {
            cin >> data;
            q.push(data);
        } else if (command == "pop") {
            if(q.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", q.front());
                q.pop();
            }
        } else if (command == "front") {
            if(q.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", q.front());
            }
        } else if (command == "back") {
            if(q.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", q.back());
            }
        } else if (command == "size") {
            printf("%d\n", q.size());
        } else if (command == "empty") {
            printf("%d\n", q.empty());
        }
    }
    return 0;
}

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
