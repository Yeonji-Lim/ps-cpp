#include <cstdio>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int n, tmp;
    char cmd[11];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", cmd);
        switch(cmd[1]) {
            case 'u':
                scanf("%d", &tmp);
                if(cmd[5] == 'f') { dq.push_front(tmp); }
                else { dq.push_back(tmp); }
                break;
            case 'o':
                if(cmd[5] == 'f') {
                    if(dq.empty()) { printf("-1\n"); }
                    else {
                        printf("%d\n", dq.front());
                        dq.pop_front();
                    }
                } else {
                    if(dq.empty()) { printf("-1\n"); }
                    else {
                        printf("%d\n", dq.back());
                        dq.pop_back();
                    }
                }
                break;
            case 'i':
                printf("%d\n", dq.size());
                break;
            case 'm':
                printf("%d\n", dq.empty());
                break;
            case 'r':
                if(dq.empty()) { printf("-1\n"); }
                else { printf("%d\n", dq.front()); }
                break;
            case 'a':
                if(dq.empty()) { printf("-1\n"); }
                else { printf("%d\n", dq.back()); }
                break;
        }
    }
    return 0;
}
