#include <iostream>
using namespace std;
int x;
int DP[30000] = {0};

int min(int a, int b) { return a < b? a: b; }

int calc(int x) {
    if(x == 1) return 0;
    if(DP[x] == 0) {
        DP[x] = calc(x-1)+1;
        if(x%5 == 0) {
            if(DP[x] != 0) DP[x] = min(DP[x], calc(x/5)+1);
            else DP[x] = calc(x/5)+1;
        }
        if(x%3 == 0) {
            if(DP[x] != 0) DP[x] = min(DP[x], calc(x/3)+1);
            else DP[x] = calc(x/3)+1;
        }
        if(x%2 == 0) {
            if(DP[x] != 0) DP[x] = min(DP[x], calc(x/2)+1);
            else DP[x] = calc(x/2)+1;
        }
    }
    return DP[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x;
    cout << calc(x) << endl;

    return 0;
}