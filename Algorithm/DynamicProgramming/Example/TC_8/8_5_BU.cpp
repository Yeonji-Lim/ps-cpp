// #include <iostream>
// using namespace std;

// int N, M;
// int mon[100], DP[10001] = {0};

// int max(int a, int b) { return a < b? a: b; }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N >> M;

//     for(int i = 0; i < N; i++) {
//         cin >> mon[i];
//     }

//     for(int i = 1; i <= M; i++) {
//         if(i < mon[0]) DP[i] = -1;
//         else {
//             for(int k = 0; k < N; k++) {
//                 if(i < mon[k]) {
//                     DP[i] = -1;
//                     continue;
//                 }
//                 if(DP[i-mon[k]] == -1) continue;
//                 if(DP[i] != 0) DP[i] = min(DP[i], 1 + DP[i-mon[k]]);
//                 else DP[i] = 1 + DP[i-mon[k]];
//             }
//             if(DP[i] == 0) DP[i] = -1;
//         }
//     }

//     cout << DP[M] << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

int N, M;
int mon[100], DP[10001];

int min(int a, int b) { return a < b? a: b; }

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill_n(DP, 10001, 10001);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> mon[i];
    }

    DP[0] = 0;

    for(int i = 1; i <= M; i++) {
        if(i < mon[0]) DP[i] = -1;
        else {
            for(int j = 0; j < N; j++){
                int tmp = i-mon[j];
                if(tmp > -1) {
                    if(DP[tmp] != -1) DP[i] = min(DP[i], DP[tmp]+1);
                } else break;
            }
            if(DP[i] == 10001) DP[i] = -1;
        }
    }

    cout << DP[M] << endl;

    return 0;
}