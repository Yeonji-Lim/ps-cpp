#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, rst = 0;
vector<int> X;

void makeGroup() {
    int num = X[X.size()-1], tmp = 1;
    X.erase(X.begin()+X.size()-1);

    if (num > X.size()+1) return;

    for(int i = X.size()-1; i > -1 && tmp != num; i--) {
        if(X[i] <= num) {
            tmp++;
            X.erase(X.begin()+i);
        }
    }
    if(tmp == num) rst++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    X.resize(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    while(!X.empty())
        makeGroup();
    
    cout << rst << endl;

    return 0;
}