#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    int h = 0;
    stack<pair<int, int>> S;
    int ans = 0;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> h;
        while(!S.empty() && S.top().first < h)
            S.pop();
        if(!S.empty()) ans = S.top().second + 1;
        S.push(make_pair(h,i));
        printf("%d ", ans);
        ans = 0;
    }
    printf("\n");
    return 0;
}
