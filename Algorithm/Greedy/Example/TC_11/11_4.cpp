#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> coins;

bool isPossible(int money, vector<int> v) {
    if(find(v.begin(), v.end(), money) != v.end()) return true;
    for(int i = 0; i < v.size(); i++) {
        vector<int> tmp(v.size(), 0);
        copy(v.begin(), v.end(), tmp.begin());
        tmp.erase(tmp.begin()+i);
        if(isPossible(money-v[i], tmp)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    coins.resize(N, 0);
    int sum = 0, i;
    for(i = 0; i < N; i++) { 
        cin >> coins[i]; 
        sum += coins[i];
    }

    sort(coins.begin(), coins.end());

    for(i = 1; i <= sum+1; i++) {
        if(!isPossible(i, coins)) break;
    }

    cout << i << endl;

    return 0;
}