#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int S;
    int N = 1;
    int L = 1, R;
    int mid;
    cin >> S;
    R = S;
    while(L<=R) {
        mid = (L+R)/2;
        if(S >= mid*(mid+1)/2) {
            if(mid > N) N = mid;
            L = mid+1;
        } else {
            R = mid-1;
        }
    }
    printf("%d", N);
    return 0;
}
