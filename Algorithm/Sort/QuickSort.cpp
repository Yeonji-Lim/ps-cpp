#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand((unsigned int)time(NULL));
    int A[100];
    cout << "------------------- created numbers -------------------\n";
    for (int i = 0; i < 100; i++) {
        // 0 ~ 999 중의 하나의 숫자를 랜덤으로 생성, 저장
        A[i] = rand() % 1000; 
        cout << A[i] << " ";
    }
    cout << "\n-------------------------------------------------------\n";
    return 0;
}