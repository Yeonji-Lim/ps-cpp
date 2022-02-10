#include <iostream>
#include <vector>
using namespace std;

int N, rst = 0;
vector<vector<int>> box;

int max(int x, int y) { return x > y? x: y; }

int eatCandy(int i, int j) {
    int ret;

    

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    box.resize(N, vector<int> (N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> box[i][j];
        }
    }



    cout << rst;
    return 0;
}