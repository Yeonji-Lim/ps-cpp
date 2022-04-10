// 2018112178 임연지
#include <iostream>
#include <ctime>
using namespace std;

// 지금 추가된 원소가 중복되는 원소인지 체크, 중복이면 true 반환
bool chkDup (int A[], int last) { 
    for(int i = 0; i < last; i++) { if(A[i] == A[last]) return true; }
    return false;
}

// 최소, 최대값을 동시에 찾아내는 함수
void findMinMax(int A[], int size, int *min, int *max) {
    int sm, la;
    *min = A[0]; *max = A[0];
    for(int i = 1; i < size-1; i+=2) {
        // A의 원소를 두 개씩 보면서 더 작은 값은 sm에, 더 큰 값은 la에 대입한다. 
        if(A[i] < A[i+1]) { sm = A[i]; la = A[i+1]; } 
        else { sm = A[i+1]; la = A[i]; }
        // 기존의 min, max 보다 더 적합한 수가 나오면 해당 값으로 갱신한다.
        if(sm < *min) *min = sm;
        if(la > *max) *max = la;
    }
    return;
}

int main() {
    srand((unsigned int)time(NULL));    // 랜덤 시드 생성
    int A[1000];
    cout << "--------created numbers--------";
    for (int i = 0; i < 1000; i++) {
        do { A[i] = rand() % 100000 + 1; }  // 1~100000 범위의 랜덤한 값을 생성
        while(chkDup(A, i));                // 그 생성값이 중복이면 다시 생성
        cout << A[i] << " ";
    }
    int min, max;
    findMinMax(A, 1000, &min, &max);
    cout << "\n--------result--------\nminimum : " << min 
         << "\nmaximum  : " << max << endl;
    return 0;
}