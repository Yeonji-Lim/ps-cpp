#include <cstdio>
#include <vector>
#define MAX_LIMIT 1000000
using namespace std;
int N;
vector<int> V;

int calculate(int n) {
    int rst = MAX_LIMIT;
    int tmp;
    if(n<4) {
        return V[n];
    }
    if(n%3 == 0) {
        V[n / 3] != 0 ? rst = V[n / 3] : rst = calculate(n / 3);
    }
    if(n%2 == 0) {
        if(V[n/2] != 0) {
            if(rst > V[n / 2]) rst = V[n / 2];
        } else {
            tmp = calculate(n/2);
            if(rst > tmp) rst = tmp;
        }
    }
    if(V[n-1] != 0) {
        if(rst > V[n-1]) {
            rst = V[n-1];
        }
    } else {
        tmp = calculate(n-1);
        if(rst > tmp) {
            rst = tmp;
        }
    }
    rst++;
    V[n] = rst;
    return rst;
}

int main() {
    scanf("%d", &N);
    V.assign(N+1,0);
    V[2] = 1;
    V[3] = 1;
    calculate(N);
    printf("%d", V[N]);
    return 0;
}
