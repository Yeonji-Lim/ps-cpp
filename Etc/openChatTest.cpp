/**
 * @brief 
 * n 길이의 문자열을 사전 순으로 나열
 * 그런데 이 문자열들은 모두 A, B로만 이루어져 있고, B는 두 개만 있다.
 * k번째 문자열을 구하고, 그 문자열의 두번째 B의 인덱스(1부터 시작)을 이진수로 바꿔서 출력하라
 */

#include <bits/stdc++.h>
using namespace std;

string decTobin (int d) {
    string b = "";
    while(d > 0) {
        if(d&1) b = "1"+b;
        else b = "0"+b;
        d = d >> 1;
    }
    return b;
}

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    for(int i = n-2; i >= 0; i--) {
        for(int j = n-1; j > i; j--) {
            cnt++;
            if(cnt == k) {
                cout << decTobin(j+1) << '\n';
                return 0;
            }
        }
    }
}