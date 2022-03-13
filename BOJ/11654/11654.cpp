#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int ans;
    cin >> ans;
    if(ans >= 0 && ans <= 9) ans += 48;
    cout << ans << endl;
    return 0;
}