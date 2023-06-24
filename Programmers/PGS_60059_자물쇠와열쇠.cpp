#include <string>
#include <vector>

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi rotateKey(vvi key) {
    int M = key.size();
    vvi rotKey(M, vi(M, 0));
    // rotKey는 key를 반시계 방향으로 90도 돌린 것
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            rotKey[M-j][i] = key[i][j];
        }
    }
    return rotKey;
}

bool isOpen(vvi key, vvi lock, vvi map, int ki, int kj) { // ki, kj는 map에서 열쇠의 시작 지점
    int M = key.size(), N = lock.size();
    // 열쇠 맞춰보기
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            map[ki+i][kj+j] += key[i][j];
        }
    }
    // 자물쇠 부분에 1이 아닌 부분이 있으면 false
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[M-1+i][M-1+j] != 1) return false;
        }
    }
    return true;
}

bool solution(vvi key, vvi lock) {
    bool answer = true;
    int hole = 0, N = lock.size(), M = key.size();
    vvi map(N+2*M-2, vi(N+2*M-2, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            map[M-1+i][M-1+j] = lock[i][j];
        }
    }
    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < N+M-1; i++) {
            for(int j = 0; j < N+M-1; j++) {
                if(isOpen(key, lock, map, i, j)) return true;
            }
        }
        key = rotateKey(key);
    }
    return false;
}