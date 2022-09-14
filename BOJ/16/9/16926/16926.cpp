#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
vector<vector<int>> v;
int d[4][2] = { {0, -1}, {-1, 0}, {0, -1}, {-1, 0} };
bool isInMap(int x, int y) { return x > -1 && x < N && y > -1 && y < M; }

void rotate(int si, int ei, int sj, int ej) {
    int tmp = v[si][sj];
    for(int k = sj; k < ej; k++) { v[si][k] = v[si][k+1]; }
    for(int k = si; k < ei; k++) { v[k][ej] = v[k+1][ej]; }
    for(int k = ej; k > sj; k--) { v[ei][k] = v[ei][k-1]; }
    for(int k = ei; k > si+1; k--) { v[k][sj] = v[k-1][sj]; }
    v[si+1][sj] = tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    v.resize(N, vector<int>(M, 0));

    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) { cin >> v[i][j]; }
    }

    while(K-- > 0) {
        for(i = 0, j = 0; i < N/2 && j < M/2; i++, j++) {
                rotate(i, N-i-1, j, M-j-1);
        }
    }

    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) { cout << v[i][j] << " "; }
        cout << endl;
    }

    return 0;
}