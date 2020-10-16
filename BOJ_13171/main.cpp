#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MV (long long)(pow(10,9)+7)
long long A, X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> X;
    long long k = A % MV;
    long long j = 1;
    vector<int> V;
    while(j<=X){
        V.push_back((int)k);
        if(j*2 > X) break;
        k = (k * k) % MV;
        j *= 2;
    }

    k = 1;
    for(int i=0; X; i++) {
        if( X % 2 == 1) k = (k * V[i]) % MV;
        X = X/2;
    }
    printf("%d", (int)k);
    return 0;
}
