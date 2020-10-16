#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MV (int)(pow(10,9)+7)
int A,X;
vector<int> V;

int calculate (int x) { // 매개변수는 지수씨 이때 지수씨는 무조건 2의 제곱수
    if(x == 1) return A % MV;
    else {
        int temp = calculate(x/2);
        return (temp * temp) % MV;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> X;
    while(X) {
        V.push_back(X % 2);
        X = X/2;
    }
    X = 1;
    for(int i=0; i<V.size(); i++) {
        if(V[i]) X *= calculate((int)pow(2,i));
    }
    printf("%d", X % MV);
    return 0;
}
