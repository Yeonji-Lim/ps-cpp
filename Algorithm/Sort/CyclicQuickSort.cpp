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
// l : 정렬할 범위의 시작 인덱스, r : 정렬할 범위의 끝 인덱스
void quickSort(int A[], int l, int r) {
    if(r <= l) return; //정렬 종료 조건

    // 피벗은 주어진 배열 범위의 마지막 원소
    int p = A[r]; 
    int i = l, j, tmp;

    // 피벗보다 작은 경우가 있으면 가장 앞의 원소(i번째)와 자리를 변경한다.
    for(j=l; j<r; j++) {
        if(A[j]<p) {
            tmp = A[j];
            A[j] = A[i];
            A[i++] = tmp; // 자리를 변경한 후에는 i를 증가시킨다.
        }
    }

    // i부터는 피벗보다 크거나 같은 원소들로 구성되어 있으므로, i번째 원소와 피벗의 위치를 바꾼다.
    tmp = A[i];
    A[i] = A[r];
    A[r] = tmp;

    // 단계별 상태 출력
    for (int k = 0; k < 10; k++) { cout << A[k] << " "; } cout << "\n";

    // 나누어진 두 부분에 대해서 다시 정렬을 진행한다.
    quickSort(A, l, i-1);
    quickSort(A, i+1, r);
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
    cout << "\n----------------------- sorting -----------------------\n";
    quickSort(A, 0, 9);
    cout << "--------------------- after sorted ---------------------\n";
    for (int i = 0; i < 10; i++) { cout << A[i] << " "; } cout << "\n";
    return 0;
}