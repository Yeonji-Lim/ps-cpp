#include <iostream>
#include <vector>
#define P 1500000
#define M 1000000
using namespace std;
typedef long long int LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LL N;
    cin >> N;
    int one = 0, two = 1, ans;
    for(int i=3; i<=N%P; i++) {
        ans = (one + two) % M;
        one = two;
        two = ans;
    }
    printf("%d", ans);
    return 0;
}
