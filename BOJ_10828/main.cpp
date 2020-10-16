#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    string command;
    stack<int> S;
    int data;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> command;
        if(command == "push") {
            cin >> data;
            S.push(data);
        } else if(command == "pop") {
            if(!S.empty()) {
                printf("%d\n", S.top());
                S.pop();
            } else {
                printf("-1\n");
            }
        } else if(command == "top") {
            if(!S.empty()) {
                printf("%d\n", S.top());
            } else {
                printf("-1\n");
            }
        } else if(command == "size") {
            printf("%d\n", S.size());
        } else if(command == "empty") {
            printf("%d\n", S.empty());
        }
    }
    return 0;
}
