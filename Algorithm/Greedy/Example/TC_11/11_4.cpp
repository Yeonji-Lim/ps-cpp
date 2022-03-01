#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, t = 0;
vector<int> coin;

set<int> money() {
    set<int> s;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; i++) {
            
        }
    }


    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    coin.resize(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    sort(coin.begin(), coin.end());

    
    
    return 0;
}