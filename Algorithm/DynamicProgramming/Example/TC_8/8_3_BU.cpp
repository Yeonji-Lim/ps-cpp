#include <iostream>
using namespace std;
int N, tmp;
int sto[100], DP[100] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> sto[i];
    }

    DP[0] = sto[0];
    DP[1] = sto[0] > sto[1]? sto[0]: sto[1];

    for(int i = 2; i < N; i++) {
        tmp = DP[i - 2] + sto[i];
        DP[i] = DP[i - 1] > tmp? DP[i-1]: tmp ;
    }

    cout << DP[N-1] << endl;

    return 0;
}