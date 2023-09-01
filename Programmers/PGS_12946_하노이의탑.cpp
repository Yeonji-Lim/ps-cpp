#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void go(int cur, int togo, int rest, int cn) {
    if(cn == 1) {
        answer.push_back({cur, togo});
        return;
    }
    go(cur, rest, togo, cn-1);
    answer.push_back({cur, togo});
    go(rest, togo, cur, cn-1);
}

vector<vector<int>> solution(int n) {
    go(1, 3, 2, n);
    return answer;
}

/*
1, 3
1, 2
3, 2
1, 3
2, 1
2, 3
1, 3
 
cur, togo, rest
n개를 cur에서 togo로 옮기려면 n-1개를 rest에 옮겨야 함

*/