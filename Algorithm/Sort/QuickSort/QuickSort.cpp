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
    // 배열의 low부터 high까지 탐색하여 pivot보다 작은 값을 만나면, A[i]와 값을 바꾸고 i를 1씩 증가시킨다.
    for (j = low; j < high; ++j) {
        if (A[j] < pivot) {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }
    // 반복문을 돌고 나면 A의 i번째부터 high번째 전까지는 pivot과 값이 같거나 더 큰 원소들로 이루어져 있다.

    // A[i]와 pivot 위치 바꾸기
    tmp = A[i];
    A[i] = pivot;
    pivot = tmp;

    // i-1번까지는 pivot보다 작은 값들이고, i+1번까지는 pivot보다 큰 값으로 구성되어 있다.
    // 두 부분은 그 내부가 정렬되어 있지 않으므로 정렬을 다시 진행한다.
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


