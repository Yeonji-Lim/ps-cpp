#include <cstdio>
#include <deque>
#include <cmath>
using namespace std;

int makeNextNum(int a, int p) {
    int tmp = 1000, next = 0;
    while(tmp != 0) {
        next += pow(a/tmp, p);
        a -= (a/tmp)*tmp;
        tmp /= 10;
    }
    return next;
}

int hasDuplicateNum(deque<int> &dq, int a) {
    int tmp = dq.front();
    int frontItem;
    do {
        frontItem = dq.front();
        if(frontItem == a) {
            while(dq.front() != tmp) { dq.pop_front(); }
            return dq.size();
        }
        dq.pop_front();
        dq.push_back(frontItem);
    } while(dq.front() != tmp);
    return -1;
}

int main() {
    int a, p, rst = 0;
    scanf("%d %d", &a, &p);
    if(a == 1) {
        printf("0\n");
        return 0;
    }
    deque<int> dq;
    dq.push_back(a);
    while(!dq.empty()) {
        a = makeNextNum(a, p);
        if(hasDuplicateNum(dq, a) != -1) {
            printf("%d\n", dq.size());
            return 0;
        }
        dq.push_back(a);
    }
    return 0;
}
