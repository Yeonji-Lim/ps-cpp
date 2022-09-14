#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> people;
vector<int> it(1024*512*2);

bool comparePower(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool compareIndex(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, p;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p;
        people.emplace_back(i, p);
    }
    sort(people.begin(), people.end(), comparePower);
    for(int i = 0; i < n; i++) {
        people[i].second = i;
    }
    sort(people.begin(), people.end(), compareIndex);

    int tmpn, a, b, sum = 0;
    for(tmpn = 1; tmpn < n; tmpn*=2);
    for(int i = 0; i < n; i++) {
        a = tmpn; b = tmpn+people[i].second-1;
        while(a <= b) {
            if((a&1) == 1) sum += it[a];
            if((b&1) == 0) sum += it[b];     
            b = (b-1) >> 1;
            a = (a+1) >> 1;
        }

        a = tmpn+people[i].second;
        while(a > 0) {
            it[a] += 1;
            a = a>>1;
        }
        cout << people[i].first - sum << '\n';
        sum = 0;
    }
}