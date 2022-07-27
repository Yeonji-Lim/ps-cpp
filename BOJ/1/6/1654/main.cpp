//#include <iostream>
//#include <deque>
//#include <climits>
//using namespace std;
//
//int K, N;
//deque<int> lens;
//
//bool possible(long long ans) {
//    int num = 0;
//    for(int i=0; i<K; i++) num += lens[i] / ans;
//    return num >= N;
//}
//
//int main() {
//    long long x;
//    long long L=0, R=LLONG_MAX;
//    long long ans;
//
//    cin >> K >> N;
//    for(int i=0; i<K; i++) {
//        cin >> x;
//        lens.push_back(x);
//    }
//
//    while(L <= R) {
//        x = (L + R) / 2;
//        if(possible(x)){
//            L = x + 1;
//            if(ans < x) ans = x;
//        } else {
//            R = x - 1;
//        }
//    }
//    printf("%lld\n", ans);
//    return 0;
//}

/* 2021.4.22 Failed */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> wires;
int k, n;
long long rst;

void findStartPoint (long long l, long long r) {
    long long m = (l+r)/2, cnt = 0;
    if(m == l || m == r) {
        rst = m;
        return;
    }
    for(int i = 0; i < k; i++) {
        cnt += wires[i]/m;
    }
    if(cnt < n) {
        findStartPoint(l, m-1);
    } else {
        findStartPoint(m+1, r);
    }
}

void findResult (long long length) {
    long long cnt = 0;
    for(int i = 0; i < k; i++) {
        cnt += wires[i]/length;
    }
    if(cnt >= n) {
        findResult(length+1);
    } else {
        rst = length-1;
    }
}

int main() {
    long long tmp, maxLength = 0;
    scanf("%d %d", &k, &n);
    for(int i = 0; i < k; i++) {
        scanf("%lld", &tmp);
        wires.push_back(tmp);
        maxLength += tmp;
    }
    maxLength /= n;
    sort(wires.begin(), wires.end());
    tmp = n/k+1;
    tmp = wires[0]/tmp;
    findStartPoint(tmp, maxLength);
    findResult(rst);
    printf("%lld\n", rst);
    return 0;
}