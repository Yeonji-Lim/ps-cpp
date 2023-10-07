#include <iostream>
#include <vector>

using namespace std;
int n, ans = 200*10-2*10+1;
int info[20][20];
bool vst[20];
vector<int> s;

int abs(int i, int j) { return i > j? i-j: j-i; }

int cal(vector<int> v) {
    int result = 0;
    for(int i : v) for(int j : v) result += info[i][j];
    return result;
}

void go(int cnt) {
    if(cnt == n/2) {
        vector<int> r;
        for(int i = 0; i < n && r.size() < n/2; i++)
            if(!vst[i]) r.push_back(i);
        ans = min(ans, abs(cal(s), cal(r)));
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!vst[i]) {
            vst[i] = true;
            s.push_back(i);
            go(cnt+1);
            s.pop_back();
            vst[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> info[i][j];
    go(0);
    cout << ans << '\n';
    return 0;
}