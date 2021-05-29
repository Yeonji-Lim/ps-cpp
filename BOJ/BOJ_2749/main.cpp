#include <cstdio>
#include <vector>
#define P 1500000
#define M 1000000
using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    if(n <= 1){
        n == 0? printf("0") : printf("1");
    } else {
        n %= P;
        vector<int> V(n+1,0);
        V[1] = 1;
        for(int i=2; i<n+1; i++) {
            V[i] = (V[i-1]+V[i-2]) % M;
        }
        printf("%d", V[n]);
    }
    return 0;
}
