#include <iostream>
#include <deque>
using namespace std;

//반복문을 하나 더 줄여볼 수 있을까..?
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    int h = 0;
    deque<int> DQ;
    int ans = 0;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &h);
        if(DQ.empty()) {
            DQ.push_back(h);
        }
        else {
            for(int j=0; j<DQ.size(); j++) {
                if(DQ[j] > h) ans = j+1;
            }
            DQ.push_back(h);
        }
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}
