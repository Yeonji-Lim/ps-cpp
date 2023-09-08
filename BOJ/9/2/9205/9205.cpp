// #include <iostream>
// #include <queue>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, t, a, b, ra, rb;
// queue<vector<int>> q;
// vector<vector<int>> v;
// vector<int> tmp;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> t;
//     while(t--) {
//         string res = "sad";
//         cin >> n;
//         cin >> a >> b;
//         v.push_back({a+b, a-b, a, b, 1});
//         q.push({a+b, a-b, a, b, 0});
//         for(int i = 0; i < n; i++) {
//             cin >> a >> b;
//             v.push_back({a+b, a-b, a, b, 0});
//         }
//         cin >> a >> b;
//         v.push_back({a+b, a-b, a, b, 0});
        
//         ra = a; rb = b;
//         while(!q.empty()) {
//             tmp = q.front();
//             a = tmp[0];
//             b = tmp[1];
//             q.pop();
//             for(int i = 0; i < n+2; i++) {
//                 if(v[i][4] != 1 && v[i][0] >= a-1000 && v[i][0] <= a+1000 && v[i][1] >= b-1000 && v[i][1] <= b+1000) {
//                     if(v[i][2] == ra && v[i][3] == rb) {
//                         res = "happy";
//                         break;
//                     }
//                     v[i][4] = 1;
//                     q.push(v[i]);
//                 }
//             }
//             if(res == "happy") break;
//         }
//         cout << res << "\n";
//     }

//     return 0;
// }

/*
경로가 아니라 갈 수 있냐 없냐만 판단하면 됨

1. 지금 위치에서 근처에 있는 편의점을 찾는다. : 비짓 처리 안된거 이면서 거리에 들어온 것이어야 함 x 축까지는 정렬 -> 최대 2*50 -> 100
    - 찾음 : 큐에 넣고 비짓처리
    - 못찾음 : 다음에 큐에 있는 거 지정 -> 없으면 sad
    - 락페 찾음 : 종료 happy
*/

/*좀 더 직관적으로 표현하는 것을 지향하자 너무 어렵게 생각하지 말자*/
/*단위가 커서 시간 복잡도를 신경써야 한다는 생각에 이상한 방법을 생각해낸듯 n의 단위를 보면 100이기 때문에 단순하게 접근해도 된다.*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, a, b, ra, rb;

int abs(int n) { return n > 0? n: -n; }

int main() {
    cin >> t;
    while(t--) {
        vector<pair<int, int>> v;
        vector<bool> vst;
        queue<pair<int, int>> q;
        string res = "sad";
        cin >> n;
        cin >> a >> b;
        v.push_back({a, b});
        vst.push_back(true);
        q.push(v[0]);
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back({a, b});
            vst.push_back(false);
        }
        cin >> a >> b;
        v.push_back({a, b});
        vst.push_back(false);
        ra = a; rb = b;
        while(!q.empty()) {
            a = q.front().first;
            b = q.front().second;
            q.pop();
            for(int i = 0; i < v.size(); i++) {
                if(!vst[i] && abs(v[i].first-a)+abs(v[i].second-b) <= 1000) {
                    if(v[i].first == ra && v[i].second == rb) {
                        res = "happy";
                        break;
                    }
                    vst[i] = true;
                    q.push(v[i]);
                }
            }
            if(res == "happy") break;
        }
        cout << res << '\n';
    }
    
}