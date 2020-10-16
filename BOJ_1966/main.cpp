#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, M;
    int im;
    queue<pair<int, int>> Q;
    priority_queue<int> PQ;

    cin >> T;
    for(int j=0; j<T; j++) {
        cin >> N >> M;
        for(int i=0; i<N; i++) {
            cin >> im;
            Q.push(make_pair(im, i));
            PQ.push(im);
        }
        im = 0; // 출력 횟수
        while(true) {
            if(Q.front().first == PQ.top()) { // 출력하는 경우
                im++;
                if(Q.front().second == M) { // 우리가 찾고자하는 원소인 경우
                    printf("%d\n", im);
                    break;
                }
                Q.pop();
                PQ.pop();
            } else { // 출력하지 않는 경우 : 뒤로 보내기
                Q.push(Q.front());
                Q.pop();
            }
        }
        while(!PQ.empty()) { //다음 테스트 케이스를 위해 비워주기
            PQ.pop();
            Q.pop();
        }
    }
    return 0;
}

//4차 시도
//bool compare (const pair<int, int> &a, const pair<int, int> &b) {
//    if(a.first == b.first)
//        return a.second < b.second;
//    return a.first > b.first;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int test_case;
//    int N, M;
//    int im;
//    pair<int, int> p;
//    pair<int, int> mp;
//    vector<pair<int, int>> V;
//    vector<pair<int, int>>::iterator it;
//
//    cin >> test_case;
//    for(int i=0; i<test_case; i++) {
//        cin >> N >> M;
//        for (int j = 0; j < N; j++) {
//            cin >> im;
//            p = make_pair(im, j);
//            V.push_back(p);
//            if(j == M) mp = p;
//        }
//        sort(V.begin(), V.end(), compare);
//        for(int j = 0; j < V.size(); j++) {
//            if(V[j].first > mp.first) {
//                N = V[j].second; // lastBigIdx
//                continue;
//            } else if(V[j].first == mp.first) {
//                M = V[j].second; //
//            }
//        }
//        V.clear();
//    }
        //3차 시도
//        lastBigIdx = M;
//        for(int j=0; j<N; j++) {
//            cin >> im;
//            V.push_back(im);
//        }
//        for(int j=0; j<N; j++) {
//            if(V[j] > V[M]) {
//                cnt++;
//                lastBigIdx = j;
//            }
//        }
//        if(lastBigIdx <= 0 || lastBigIdx == N-1) {  // 해당 원소가 제일 큰 경우!
//            for(int j = 0; j<M; j++) {
//                if(V[j] == V[M]) cnt++;
//            }
//        } else if(lastBigIdx < M) { // 여기서 부터는 사이값
//            for(int j = lastBigIdx; j<M; j++) {
//                if(V[j] == V[M]) cnt++;
//            }
//        } else if(M < lastBigIdx) {
//            for(int j = 0; j<N; j++) {
//                if(M <= j && j <= lastBigIdx) continue;
//                if(V[j] == V[M]) cnt++;
//            }
//        }

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

// 3차 시도
//        printf("%d\n", cnt);
//        cnt = 1;
//        V.clear();
//    }
//    return 0;
//}
