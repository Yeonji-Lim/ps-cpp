// #include <iostream>
// #include <vector>
// #include <deque>
// using namespace std;

// int N, K, L, x = 0, y = 0;
// vector<vector<bool>> map;
// vector<pair<int, char>> plan;
// deque<pair<int, int>> snake;

// int direc = 0;
// int d[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
// bool isInMap(int i, int j) { return i > -1 && i < N && j >-1 && j < N; }

// void turn(char cmd) {
//     if(cmd == 'L') direc = (direc+1) % 4;
//     else direc = (direc+1) % 4;
// }

// bool isSnake(int ti, int tj) {
//     for(int i = 0; i < snake.size(); i++) {
//         if(snake[i].first == ti && snake[i].second == tj) return true;
//     }
//     return false;
// }

// bool move() {
//     x += d[direc][0]; y += d[direc][1];
//     if(!isInMap(x, y)) return false;

//     if(!map[x][y]) snake.pop_back();
//     else map[x][y] = false;

//     if(isSnake(x, y)) return false;

//     snake.emplace_front(x, y);
//     return true;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N;
//     map.resize(N, vector<bool>(N, false));

//     cin >> K;
//     int ai, aj;
//     while(K--){
//         cin >> ai >> aj;
//         map[ai-1][aj-1] = true;
//     }

//     cin >> L;
//     char cmd;
//     while(L--) {
//         cin >> ai >> cmd;
//         plan.emplace_back(ai, cmd);
//     }

//     snake.emplace_front(0, 0);
//     ai = 0; aj = 0;
//     do {
//         if(aj < plan.size() && plan[aj].first == ai) {
//             turn(plan[aj].second); aj++;
//         }
//         ai++;
//     } while(move());

//     cout << ai << endl;
//     return 0;
// }

//20220324
#include <string>
#include <vector>

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

vvi rotateKey(vvi key)
{
    int M = key.size();
    vvi rotKey(M, vi(M, 0));
    // rotKey는 key를 반시계 방향으로 90도 돌린 것
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            rotKey[M - j][i] = key[i][j];
        }
    }
    return rotKey;
}

bool isOpen(vvi key, vvi lock, vvi map, int ki, int kj)
{ // ki, kj는 map에서 열쇠의 시작 지점
    int M = key.size(), N = lock.size();
    // 열쇠 맞춰보기
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            map[ki + i][kj + j] += key[i][j];
        }
    }
    // 자물쇠 부분에 1이 아닌 부분이 있으면 false
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[M - 1 + i][M - 1 + j] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vvi key, vvi lock)
{
    bool answer = true;
    int hole = 0, N = lock.size(), M = key.size();
    vvi map(N + 2 * M - 2, vi(N + 2 * M - 2, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            map[M - 1 + i][M - 1 + j] = lock[i][j];
        }
    }
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < N + M - 1; i++)
        {
            for (int j = 0; j < N + M - 1; j++)
            {
                if (isOpen(key, lock, map, i, j))
                    return true;
            }
        }
        key = rotateKey(key);
    }
    return false;
}