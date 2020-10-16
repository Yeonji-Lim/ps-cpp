#include <iostream>
#include <cmath>
using namespace std;
int N, r, c, ans=0;

void calculate(int x, int y, int n) {
    if(n == 2) {
        if(r == x) c == y? ans+=0: ans+=1;
        else c == y? ans+=2: ans+=3;
        return;
    }
    if(r < x+n/2) {
        if (c < y + n / 2) calculate(x, y, n / 2);
        else {
            ans += n * n / 4;
            calculate(x, y + n / 2, n / 2);
        }
    } else {
        if (c < y + n / 2) {
            ans += n * n / 2;
            calculate(x + n / 2, y, n / 2);
        }
        else {
            ans += n * n / 4 * 3;
            calculate(x + n / 2, y + n / 2, n / 2);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> r >> c;
    calculate(0,0,(int)pow(2,N));
    printf("%d", ans);
    return 0;
}
