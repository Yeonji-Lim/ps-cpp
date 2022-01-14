#include <iostream>
using namespace std;

int N, M;
int mon[100], DP[10001] = {10001};

int min(int a, int b) { return a < b? a: b;}

int find(int cur) {
    
    if(cur < mon[0]) DP[cur] = -1;
    else if(cur == mon[0]) DP[cur] = 0;
    else {
        for(int i = 0; i < N; i++) {
            if(DP[cur-mon[i]] == -1) continue;
            if(DP[cur] != 0) DP[cur] = min(DP[cur-mon[i]]+1, DP[cur]);
            else DP[cur] = DP[cur-mon[i]]+1;
        }

        if(DP[cur] == 0) DP[cur] = -1;
    }
    
    return DP[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> mon[i];
    }

    cout << find(M) << endl;

    return 0;
}