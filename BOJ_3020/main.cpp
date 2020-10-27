#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, H, obs;
    scanf("%d %d", &N, &H);
    vector<int> J (H,0);
    vector<int> S (H,0);
    while(N) {
        scanf("%d", &obs);
        if(N%2) {
            J[obs-1]++;
        } else {
            S[obs-1]++;
        }
        N--;
    }
    for(int i=1; i<H; i++) {
        J[H-i-1] += J[H-i];
        S[H-i-1] += S[H-i];
    }
    for(int i=0; i<H; i++) {
        J[i] += S[H-i-1];
    }
    sort(J.begin(), J.end());
    for(int i=0; i<H; i++) {
        if(J[0] != J[i]) {
            printf("%d %d", J[0], i);
            break;
        }
    }
    return 0;
}
