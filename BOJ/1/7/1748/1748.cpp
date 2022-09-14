#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    long long int rst = 0;
    cin >> N;

    long long int tmp = N;
    int dgt = 1;
    tmp = tmp/10;

    while(tmp != 0) {
        dgt++;
        tmp = tmp/10;
    }

    for(int i = 1; i < dgt; i++) {
        rst += i * 9 * (int)pow(10, i-1);
        tmp += 9 * (int)pow(10, i - 1);
    }

    rst += dgt * (N - tmp);

    cout << rst << endl;
    
    return 0;
}