#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int data;
    int L, R, mid;
    deque<int> D;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> data;
        D.push_back(data);
    }
    sort(D.begin(), D.end());
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> data;
        L = 0; R = D.size()-1;
        while(true) {
            if(L > R) {
                printf("0\n");
                break;
            }
            mid = (L+R)/2;
            if(data == D[mid]) {
                printf("1\n");
                break;
            }
            else if(data > D[mid]) {
                L = mid+1;
            } else {
                R = mid-1;
            }
        }
    }
    return 0;
}
