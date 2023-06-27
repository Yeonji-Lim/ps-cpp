// #include <string>
// #include <vector>

// using namespace std;
// typedef vector<vector<int>> vvi;
// typedef vector<int> vi;

// vvi rotateKey(vvi key) {
//     int M = key.size();
//     vvi rotKey(M, vi(M, 0));
//     // rotKey는 key를 반시계 방향으로 90도 돌린 것
//     for(int i = 0; i < M; i++) {
//         for(int j = 0; j < M; j++) {
//             rotKey[M-j][i] = key[i][j];
//         }
//     }
//     return rotKey;
// }

// bool isOpen(vvi key, vvi lock, vvi map, int ki, int kj) { // ki, kj는 map에서 열쇠의 시작 지점
//     int M = key.size(), N = lock.size();
//     // 열쇠 맞춰보기
//     for(int i=0; i<M; i++) {
//         for(int j=0; j<M; j++) {
//             map[ki+i][kj+j] += key[i][j];
//         }
//     }
//     // 자물쇠 부분에 1이 아닌 부분이 있으면 false
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             if(map[M-1+i][M-1+j] != 1) return false;
//         }
//     }
//     return true;
// }

// bool solution(vvi key, vvi lock) {
//     bool answer = true;
//     int hole = 0, N = lock.size(), M = key.size();
//     vvi map(N+2*M-2, vi(N+2*M-2, 0));
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             map[M-1+i][M-1+j] = lock[i][j];
//         }
//     }
//     for(int k = 0; k < 4; k++) {
//         for(int i = 0; i < N+M-1; i++) {
//             for(int j = 0; j < N+M-1; j++) {
//                 if(isOpen(key, lock, map, i, j)) return true;
//             }
//         }
//         key = rotateKey(key);
//     }
//     return false;
// }

#include <string>
#include <vector>

using namespace std;
vector<vector<int>> key, lock;
int ls, ks;

bool isMatched(vector<vector<int>> target) { // 열렸는 지 체크
    for(int i = ks-1; i < ls+ks-1; i++) {
        for(int j = ks-1; j < ls+ks-1; j++) {
            if(target[i][j] == 0) return false;
        }
    }
    return true;
}

bool match(int si, int sj) { // 열기 시도
    vector<vector<int>> lab = lock;
    for(int i = si; i < si+ks; i++) {
        for(int j = sj; j < sj+ks; j++) {
            if(i < ks-1 || i > ks+ls-1 || j < ks-1 || j > ks+ls-1 ) continue;
            if(lab[i][j] == 1 && key[i-si][j-sj] == 1) return false;
            lab[i][j] += key[i-si][j-sj];
        }
    }
    return isMatched(lab);
}

void rotation() { // 열쇠 돌리기
    vector<vector<int>> result;
    for(int i = 0; i < ks; i++) {
        vector<int> v;
        for(int j = 0; j < ks; j++) {
            v.push_back(key[ks-1-j][i]);
        }
        result.push_back(v);
    }
    key = result;
}

bool move() { // 열쇠 움직이기
    vector<vector<int>> lab = lock;
    for(int i = 0; i < ls+ks; i++) {
        for(int j = 0; j < ls+ks; j++) {
            if(match(i, j)) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> k, vector<vector<int>> l) {
    ks = k.size();
    ls = l.size();
    key = k;

    for(int i = 0; i < ls+2*ks-2; i++) { // 넓은 곳에 자물쇠 놓기(?)
        vector<int> v;
        for(int j = 0; j < ls+2*ks-2; j++) {
           if(i < ks-1 || i > ls+ks-2 || j < ks-1 || j > ls+ks-2) v.push_back(0);
           else v.push_back(l[i-ks+1][j-ks+1]);
       }
       lock.push_back(v);
    }
    if(move()) return true;
    for(int k = 0; k < 3; k++) {
       rotation();
       if(move()) return true;
    }
    return false;
}