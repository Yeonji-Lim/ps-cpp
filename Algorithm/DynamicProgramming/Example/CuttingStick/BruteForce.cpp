// 2018112178 임연지 
#include <iostream>
using namespace std;

// 막대 길이별 가격을 저장
int price[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

// 해당 길이의 막대를 잘라서 나올 수 있는 최대 가격을 반환
int priceOf(int length) {
    // 길이가 1이라면 더이상 자를 수 없음. 해당 가격을 반환
    if(length == 1) return price[1];

    // 자르지 않았을 때 가격으로 초기화
    int ret = price[length];

    // (i, length-i)로 자르고, i에서의 가격 + (length-i) 길이에서의 최대 가격 중 가장 큰 값을 찾는다.
    for(int i = 1; i < length; i++) 
        ret = max(price[i] + priceOf(length-i), ret);

    return ret;
}

int main() {
    // 모든 길이에 대해서 최대 가격을 계산한다.
    for(int length = 1; length < 11; length++) 
        cout << priceOf(length) << " ";
    cout << endl;
    return 0;
}