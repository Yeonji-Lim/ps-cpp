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

/* 2021.4.22 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k, n, tmp, cnt = 0, length;
    scanf("%d %d", &k, &n);
    vector<int> wires;
    for(int i = 0; i < k; i++) {
        scanf("%d", &tmp);
        wires.push_back(tmp);
    }
    sort(wires.begin(), wires.end());
    tmp = n/k;
    while(cnt < n) {
        cnt = 0;
        length = wires[k-1]/tmp;
        for(int i = 0; i < k; i++) {
            cnt += wires[i]/length;
        }
        tmp++;
    }
    while(cnt >= n) {
        length++;
        cnt = 0;
        for(int i = 0; i < k; i++) {
            cnt += wires[i]/length;
        }
    }
    length--;
    printf("%d\n", length);
    return 0;
}