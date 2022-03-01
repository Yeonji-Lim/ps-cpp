#include <iostream>
#define N_MAX 1000
using namespace std;

int numberOfHansu (int N) {
    int result = 0;
    int hundred,ten,one;
    for(int i = 1; i <= N; i++) {
        if(i == N_MAX) break;
        hundred = i/100;
        ten = (i - hundred*100)/10;
        one = i%10;
        if(hundred) { //백의 자리 수
            if(hundred - ten == ten - one) result++;
        }
        else { //십의 자리나 일의 자리 수는 무조건 한수
            result++;
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    if(N<=N_MAX) cout << numberOfHansu(N) << endl;
    return 0;
}
