#include <iostream>
using namespace std;

int min(int a, int b) { return a < b? a: b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x;
    cin >> x;

    int DP[30000] = {0};

    for(int i = 2; i <= x; i++) {
        DP[i] = DP[i-1]+1;
        if(i%5 == 0) {
            if(DP[i] != 0) DP[i] = min(DP[i], DP[i/5]+1);
            else DP[i] = DP[i/5]+1;
        }
        if(i%3 == 0) {
            if(DP[i] != 0) DP[i] = min(DP[i], DP[i/3]+1);
            else DP[i] = DP[i/3]+1;
        }
        if(i%2 == 0) {
            if(DP[i] != 0) DP[i] = min(DP[i], DP[i/2]+1);
            else DP[i] = DP[i/2]+1;
        }
    }

    cout << DP[x] << endl;
    
    return 0;
}