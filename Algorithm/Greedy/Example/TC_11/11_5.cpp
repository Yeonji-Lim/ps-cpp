#include <iostream>
#include <vector>
using namespace std;

int N, M, rst;
vector<int> ball;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    ball.resize(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> ball[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(ball[i] != ball[j]) rst++;
        }
    }

    cout << rst << endl;

    return 0;
}