//2018112178 임연지

#include <iostream>
using namespace std;

void SelectionSort (int* A, int start) {
    int min = A[start], minIdx = start, tmp;
    for(int i = start+1; i < 8; i++) {
        if(min > A[i]) {
            min = A[i];
            minIdx = i;
        }
    }
    tmp = A[start];
    A[start] = A[minIdx];
    A[minIdx] = tmp;
    for(int i = 0; i < 8; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    if(start < 7) SelectionSort(A, start+1);
}

int main() {
    int A[8], min, tmp, minIdx;
    for(int i = 0; i < 8; i++) {
        cin >> A[i];
    }
    SelectionSort(A, 0);
    return 0;
}