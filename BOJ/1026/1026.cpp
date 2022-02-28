#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, rst;
vector<int> A, B;

bool Rev(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> A[i]; 
    }
    for(int i = 0; i < N; i++){
        cin >> B[i]; 
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), Rev);
    
    for(int i = 0; i < N; i++){
        rst += A[i] * B[i];
    }
    
    cout << rst << endl;
    return 0;
}