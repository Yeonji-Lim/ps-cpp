#include <iostream>
using namespace std;
int N;
int sto[100], DP[100] = {0};

int find(int cur) {
    if(DP[cur] == 0) {
        int tmp = find(cur-2) + sto[cur];
        DP[cur] = find(cur-1) > tmp? find(cur-1): tmp;
    }
    return DP[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> sto[i];
    }

    DP[0] = sto[0];
    DP[1] = sto[0] > sto[1] ? sto[0] : sto[1];

    cout << find(N-1) << endl;

    return 0;
}