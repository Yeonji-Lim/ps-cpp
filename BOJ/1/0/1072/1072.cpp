#include <iostream>
#include <vector>
using namespace std;
long long x, y;
int z, k = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y;
    z = ((double) y / x) * 100;
    for(int i = 1; i < 100-z; i++) {
        k = (100*y-(z+i)*x) / ((z+i)-100);
        if(k > 0) break;
    }
    if(k > 0) {
        while ((int) (((double) (y+k) / (x+k)) * 100) == z) k++;
        cout << k << '\n';
    }
    else cout << "-1\n";
    return 0;
}