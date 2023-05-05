#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int num[8];
int cho[8];

void choose(int cur) {
    if(cur == m) {
        for(int i = 0; i < cur; i++) {
            cout << cho[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    if(cur != 0) tmp = cho[cur-1]; // 처음 고르는 상황이 아니라면 최근 숫자 저장
    for(int i = 0; i < n; i++) {
        if(tmp <= num[i]) {
            cho[cur] = num[i];
            choose(cur+1);
            cho[cur] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num+n);
    choose(0);
}