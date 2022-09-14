#include <iostream>
#include <vector>
using namespace std;
int n, ans = 0;
vector<vector<int>> triangle(501, vector<int>(501, 0));
vector<vector<int>> DP(501, vector<int>(501, -1));

bool isInTriangle(int i, int j) {return i > -1 && i < n && j > -1 && j <= i; }

int calMax(int i, int j) {
    if(!isInTriangle(i, j)) return -1;
    if(DP[i][j] != -1) return DP[i][j];
    return DP[i][j] = max(calMax(i-1, j-1), calMax(i-1, j)) + triangle[i][j];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    DP[0][0] = triangle[0][0];
    for(int i = 0; i < n; i++) {
        ans = max(calMax(n-1, i), ans);
    }
    cout << ans << '\n';
    return 0;
}