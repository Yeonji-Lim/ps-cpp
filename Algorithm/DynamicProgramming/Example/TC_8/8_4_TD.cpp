#include <iostream>
using namespace std;

int N;
int DP[1001] = {0};

int find(int cur) {
    if(DP[cur] == 0) DP[cur] = find(cur-1) + find(cur-2)*2;
    return DP[cur];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    DP[1] = 1;
    DP[2] = 3;
    
    cout << find(N) << endl;

    return 0;
}