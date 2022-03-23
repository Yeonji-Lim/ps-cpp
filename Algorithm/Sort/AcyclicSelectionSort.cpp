//2018112178 임연지
#include <iostream>
using namespace std;
int main() {
    int A[8], min, tmp, minIdx;
    for(int i = 0; i < 8; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < 7; i++) {
        min = A[i];
        minIdx = i;
        for(int j = i+1; j < 8; j++) {
            if(min > A[j]) {
                min = A[j];
                minIdx = j;
            }
        }
        tmp = A[i];
        A[i] = min;
        A[minIdx] = tmp;
        
        for(int j = 0; j < 8; j++) {
            cout << A[j] << " ";
        }
        cout << endl;
    }
    return 0;
}