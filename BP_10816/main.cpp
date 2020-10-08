#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> V;

int SearchIdx(int x) {
    pair<int, int> p = make_pair(x,-1);
    int L=0, R=V.size();
    int mid;
    while(L<=R) {
        mid=(L+R)/2;
        if(x == V[mid].first) {
            p = V[mid];
        } else if(x >= V[mid].first) {
            L = mid+1;
        } else {
            R = mid-1;
        }
    }
    return p.second == -1? -1: mid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int data;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> data;
        sort(V.begin(), V.end());
        if(V.empty()) {
            V.push_back(make_pair(data, 1));
            continue;
        }
        M = SearchIdx(data);
        if(M == -1) { // V가 비어있거나 처음 들어가는 원소인 경우
            V.push_back(make_pair(data, 1));
        } else {
            V[M].second++;
        }
    }

    cin >> M;
    for(int i=0; i<M; i++) {
        N = SearchIdx(data);
        N == -1? printf("0 "): printf("%d ",V[N].second);
    }

    return 0;
}
