#include <iostream>
using namespace std;

int N, M;
int parent[100000];

int find_parent(int x) {
    if(parent[x] != x)
        parent[x] = find_parent(parent[x]);
    return x;
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int x = 1; x <= N; x++) {
        parent[x] = x;
    }

    int c, i, j;
    while(M-- != 0) {
        cin >> c >> i >> j;
        if(c) { //같은 팀 여부 확인
            if(find_parent(i) == find_parent(j)){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            union_parent(i, j);
        }
    }
    return 0;
}