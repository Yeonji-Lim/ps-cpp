/* 계수 정렬 이용 풀이 */

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int N, M, t;
    int items[1000000] = {};

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> t;
        items[t]++;
    }
    cin >> M;
    for(int i = 0; i < M; i++ ) {
        cin >> t;
        if(items[t] != 0) cout << "yes ";
        else cout << "no ";
    }
    cout << endl;
    return 0;
}