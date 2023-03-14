// 12945
#include <string>
#include <vector>
#define mod 1234567

using namespace std;

int solution(int n) {
    vector<int> fibo = vector<int>(n);
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= n; i++) {
        fibo[i] = (fibo[i-1] + fibo[i-2])%mod;
    }
    return fibo[n];
}