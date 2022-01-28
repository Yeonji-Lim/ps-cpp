#include <iostream>
using namespace std;
int V, E;
int parent[100];
bool cycle = false;

int find_parent(int child) {
    if(parent[child] != child) {
        parent[child] = find_parent(parent[child]);
    }
    return parent[child];
}

void union_parent(int x, int y) {
    // int p_x = find_parent(x);
    // int p_y = find_parent(y);

    // if(x == y)
    //     cycle = true;
    // else if (p_x < p_y)
    //     parent[y] = p_x;
    // else
    //     parent[x] = p_y;

    // > 이렇게 따로 parent를 설정할 필요가 없다 어차피 그 과정에서 모두 trace되게 되어있고, 우리는 최종 보스에서만 서열을 정하면 됨
    // > 기존과 똑같이 크고 작음만 비교하고 union 연산만 진행하고 cycle 판별을 위한 코드는 main에 넣자
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

    cin >> V >> E;
    for(int x = 1; x <=V; x++) {
        parent[x]=x;
    }

    int i, j;
    for(int x = 0; x < E; x++) {
        cin >> i >> j;
        if(find_parent(i) == find_parent(j)) {    
            cycle = true;
            break;
        }
        else union_parent(i, j);
    }

    if(cycle) cout << "사이클 발생함";
    else cout << "사이클 발생안함";
    return 0;
}