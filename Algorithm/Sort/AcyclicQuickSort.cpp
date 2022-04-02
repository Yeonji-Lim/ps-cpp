//2018112178 임연지
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

bool checkOverlap(int A[], int idx) { // 현재 들어온 원소가 기존 배열에서 중복을 발생하는지 체크
    for(int j = 0; j < idx-1; j++)
        if(A[idx] == A[j]) return true;
    return false;
}
int main() {
    srand((unsigned int)time(NULL));
    int A[10];
    cout << "------------------- created numbers -------------------\n";
    for(int i = 0; i < 10; i++) {
        // 중복이 발생하지 않을 때까지 난수 생성 후 저장
        do { A[i] = rand()%1000000+1; } 
        while(checkOverlap(A, i));
        cout << A[i] << " ";
    }
    cout << "\n----------------------- sorting -----------------------\n";
    queue<pair<int, int>> q;
    int l, r;
    q.emplace(0, 9);        // 계속 해서 정렬을 해야하는 범위를 queue에 push한다.
    while(!q.empty()) {     // 더이상 정렬할 부분이 없을 때까지 진행

        // 정렬을 해야 하는 부분 입력
        l = q.front().first;
        r = q.front().second;
        q.pop();
        if(r <= l) continue; // 해당 부분 정렬 종료 조건
        int p = A[r]; // 피벗은 주어진 배열 범위의 마지막 원소
        int x = l, y, tmp;

        // 피벗보다 작은 경우가 있으면 가장 앞의 원소(x번째)와 자리를 변경한다.
        for(y=l; y<r; y++) {
            if(A[y]<p) {
                tmp = A[y];
                A[y] = A[x];
                A[x++] = tmp; // 자리를 변경한 후에는 i를 증가시킨다.
            }
        }
        // x부터는 피벗보다 크거나 같은 원소들로 구성되어 있으므로, x번째 원소와 피벗의 위치를 바꾼다.
        tmp = A[x];
        A[x] = A[r];
        A[r] = tmp;

        for (int i = 0; i < 10; i++) { cout << A[i] << " "; } cout << "\n"; // 단계별 상태 출력

        // 다음 정렬을 진행할 범위를 q에 push한다.
        q.emplace(l, x-1);
        q.emplace(x+1, r);
    }
    cout << "--------------------- after sorted ---------------------\n";
    for (int i = 0; i < 10; i++) { cout << A[i] << " "; } cout << "\n";return 0;
}