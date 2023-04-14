#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string number;
    int t, cur = 1, ans = 0;
    cin >> number;
    for(int i = 0; i < number.size(); i++) {
        cur *= number[i]-'0';
    }
    ans = max(cur, ans);
    cur = 1;
    for(int i = 0; i < number.size(); i++) {
        if(i != 0)
            for(int k = 0; k < i; k++)
                cur *= number[k]-'0';
        t = number[i]-'0'-1;
        if(t > 0 || i != 0) cur *= t;
        for(int k = 0; k < number.size()-i-1; k++) cur *= 9;
        ans = max(cur, ans);
        cur = 1;
    }
    cout << ans;
    return 0;
}