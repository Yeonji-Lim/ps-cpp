#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void Sort(vector<int> V, vector<int> &L, vector<int> &R, int p) {
    int i = 0, j = 0, tmp;
    while(i < L.size() && j < R.size()) {
        while(i<L.size() && p>L[i]) i++;
        while(j<R.size() && p<=R[j]) j++;
        if(i == L.size || j == R.size) break;
        tmp = L[i];
        L[i] = R[j];
        R[j] = tmp;
        
        i++;
        j++;
    }
    while(i<L.size()) {
        if(p<=L[i]) R.push_back(L[i]);
        i++;
    }
    while(j<R.size()) {
        if(p>R[j]) L.push_back(R[j]);
        j++;
    }
}

vector<int> Merge(vector<int> L, vector<int> R, int p) {
    vector<int> ret(L.size()+R.size()+1, 0);
    copy(L.begin(), L.end(), ret.begin())
    ret.push_back(p);
    copy(R.begin(), R.end(), ret.begin()+L.size()+1);
    return ret;
}

int main() {
    srand((unsigned int)time(NULL));
    int A[100];
    cout << "------------------- created numbers -------------------\n";
    for (int i = 0; i < 100; i++) {
        // 0 ~ 999 중의 하나의 숫자를 랜덤으로 생성, 저장
        A[i] = rand() % 1000; 
        cout << A[i] << " ";
    }
    cout << "\n-------------------------------------------------------\n";
    return 0;
}