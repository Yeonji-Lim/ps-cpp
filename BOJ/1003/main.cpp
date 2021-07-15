#include <iostream>
#include <vector>
using namespace std;
typedef long long int LL;
vector<pair<LL, LL>> V(41,make_pair(-1,-1));

pair<LL, LL> solve(int n) {
    if(n == 0) return make_pair(1LL,0LL);
    if(n == 1) return make_pair(0LL,1LL);
    if(V[n].first != -1) return V[n];
    pair<LL, LL> a = solve(n-1);
    pair<LL, LL> b = solve(n-2);
    V[n] = make_pair(a.first + b.first,a.second + b.second);
    return V[n];
}

int main() {
    int T, n;
    pair<LL, LL> p;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        p = solve(n);
        printf("%lld %lld\n", p.first, p.second);
    }
    return 0;
}