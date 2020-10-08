#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> V;

int SearchIdx(int x) {
    bool find = false;
    int L=0, R=V.size();
    int mid;
    while(L<=R) {
        mid=(L+R)/2;
        if(x == V[mid].first) {
            find = true;
            break;
        } else if(x >= V[mid].first) {
            L = mid+1;
        } else {
            R = mid-1;
        }
    }
    return find? mid: -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int data;
    pair<int, int> p;

    cin >> N;
    V.reserve(N);
    for(int i=0; i<N; i++) {
        cin >> data;
        p = make_pair(data, 1);
        V.push_back(p);
    }
    sort(V.begin(), V.end());
    for(int i=1; i<V.size(); i++) {
        if(V[i].first == V[i-1].first) {
            V[i].second += V[i-1].second;
            V.erase(V.begin()+i-1); // V[i-1] 삭제
            i--;
        }
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> data;
        N = SearchIdx(data);
        N == -1? printf("0 "): printf("%d ",V[N].second);
    }
    return 0;
}
