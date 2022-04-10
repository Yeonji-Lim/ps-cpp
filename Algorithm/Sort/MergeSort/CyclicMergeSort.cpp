// 2018112178 임연지
#include <iostream>
#include <vector>
using namespace std;

void merge(int A[], int l, int m, int r) {
    int B[10];
    int i, leftptr = l, rightptr = m+1, bufptr = l;
    while(leftptr <= m && rightptr <= r) {
        if(A[leftptr] < A[rightptr]) B[bufptr++] = A[leftptr++];
        else B[bufptr++] = A[rightptr++];
    }
    if(leftptr > m)
        for(i = rightptr; i <= r; i++) {
            B[bufptr++] = A[i];
        }
    else
        for(i = leftptr; i <= m; i++) {
            B[bufptr++] = A[i];
        }
    for(i = l; i <= r; i++ ) {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int l, int r) {
    int m = (l+r)/2;
    if(l < r) {
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, m, r);
        for(int i = 0; i < 10; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[10] = {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
    mergeSort(A, 0, 9);
    return 0;
}
