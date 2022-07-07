#include <bits/stdc++.h>
#define MAX 4000001
using namespace std;
vector<bool> is_prime(MAX, true);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 2; i < (MAX>>1); i++) {
        if(is_prime[i]) {
            for(int j = i*2; j < MAX; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    is_prime[0] = false;
    is_prime[1] = false;
    int n, si = 2, ei = 2, sum = 2, cnt = 0; 
    cin >> n;
    while(si <= ei) {
        if(ei > n) break;
        if(n == sum) {
            cnt++;
            sum -= si;
            do { si++; } while(!is_prime[si]);
            do { ei++; } while(!is_prime[ei]);
            sum += ei;
        } else if (n > sum) {
            do { ei++; } while(!is_prime[ei]);
            sum += ei;
        } else {
            sum -= si;
            do { si++; } while(!is_prime[si]);
        }
    }
    cout << cnt << '\n';
    return 0;
}