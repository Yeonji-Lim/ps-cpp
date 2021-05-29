/* 2021.5.10 Solved - 2172KB 0ms */
#include <iostream>
#include <queue>
using namespace std;
int video[64][64];
queue<char> rstQ;

queue<char> quadTree(int sx, int sy, int n) {
    queue<char> retQ;
    int i, j, ret = video[sx][sy];
    if(n == 1) {
        retQ.push(ret);
        return retQ;
    }
    bool isEqual = true;
    for(i = sx; i < sx+n; i++) {
        for(j = sy; j < sy+n; j++) {
            if(ret != video[i][j]) {
                isEqual = false;
                break;
            }
        }
    }
    if(isEqual) {
        retQ.push(ret);
        return retQ;
    }
    queue<char> tmpQ;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            tmpQ = quadTree(sx+i*n/2, sy+j*n/2, n/2);
            if(tmpQ.size() == 1) retQ.push(tmpQ.front());
            else {
                retQ.push('(');
                while(!tmpQ.empty()) {
                    retQ.push(tmpQ.front());
                    tmpQ.pop();
                }
                retQ.push(')');
            }
        }
    }
    return retQ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string tmp;
    queue<char> tmpQ;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < n; j++) {
            video[i][j] = tmp[j];
        }
    }
    rstQ = quadTree(0, 0, n);
    if(rstQ.size() == 1) {
        cout << rstQ.front();
        cout << endl;
    } else {
        cout << '(';
        while(!rstQ.empty()) {
            cout << rstQ.front();
            rstQ.pop();
        }
        cout << ')' << endl;
    }
    cout << endl;
    return 0;
}