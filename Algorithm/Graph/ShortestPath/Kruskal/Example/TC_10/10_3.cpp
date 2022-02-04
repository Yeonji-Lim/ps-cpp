#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int N, M, rst = 0;
vector<int> parent;
vector<tuple<int, int, int>> sp_tr_1;
vector<tuple<int, int, int>> sp_tr_2;
vector<tuple<int, int, int>> v;

bool cmpF(tuple<int, int, int> &x, tuple<int, int, int> &y) {
    return get<2>(x) < get<2>(y);
}

int find_parent(int x) {
    if(parent[x] != x) {
        parent[x] = find_parent(parent[x]);
    }
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

    for(int x = 0; x <= N; x++) {
        parent.push_back(x);
    }

    int i, j, c;
    while(M-- != 0) {
        cin >> i >> j >> c;
        union_parent(i, j);
        v.emplace_back(i, j, c);
    }

    sort(v.begin(), v.end(), cmpF);

    c = get<0>(v[0]);
    c = find_parent(c);

    for(int x = 0; x <= v.size(); x++) {
        i = find_parent(get<0>(v[x]));
        j = find_parent(get<1>(v[x]));

        if (i != j) {
            if(i == c) sp_tr_1.push_back(v[x]);
            else sp_tr_2.push_back(v[x]);
            rst += get<2>(v[x]);
        }
    }

    cout << rst << endl;

    return 0;
}