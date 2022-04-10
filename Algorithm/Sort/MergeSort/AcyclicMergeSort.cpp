//2018112178 임연지
#include <iostream>
using namespace std;

void merge(int A[], int l, int m, int r) {
    int B[10];
    int i, leftptr = l, rightptr = m+1, bufptr = l;
    while(leftptr <= m && rightptr <= r) {
        if(A[leftptr] < A[rightptr]) B[bufptr++] = A[leftptr++];
        else B[bufptr++] = A[rightptr++];
    }
    if(leftptr > m) for(i = rightptr; i <= r; i++) { B[bufptr++] = A[i]; }
    else for(i = leftptr; i <= m; i++) { B[bufptr++] = A[i]; }
    for(i = l; i <= r; i++ ) { A[i] = B[i]; }
}

int main() {
    int A[10] = {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
    int l, r, m, n = 2;
    while(n < 10) {
        for(int i = 0; i < 10; i += n){
            l = i;
            r = l+n-1;
            if(r > 9) r = 9;
            m = (l+r)/2;
            merge(A, l, m, r);
            for(int j = 0; j < 10; j++) { cout << A[j] << " "; } cout << endl;
        }
        n *=2;
    }
    n /= 2;
    merge(A, 0, n-1, 9);
    for(int j = 0; j < 10; j++) { cout << A[j] << " "; } cout << endl;
    return 0;
}