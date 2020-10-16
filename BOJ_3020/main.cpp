#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rstV;

int LowerBound(int data, vector<int> V) {
    int L=0, R=V.size();
    int mid;
    int result;
    while(L<=R) {
        mid = (L+R)/2;
        if(data >= V[mid]) {
            if(data == V[mid]) result = mid;
            R = mid-1;
        } else L = mid+1;
    }
    return result;
}

int UpperBound(int data) {
    int L=0, R=rstV.size();
    int mid;
    int result;
    while(L<=R) {
        mid = (L+R)/2;
        if(data <= rstV[mid]) {
            if(data == rstV[mid]) result = mid;
            L = mid+1;
        } else R = mid-1;
    }
    return result;
}

int main() {
    int N, H;
    int obs;
    int result = 1;
    vector<int> S;
    vector<int> J;
    cin >> N >> H;
    S.resize(N/2, 0);
    J.resize(N/2,0);
    for(int i=0; i<N; i++) {
        cin >> obs;
        if(i%2 != 0) { // 종유석
            J.push_back(obs);
        } else { // 석순
            S.push_back(obs);
        }
    }
    sort(S.begin(), S.end());
    sort(J.begin(), J.end());
//    N = (S.size()-LowerBound(H/2,S))+(J.size()-LowerBound(H-H/2+1,J));
    int j;
    for(int i=0; i<H; i++) {
        j = 0;
        while(S[j] < i) j++;
        obs = S.size() - j;
        j = 0;
        while(J[j] < H-i+1) j++;
        obs += J.size() - j;
        rstV.push_back(obs);
    }
    sort(rstV.begin(), rstV.end());
    j = 0;
    while(rstV[j] == rstV.front()) j++;
    printf("%d", j-1);
    return 0;
}
