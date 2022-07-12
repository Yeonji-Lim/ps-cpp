#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> links;
vector<int> parent(1001);
vector<int> degree(1001, -1);

int grp(int a) {
    if(parent[a] == a) return a;
    return parent[a] = grp(parent[a]);
}

void join(int a, int b) {
    a = grp(a);
    b = grp(b);
    parent[a] = b;
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        degree[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        links.push_back({c, a, b});
    }
    sort(links.begin(), links.end());
    c = 0;
    for(int i = 0; i < m; i++) {
        a = links[i][1]; b = links[i][2];
        if(grp(a) == grp(b)) continue;
        join(a, b);
        c += links[i][0];
    }
    cout << c << '\n';
    return 0;
}