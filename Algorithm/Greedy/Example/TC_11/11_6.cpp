#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> food_times;

void next(int &x) {
    if(x == N-1) x = 0;
    else ++x;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    food_times.resize(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> food_times[i];
    }

    int cur = 0;
    for(int i = 0; i < K; i++) {
        while(food_times[cur] == 0) {
            next(cur);
        }
        food_times[cur]--;
        next(cur);
    }

    cout << ++cur << endl;
    return 0;
} 