// #include <iostream>
// #include <algorithm>
// #include <deque>
// #include <vector>
// using namespace std;
// typedef vector<vector<int>> vvi;
// typedef vector<int> vi;

// int N, M, ans=0, si=0, sj=0, hnum=0;
// vvi map, cMap, chicRank;

// bool compare(vi a, vi b) { return a[0] > b[0]; }
// int subAbs(int a, int b) { return a > b? a-b: b-a; }

// int chicDist(int hi, int hj) {
//     int dist = 100; // N의 범위안에서 절대 나올 수 없는 큰값
//     int ci, cj, tmp;
//     for(int i = 0; i < N; i++) { for(int j = 0; j < N; j++) {
//         if(map[i][j] == 2) {
//             tmp = subAbs(i, hi)+subAbs(j, hj);
//             if(dist > tmp){
//                 dist = tmp;
//                 ci = i; cj = j;
//             }
//         }
//     }}
//     cMap[ci][cj]++;
//     return dist;
// }

// void helpFunc() {
//     int mi = si/hnum, mj = sj/hnum, ci, cj;
//     vvi tmp;
//     for(int i = 0; i < N; i++) {
//         for(int j =0; j <N; j++) {
//             if(map[i][j] == 2) {
//                 tmp.push_back(vi{subAbs(mi, i)+subAbs(mj, j), i, j});
//             }
//         }
//     }
//     sort(tmp.begin(), tmp.end());
//     for(int i = 0; i < M; i++) {
//         ci = tmp[i][1]; cj = tmp[i][2];
//         cMap[ci][cj] += M-i;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N >> M;

//     map.resize(N, (vi(N, 0)));
//     cMap.resize(N, (vi(N, 0)));

//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             cin >> map[i][j];
//         }
//     }

//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             if(map[i][j] == 1) {
//                 cMap[i][j] = chicDist(i, j);
//                 si+=i; sj+=j;
//                 hnum++;
//             }
//         }
//     }
//     helpFunc();

//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             if(map[i][j] == 2) chicRank.push_back(vi{cMap[i][j], i, j});
//         }
//     }
//     sort(chicRank.begin(), chicRank.end(), compare);
//     for(int i = M; i < chicRank.size(); i++) {
//         map[chicRank[i][1]][chicRank[i][2]] = 0;
//     }

//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             if(map[i][j] == 1) ans += chicDist(i, j);
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }

// next_permutation을 활용하여 다시!

// #include <iostream>
// #include <algorithm>
// #include <cstdlib>
// #include <vector>
// using namespace std;

// int N, M;
// vector<pair<int, int>> house;
// vector<pair<int, int>> chicken;

// int chickDist(pair<int, int> h, pair<int, int> c) { return abs(h.first - c.first) + abs(h.second - c.second); }

// int main() {
//     int tmp, ans = 1e9, tmpAns = 0;
//     cin >> N >> M;
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             cin >> tmp;
//             if(tmp == 1) house.emplace_back(i, j);
//             if(tmp == 2) {
//                 chicken.emplace_back(i, j);
//                 tmpAns++;
//             }
//         }
//     }

//     vector<bool> perm(tmpAns);
//     fill(perm.end()-M, perm.end(), true);
//     tmp = 1e9;
//     tmpAns = 0;
//     do {
//         for(int i = 0; i < house.size(); i++) {
//             for(int j = 0; j < chicken.size(); j++) {
//                 if(perm[j]) tmp = min(tmp, chickDist(house[i], chicken[j]));
//             }
//             tmpAns += tmp;
//             tmp = 1e9;
//         }
//         ans = min(ans, tmpAns);
//         tmpAns = 0;
//     } while(next_permutation(perm.begin(), perm.end()));

//     cout << ans << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, ans = 100*2500, tmpans = 0, chidist = 0;
vector<pair<int, int>> chi, zip;
vector<bool> exist;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tmpans;
            if(tmpans == 2) chi.emplace_back(i, j);
            if(tmpans == 1) zip.emplace_back(i, j);
        }
    }
    exist.resize(chi.size());
    fill(exist.end()-m, exist.end(), true);
    do {
        tmpans = 0;
        for(int i = 0; i < zip.size(); i++) {
            chidist = 101;
            for(int j = 0; j < chi.size(); j++) {
                if(exist[j]) {
                    chidist = min(chidist, abs(zip[i].first-chi[j].first) + abs(zip[i].second-chi[j].second));
                }
            }
            if(chidist != 101) tmpans += chidist;
        }
        ans = min(ans, tmpans);
    } while(next_permutation(exist.begin(), exist.end()));
    cout << ans << '\n';
    return 0;
}