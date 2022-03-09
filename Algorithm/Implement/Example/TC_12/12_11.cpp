#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, K, L, x = 0, y = 0;
vector<vector<bool>> map;
vector<pair<int, char>> plan;
deque<pair<int, int>> snake;

int direc = 0;
int d[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
bool isInMap(int i, int j) { return i > -1 && i < N && j >-1 && j < N; }

void turn(char cmd) {
    if(cmd == 'L') direc = (direc+1) % 4;
    else direc = (direc+1) % 4;
}

bool isSnake(int ti, int tj) {
    for(int i = 0; i < snake.size(); i++) {
        if(snake[i].first == ti && snake[i].second == tj) return true;
    }
    return false;
}

bool move() {
    x += d[direc][0]; y += d[direc][1];
    if(!isInMap(x, y)) return false;

    if(!map[x][y]) snake.pop_back();
    else map[x][y] = false;

    if(isSnake(x, y)) return false;

    snake.emplace_front(x, y);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    map.resize(N, vector<bool>(N, false));

    cin >> K;
    int ai, aj;
    while(K--){
        cin >> ai >> aj;
        map[ai-1][aj-1] = true;
    }

    cin >> L;
    char cmd;
    while(L--) {
        cin >> ai >> cmd;
        plan.emplace_back(ai, cmd);
    }

    snake.emplace_front(0, 0);
    ai = 0; aj = 0;
    do {
        if(aj < plan.size() && plan[aj].first == ai) {
            turn(plan[aj].second); aj++;
        }
        ai++;
    } while(move());

    cout << ai << endl;
    return 0;
}