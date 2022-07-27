#include <iostream>
#include <vector>
using namespace std;
string s;
int ans = 0, a, b;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            a = a*10 + s[i]-'0';
        } else {
            ans += a;
            a = 0;
            if(s[i] == '-') {
                v.push_back(ans);
                ans = 0;
            }
        }
    }
    ans += a;
    v.push_back(ans);
    ans = v[0];
    if(v.size() > 1) for(int i = 1; i < v.size(); i++) {
        ans -= v[i];
    }
    cout << ans << endl;

    return 0;
}