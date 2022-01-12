#include <iostream>
using namespace std;

int N;
int DP[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    DP[1] = 1;
    DP[2] = 3;

    for(int i = 3; i <= N; i++) {
        DP[i] = DP[i-2]*2 + DP[i-1];
    }

    cout << DP[N] << endl;

    return 0;
}