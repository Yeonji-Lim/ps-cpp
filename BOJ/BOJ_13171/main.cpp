#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MOD (long long)(pow(10,9)+7)
long long A, X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> X;
    A = A % MOD;
    long long tempX = X;
    long long i = 1;
    long long ans = 1;
    while(i <= X){
        if(tempX % 2 == 1) ans = (ans * A) % MOD;
        if(i * 2 > X) break;
        A = (A * A) % MOD;
        i *= 2;
        tempX /= 2;
    }
    printf("%d", ans);

    return 0;
}
