//2018112178 임연지
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// 퀵소트로 정렬을 진행한다.
void quickSort(int A[], int low, int high) {
    if (low >= high) return; //정렬 종료 조건

    int i = low, j, tmp;

    // 비교할 기준인 피벗을 마지막 원소로 설정한다.
    int &pivot = A[high]; 
    //
    for (j = low; j < high; ++j) {
        if (A[j] < pivot) {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }
    tmp = A[i];
    A[i] = pivot;
    pivot = tmp;

    quickSort(A, low, i - 1);
    quickSort(A, i + 1, high);
}

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
    quickSort(A, 0, 99);
    cout << "--------------------- after sorted ---------------------\n";
    for (int i = 0; i < 100; i++) { cout << A[i] << " "; }
    cout << "\n-------------------------------------------------------\n";
    return 0;
}


