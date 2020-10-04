#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int cnt = 0;
    string str;
    bool prevOpen;

    cin >> str;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') {
            prevOpen = true;
            cnt++;
        }
        else {
            cnt--;
            prevOpen? ans += cnt : ans++;
            prevOpen = false;
        }
    }
    printf("%d\n", ans);
    return 0;
}
