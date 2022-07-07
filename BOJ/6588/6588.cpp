#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
vector<bool> is_prime(MAX, true);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 2; i < 1001; i++){
        if(is_prime[i]) {
            for(int j = 2*i; j < MAX; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    is_prime[0] = false;
    is_prime[1] = false;
    int n, num;
    cin >> n; 
    while(n != 0) {
        for(num = 3; num < n; num++) {
            if(is_prime[num] && is_prime[n-num]) {
                cout << n << " = " << num << " + " << n-num << '\n';
                break;
            }
        }
        if(num == n) cout << "Goldbach's conjecture is wrong.\n";
        cin >> n;
    }
    return 0;
}