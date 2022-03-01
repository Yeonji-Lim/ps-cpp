#include <iostream>
#include <vector>
using namespace std;
int T, K;
vector<string> link;
vector<int> isActive;

void chooseDir(int curIdx) {
    if(curIdx-1 > -1 && isActive[curIdx-1] != 0 && link[curIdx-1][2] != link[curIdx][6]) {
        isActive[curIdx] = -1 * isActive[curIdx-1];
    }
    if(curIdx+1 < T && isActive[curIdx+1] != 0 && link[curIdx+1][6] != link[curIdx][2]) {
        isActive[curIdx] = -1 * isActive[curIdx+1];
    }
}

void rotate(int curIdx) {
    string ch;
    if(isActive[curIdx] == 1) {
        ch = link[curIdx][7];
        link[curIdx] = ch + link[curIdx].substr(0, 7);
    } else if(isActive[curIdx] == -1) {
        ch = link[curIdx][0];
        link[curIdx] = link[curIdx].substr(1) + ch;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i = 0;
    cin >> T;
    link.resize(T, "0");
    isActive.resize(T, 0);
    for(i = 0; i < T; i++) { cin >> link[i]; }

    cin >> K;
    int tar;
    while(K-- > 0) {
        cin >> tar;
        tar--;
        cin >> isActive[tar];

        //방향정하기
        for(i = tar-1; i > -1; i--) { chooseDir(i); }
        for(i = tar+1; i < T; i++) { chooseDir(i); }

        //회전시키기
        for(i = 0; i < T; i++) { rotate(i); }
        fill(isActive.begin(), isActive.end(), 0);
    }

    for(i = 0; i < T; i++) { K += link[i][0]-'0'; }

    cout << ++K << endl;
    return 0;
}