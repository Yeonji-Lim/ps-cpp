#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num == 0) {
            if(pq.empty()) {
                cout << 0 << endl;
            } else {
                cout << pq.top() << endl;
                pq.pop();
            }
        } else {
            pq.push(num);
        }
    }
    return 0;
}