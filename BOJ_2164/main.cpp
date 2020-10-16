#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    deque<int> cards;
    int data;

    cin >> N;
    for(int i=1; i<N+1; i++) {
        cards.push_back(i);
    }
    while(cards.size() != 1) {
        cards.pop_front();
        if(cards.size() == 1) break;
        cards.push_back(cards.front());
        cards.pop_front();
    }
    printf("%d\n", cards.front());
    return 0;
}
