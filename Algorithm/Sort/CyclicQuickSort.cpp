//2018112178 임연지

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 현재 들어온 원소가 기존 배열에서 중복을 발생하는지 체크
bool checkOverlap(int A[], int idx) {
    for(int j = 0; j < idx-1; j++)
        if(A[idx] == A[j]) return true;
    return false;
}

int main() {
    srand((unsigned int)time(NULL));
    int A[10];
    cout << "------------------- created numbers -------------------\n";
    for(int i = 0; i < 10; i++) {
        // 중복이 발생하지 않을 때까지 난수 생성 후 저장
        do { A[i] = rand()%1000000+1; } 
        while(checkOverlap(A, i));
        cout << A[i] << " ";
    }
    cout << "\n-------------------------------------------------------\n";

    return 0;
}