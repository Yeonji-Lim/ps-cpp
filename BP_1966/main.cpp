#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    int N, M;
    vector<int> V;
    int im;
    int cnt = 1;
    int lastBigIdx = -1;

    cin >> test_case;
    for(int i=0; i<test_case; i++) {
        cin >> N >> M;
//        lastBigIdx = M;
        for(int j=0; j<N; j++) {
            cin >> im;
            V.push_back(im);
        }
        for(int j=0; j<N; j++) {
            if(V[j] > V[M]) {
                cnt++;
                lastBigIdx = j;
            }
        }
        if(lastBigIdx <= 0 || lastBigIdx == N-1) {  // 해당 원소가 제일 큰 경우!
            for(int j = 0; j<M; j++) {
                if(V[j] == V[M]) cnt++;
            }
        } else if(lastBigIdx < M) { // 여기서 부터는 사이값
            for(int j = lastBigIdx; j<M; j++) {
                if(V[j] == V[M]) cnt++;
            }
        } else if(M < lastBigIdx) {
            for(int j = 0; j<N; j++) {
                if(M <= j && j <= lastBigIdx) continue;
                if(V[j] == V[M]) cnt++;
            }
        }

        //2차 시도
//        if(lastBigIdx > M && lastBigIdx < N) {
//            for(int j=lastBigIdx; j<N; j++) {
//                if(V[j] == V[M]) cnt++;
//            }
//        } else if (lastBigIdx < M) {
//            for(int j=lastBigIdx; j<M; j++) {
//                if(V[j] == V[M]) cnt++;
//            }
//        } else if(lastBigIdx == N)


        //맨처음 시도
//
//        for(int j=0; j<N; j++) {
//            if(j == M) continue;
//            if(j<M) {
//                //같거나 크면 cnt++
//                if(V[j] >= V[M]) cnt++;
//            } else {
//                //크면 ++, 작거나 같으면 일단 무시, 마지막 큰 인덱스 기억
//                if(V[j] > V[M]) {
//                    cnt++;
//                    lastBigIdx = j;
//                }
//            }
//        }
//        //마지막 큰 인덱스 보다 뒤의 수에서 같은 값 개수 세기
//        if(lastBigIdx != M) for(int j = lastBigIdx; j<N; j++)
//            if(V[j] == V[M]) cnt++;

        printf("%d\n", cnt);
        cnt = 1;
        V.clear();
    }
    return 0;
}
