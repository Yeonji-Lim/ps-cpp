#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int L;
    int data;
    vector<int> V;
    vector<int>::iterator it;

    cin >> N >> L;
    for(int i=0; i<N; i++) {
        cin >> data;
        V.push_back(data);
        it = V.begin()+i;
        while(it != V.begin()-1 && it != V.begin()+i-L) {
            if(*it < data) {
                data = *it;
            }
            it--;
        }
        printf("%d ", data);
    }
    return 0;
}