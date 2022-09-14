#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nums(1001, vector<int>(1001, 0));
int n, m, ans = 1;
int d[3][2] = {{-1, -1}, {-1, 0}, {0, -1}};
bool isValid(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            nums[i][j] = str[j]-'0';
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(nums[i][j] == 1) {
                int prev = -1;
                bool wide = true;
                for(int k = 0; k < 3; k++) {
                    int ni = i + d[k][0], nj = j + d[k][1];
                    if(isValid(ni, nj)) {
                        if (nums[ni][nj] == 0) {
                            wide = false;
                            break;
                        } 
                        if (prev == -1) {
                            prev = nums[ni][nj];
                        } else if (nums[ni][nj] != prev) {
                            prev = min(prev, nums[ni][nj]);
                        }
                    } else {
                        wide = false;
                        break;
                    }
                }
                if(wide) nums[i][j] = prev+1;
                ans = max(ans, nums[i][j]);
            }
        } 
    }
    cout << ans*ans << '\n';
    return 0;
}