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

vvi map;

vvi lotateKey(vvi key)
{
    vvi rotKey(key.size(), vi(key[0].size(), 0));
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            rotKey[key.size() - j][i] = key[i][j];
        }
    }
    return rotKey;
}

int isOpen(vvi key, int ki, int kj)
{
    int ret = 0;
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            if (key[i][j] == 1)
                if (map[ki + i][kj + j] == 1)
                    return -1;
                else if (map[ki + i][kj + j] == 0)
                    ret++;
        }
    }
    return ret;
}

bool solution(vvi key, vvi lock)
{
    bool answer = true;
    int hole = 0;
    map.resize(key.size() + 2 * lock.size() - 2, vi(key.size() + 2 * lock.size() - 2, 2)) for (int i = 0; i < lock.size(); i++)
    {
        for (int j = 0; j < lock.size(); j++)
        {
            map[key.size() - 1 + i][key.size() - 1 + j] = lock[i][j];
            if (lock[i][j] == 0)
                hole++;
        }
    }

    return answer;
}