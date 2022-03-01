#include <iostream>

using namespace std;

int decomposition (int num) {
    int hundredT = num/100000;
    int tenT = num/10000;
    int thousand = num/1000;
    int hundred = num/100;
    int ten = num/10;
    int one = num%10;

    ten -= hundred*10;
    hundred -= thousand*10;
    thousand -= tenT*10;
    tenT -= hundredT*10;

    return num + hundredT + tenT + thousand + hundred + ten + one;
}

int main() {
    int N;
    cin >> N;
    if(N<1 || N>1000000) return 0;
    int result = 0;
    for(int i = 1; i < N; i++) {
        if(decomposition(i) == N) {
            result = i;
            break;
        }

    }
    printf("%d\n", result);
    return 0;
}
