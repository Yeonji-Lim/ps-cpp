#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int V, E, rst = 0;
int parent[100];
vector<tuple<int, int, int>> vec;
vector<tuple<int, int, int>> min_sptr;

static bool cmp_sort(tuple<int, int, int> &x, tuple<int, int, int> &y) {
    return get<2>(x) < get<2>(y);
}

int find_parent(int child)
{
    if(parent[child] != child) {
        parent[child] = find_parent(parent[child]);
    }
    return parent[child]; // child;가 아님
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;

    for(int x=1; x<=V; x++) {
        parent[x] = x;
    }

    int i, j, k;
    for(int x = 0; x < E; x++) {
        cin >> i >> j >> k;
        vec.emplace_back(i, j, k);
    }

    sort(vec.begin(), vec.end(), cmp_sort);

    for(int x = 0 ; x < E; x++) {
        i = get<0>(vec[x]);
        j = get<1>(vec[x]);
        // cout << i << " " << j << " " << get<2>(vec[x]) << endl;
        if (find_parent(i) != find_parent(j)){ //사이클 발생하지 않음
            // cout << "o" << endl;
            union_parent(i, j);
            rst += get<2>(vec[x]);
            min_sptr.push_back(vec[x]);
        } 
        // for(int y = 1; y <= V; y++) {
        //     cout << y << " : " << parent[y] << endl;
        // }
    }

    cout << rst << endl;

    return 0;
}