#include <iostream>
#include <vector>
using namespace std;
long long x, y, z, k = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y;
    z = y * 100 / x;
    for(int i = 1; i < 100-z; i++) {
        k = ((z+i)*x-100*y) / (100-(z+i));
        if(k > 0) break;
    }
    if(k > 0) {
        while ((long long) (y+k) * 100 / (x+k) < z+1) k++;
        cout << k << '\n';
    }
    else cout << "-1\n";
    return 0;
}