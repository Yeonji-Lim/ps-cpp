#include <bits/stdc++.h>
using namespace std;
int n, ans;

bool isOK(vector<int> colArray, int r, int c) {
    for(int j = 0; j < n; j++) {
        int i = colArray[j];
        if(i != 0) {
            if(abs(i-r)!=abs(j-c)) return false;
        }
    }
    return true;
}

void queen(int r, vector<int> colArray) {
    if(r == n) {
        ans++;
        return;
    }
    for(int c = 0; c < n; c++) {
        if(colArray[c] == 0 && isOK(colArray, r, c)) {
            colArray[c] = r;
            queen(r+1, colArray);
            colArray[c] = 0;
        }
    }
}

int main() {
    cin >> n;
    vector<int> colArray(n, 0);
    queen(0, colArray);
    cout << ans << endl;
    return 0;
}