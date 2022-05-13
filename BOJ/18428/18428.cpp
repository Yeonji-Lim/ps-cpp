#include <bits/stdc++.h>
using namespace std;
int n;
char cor[6][6];
vector<pair<int, int>> teacher;
vector<pair<int, int>> student;
vector<pair<int, int>> space;
bool ans = false;

bool isAvoidWatch() {
    bool ret = true;
    for(int t = 0; t < teacher.size(); t++) {
        int ti = teacher[t].first, tj = teacher[t].second;
        int i = ti, j;
        for(j = tj-1; j > -1; j--) {
            if(cor[i][j] == 'O') break;
            if(cor[i][j] == 'S') return false;
        }
        for(j = tj+1; j < n; j++) {
            if(cor[i][j] == 'O') break;
            if(cor[i][j] == 'S') return false;
        }
        j = tj;
        for(i = ti-1; i > -1; i--) {
            if(cor[i][j] == 'O') break;
            if(cor[i][j] == 'S') return false;
        }
        for(i = ti+1; i < n; i++) {
            if(cor[i][j] == 'O') break;
            if(cor[i][j] == 'S') return false;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cor[i][j];
            switch(cor[i][j]) {
                case 'T': teacher.emplace_back(i, j); break;
                case 'S': student.emplace_back(i, j); break;
                case 'X': space.emplace_back(i, j); break;
            }
        }
    }
    vector<bool> perm(space.size());
    fill(perm.end()-3, perm.end(), true);
    int tmp = 0;
    do {
        for(int i = 0; i < perm.size() && tmp < 4; i++) {
            if(perm[i]) {
                cor[space[i].first][space[i].second] = 'O';
                tmp++;
            }
        }
        if(isAvoidWatch()) { ans = true; break; }
        tmp = 0;
        for(int i = 0; i < perm.size() && tmp < 4; i++) {
            if(perm[i]) {
                cor[space[i].first][space[i].second] = 'X';
                tmp++;
            }
        }
        tmp = 0;
    } while(next_permutation(perm.begin(), perm.end()));
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}