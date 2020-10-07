#include <iostream>
#include <deque>
#include <climits>
using namespace std;

int K, N;
deque<int> lens;

bool possible(long long ans) {
    int num = 0;
    for(int i=0; i<K; i++) num += lens[i] / ans;
    return num >= N;
}

int main() {
    long long x;
    long long L=0, R=LLONG_MAX;
    long long ans;

    cin >> K >> N;
    for(int i=0; i<K; i++) {
        cin >> x;
        lens.push_back(x);
    }

    while(L <= R) {
        x = (L + R) / 2;
        if(possible(x)){
            L = x + 1;
            if(ans < x) ans = x;
        } else {
            R = x - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}