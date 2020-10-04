#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int L;
    int data;
    deque<int> sortDQ;
    deque<int> originDQ;
    deque<int>::iterator it;
    cin >> N >> L;
    for(int i=0; i<N; i++) {
        cin >> data;
        sortDQ.push_back(data);
        originDQ.push_back(data);
        if(originDQ.size() > L) {
            it = find(sortDQ.begin(), sortDQ.end(), originDQ.front());
            sortDQ.erase(it);
            originDQ.pop_front();
        }
        sort(sortDQ.begin(), sortDQ.end());
        printf("%d ", sortDQ.front());
    }
    return 0;
}
