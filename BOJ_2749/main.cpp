#include <iostream>
#include <vector>
using namespace std;
#define P 1500000
#define M 1000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    vector<int> V;
    long long ans;
    cin >> n;
    if(n == 1) {
        printf("0");
        return 0;
    } else if(n == 2) {
        printf("1");
        return 0;
    } else {
        for(int i=2; i<P; i++) {
            V.push_back((V[i-1]+V[i-2]) % M);
        }
    }
    printf("%d", V[n%P]);
    return 0;
}
