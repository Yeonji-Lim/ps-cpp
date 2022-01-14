// #include <iostream>
// using namespace std;

// int N, M;
// int mon[100], DP[10001] = {10001};

// int min(int a, int b) { return a < b? a: b;}

// int find(int cur) {
    
//     if(cur < mon[0]) DP[cur] = -1;
//     else if(cur == mon[0]) DP[cur] = 0;
//     else {
//         for(int i = 0; i < N; i++) {
//             if(DP[cur-mon[i]] == -1) continue;
//             if(DP[cur] != 0) DP[cur] = min(DP[cur-mon[i]]+1, DP[cur]);
//             else DP[cur] = DP[cur-mon[i]]+1;
//         }

//         if(DP[cur] == 0) DP[cur] = -1;
//     }
    
//     return DP[cur];
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N >> M;

//     for(int i = 0; i < N; i++) {
//         cin >> mon[i];
//     }

//     cout << find(M) << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

int N, M;
int mon[100], DP[10001];

int min(int a, int b) { return a < b? a: b; }

int find(int cur) {
    if(DP[cur] == 10001) {
        if(cur < mon[0]) DP[cur] = -1;
        for(int j = 0; j < N; j++) {
            int tmp = cur - mon[j];
            if(tmp >=0) {
                int DP_tmp = find(tmp);
                if(DP_tmp != -1) DP[cur] = min(DP[cur], DP_tmp+1);
            } else break;
        }
    }
    return DP[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(DP, 10001, 10001);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> mon[i];
    }

    DP[0] = 0;

    cout << find(M) << endl;

    return 0;
}