#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, tmp;
int minsic[11] = {0,};
bool isPos = true;
vector<int> hei;
vector<pair<int, int>> info;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> minsic[i]; // minsic[a] == 키가 a+1인 사람의 답 -> 키가 j인 사람의 답을 찾으려면 minsic[j-1];
        hei.push_back(i+1); // 각 사람의 키 1 ~ n 인덱스 0 ~ n-1
        info.push_back({0, -1}); // 각 사람의 info // info[a].first == 키가 a인 사람의 답, info[a].second == 키가 a인 사람 앞에 키큰 사람 인덱스(hei의 인덱스)
    }
    hei = {6, 2, 3, 4, 7, 5, 1};
    do {
        for(int i = 0; i < n; i++) {
            cout << hei[i] << ' ';
        }
        if(hei[0] == 7) break;
        cout << "------\n";
        if(info[0].first != minsic[hei[0]-1]) continue; //첫번째 오는 숫자의 답은 0이어야 한다.
        isPos = true;
        for(int i = 1; i < n; i++) {
            tmp = i-1;
            while(hei[tmp] < hei[i] && info[tmp].second != -1) {
                tmp = info[tmp].second;
            }
            info[i].first = info[tmp].first;
            info[i].second = tmp;
            if(hei[tmp] > hei[i]) info[i].first++;
            if(info[i].first != minsic[hei[i]-1]) {
                cout << "break!" << hei[i] << " " << info[i].first << " " << minsic[hei[i]-1] << "\n";
                cout << hei[tmp] << '\n';
                isPos = false;
                break;
            }
            cout << hei[i] << " " << info[i].first << " " << info[i].second << '\n';
        }
        if(isPos) break;
        cout << "-----------------------\n";
    } while(next_permutation(hei.begin(), hei.end()));
    for(int i = 0; i < n; i++) {
        cout << hei[i] << ' ';
    }
    return 0;
}

/*
앞 숫자 (ans), 
내 앞에 애가 큰 수 이면 걔가 가지고 있는 거 +1 이 내꺼
작은 수이면, 얘가 참고한 놈한테 가기 -> 얘보다 큰수
*/