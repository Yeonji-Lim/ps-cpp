#include <bits/stdc++.h>
#define SIZE 4001
using namespace std;
int n;
int A[SIZE];
int B[SIZE];
int C[SIZE];
int D[SIZE];
int a_list[SIZE*SIZE];
int b_list[SIZE*SIZE];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    // a_list, b_list 생성
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a_list[n*i+j] = A[i]+B[j];
            b_list[n*i+j] = C[i]+D[j];
        }
    }
    // sort
    sort(a_list, a_list+n*n);
    sort(b_list, b_list+n*n, greater<int>());
    // 2 pointer
    int a_i = 0, b_i = 0, sum, size = n*n;
    while(a_i < size || b_i < size) {
        sum = a_list[a_i] + b_list[b_i];
        if(sum == 0) {
            int prev = a_list[a_i], a_num = 0, b_num = 0;
            while(a_i < size && prev == a_list[a_i]) { a_i++; a_num++; }
            prev = b_list[b_i];
            while(b_i < size && prev == b_list[b_i]) { b_i++; b_num++; }
            ans += a_num * b_num;
        } else if(sum > 0) {
            b_i++;
        } else {
            a_i++;
        }
    }
    cout << ans << endl;
    return 0;
}