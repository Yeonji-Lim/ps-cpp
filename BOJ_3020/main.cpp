#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, H, obs;
    scanf("%d %d", &N, &H);
    vector<int> V (H, 0);
    while(N--) {
        scanf("%d", &obs);
        if(N%2) {
            while(obs) {
                ++V[H-obs];
                obs--;
            }
        } else {
            while(obs) {
                ++V[obs-1];
                obs--;
            }
        }
    }
    sort(V.begin(), V.end());
    obs = 0;
    while(V[0] == V[obs]) obs++;
    printf("%d %d", V[0], obs);
    return 0;
}
