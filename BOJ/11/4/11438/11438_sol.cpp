// 백준에서는 테스트 케이스 각각에 1.5초, 삼성은 각각의 테스트 케이스가 아니라 뭉탱이로 테스트 케이스 제공 -> 초기화에 신경 써야 한다.
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> tree[100001];
int depth[100001];
deque<int> targets;
int parent[18][100001]; // 2^17 까지 커버 가능하게 [k][v] : v의 2^k번째 부모 저장

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        tree[a].push_back(b); //방향이 없으므로 둘 다 넣어줌
        tree[b].push_back(a);
    }

    // 전역변수로 정의된 배열을 모두 0이나 -1로 초기화 하는 방법
    memset(parent, 0, sizeof parent);

    // 루트 노드로 부터의 depth를 알아야 : DFS or BFS로 알아내면 됨
    // BFS -> 방문 체크 해야 함 : depth를 이용
    // 근데 이때 루트 노드의 depth는 0 -> 1. depth를 -1로 초기화 2. 루트인 경우만 조건을 따로 빼기
    fill_n(depth, 100001, -1);

    targets.push_back(1);
    while(!targets.empty()) {
        int curr = targets.front();
        targets.pop_front();
        for(int next : tree[curr]) {
            if(depth[next] == -1) {
                targets.push_back(next);
                depth[next] = depth[curr]+1;
                // curr는 next의 한칸 부모
                parent[0][next] = curr;
            }
        }
    }

    // 점핑 테이블 (희소 테이블) 만들기
    for(int r = 1; r < 18; r++) {
        for(int i = 1; i <= n; i++) {
            // parent[r][i]는 parent[r-1][i]의 2^(r-1) 번째 부모
            parent[r][i] = parent[r-1][parent[r-1][i]]; 
            // 하나 적은 r 값에 대해서 전 루프에서 저장해두기 때문에 정상 작동
        } 
    }

    cin >> m;
    int diff, cnt, pa, pb;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        // a, b 의 LCA를 구하여 출력

        // 1 : Depth 맞추기
        if(depth[a] < depth[b]) { // a, b에 대한 질문과 b, a의 질문은 같다. 
            cnt = a;
            a = b;
            b = cnt;
        }
        diff = depth[a] - depth[b];
        for(int r = 0; diff; r++) {
            if(diff & 1) {
                a = parent[r][a];
            }
            diff >>= 1;
        }

        // 2 : LCA 찾기
        while(a != b) {
            cnt = 0;
            for(cnt = 0; cnt < 18; cnt++) {
                if(parent[cnt][a] == parent[cnt][b]) break;
            }
            if(cnt) --cnt; 
            // cnt = 1 : cnt가 0이 되서 다시 while
            // cnt = 0 : while 조건에 걸러짐
            // cnt = 18 : 구조상 17만큼 올라가면 모두 만나게 되어 있음
            //            루트를 넘어가면 0이 들어감, 0이 들어가면 그 전의 값으로 가기 때문에 오동작하지 않음
            a = parent[cnt][a];
            b = parent[cnt][b];
        }
        cout << a << '\n';
    }
    return 0;
}