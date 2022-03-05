#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> dist;
vector<pair<int, int>> cost;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int i = 0;
    dist.resize(N-1, 0);
    for(; i<N-1; i++){
        cin >> dist[i];
    }
    cost.resize(N, make_pair(0, 0));
    for(i=0; i<N; i++){
        cin >> cost[i].first;
        cost[i].second = i;
    }
    sort(cost.begin(), cost.end());

    int prev = N-1;
    long long ans = 0;
    for(i=0; i<N && prev!=0; i++) {
        if(cost[i].second >= prev) continue;
        for(int k=cost[i].second; k<prev; k++){
            ans += (long long)cost[i].first * dist[k];
        }
        prev = cost[i].second;
    }

    cout << ans << endl;
    return 0;
}