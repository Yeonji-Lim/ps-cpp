#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> A;

void quickSort(int l, int r) {
    int &p = A[r];
    int i = l, j = r-1, tmp;
    while(i < j) {
        if(A[j] < p) {
            tmp = A[j];
            A[j] = A[i];
            A[i++] = tmp;
        }
        j--;
    }
    tmp = p;
    p = A[i];
    A[i] = tmp;
    quickSort(l, i-1);
    quickSort(i+1, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    A.resize(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    quickSort(0, A.size()-1);

    int tmp = A[0];
    cout << A[0] << " ";
    for(int i = 1; i < N; i++) {
        if(A[i] != tmp) {
            tmp = A[i];
            cout << A[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}