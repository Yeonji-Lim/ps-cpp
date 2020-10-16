#include <iostream>
#include <vector>
using namespace std;

void calculateRank (vector<pair<int,int>> &peopleBulk) {
    int rank = 1;
    for(int i = 0; i < (int)peopleBulk.size(); i++) {
        for(int j = 0; j < (int)peopleBulk.size(); j++) {
            if(j == i) continue;
            if(peopleBulk[i].first < peopleBulk[j].first && peopleBulk[i].second < peopleBulk[j].second) {
                rank++;
            }
        }
        cout << rank << " ";
        rank = 1;
    }
}

int main() {
    int N;
    cin >> N;
    if(N<2 || N>50) return 0;
    vector<pair<int, int>> peopleBulk;
    int height, weight;
    for(int i = 0; i < N; i++) {
        cin >> height >> weight;
        if(height<10 || height>200 || weight<10 || weight>200) return 0;
        peopleBulk.push_back(make_pair(height,weight));
    }

    calculateRank(peopleBulk);

    return 0;
}
