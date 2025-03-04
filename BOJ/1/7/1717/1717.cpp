#include <bits/stdc++.h>
using namespace std;
vector<int> parent(1000001, 0); 

int group(int a) {
    if(parent[a] == a) return a;
    return parent[a] = group(parent[a]);
}

void join(int a, int b) {
    a = group(a);
    b = group(b);
    parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b, c;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if(!a) {
            join(b, c);
        } else {
            if(group(b) == group(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}