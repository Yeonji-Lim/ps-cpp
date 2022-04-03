#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

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