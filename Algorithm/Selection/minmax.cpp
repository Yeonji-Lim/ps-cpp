// 2018112178 임연지
#include <iostream>
#include <ctime>
using namespace std;

// 지금 추가된 원소가 중복되는 원소인지 체크, 중복이면 true 반환
bool chkDup (int A[], int last) { 
    for(int i = 0; i < last; i++) { if(A[i] == A[last]) return true; }
    return false;
}

// A의 원소를 순환하면서 tmp보다 작은 값이 나오면 tmp 값을 갱신
int minimum (int A[], int n) {
    int i, tmp = A[0];
    for(i = 1; i < n; i++) { if(tmp > A[i]) tmp = A[i]; }
    return tmp;
}

// A의 원소를 순환하면서 tmp보다 큰 값이 나오면 tmp 값을 갱신
int maximum (int A[], int n) {
    int i, tmp = A[0];
    for(i = 1; i < n; i++) { if(tmp < A[i]) tmp = A[i]; }
    return tmp;
}

int main() {
    srand((unsigned int)time(NULL));    // 랜덤 시드 생성
    int A[1000];
    cout << "--------created numbers--------\n";
    for (int i = 0; i < 1000; i++) {
        do { A[i] = rand() % 100000 + 1; }  // 1~100000 범위의 랜덤한 값을 생성
        while(chkDup(A, i));                // 그 생성값이 중복이면 다시 생성
        cout << A[i] << " ";
    }
    cout << "\n--------result--------\nminimum : " << minimum(A, 1000) 
         << " maximum  : " << maximum(A, 1000) << endl;
    return 0;
}