#include <bits/stdc++.h>
using namespace std;
deque<int> min_heap;

void swap(int i, int j) {
    int tmp = min_heap[i];
    min_heap[i] = min_heap[j];
    min_heap[j] = tmp;
}

void setHeapInsert() {
    if(min_heap.size() == 2) return;
    int i = min_heap.size()-1;
    while(i > -1) {
        if(min_heap[i/2] < min_heap[i]) break;
        swap(i/2, i);
        i /= 2;
    }
}

void setHeapDelete() {
    if(min_heap.size() == 2) return;
    int i = 1, j;
    while(i < min_heap.size()) {
        if(2*i >= min_heap.size()) break;
        if(min_heap[i] < min_heap[2*i]) {
            if(2*i+1 >= min_heap.size()) break;
            if(min_heap[i] < min_heap[2*i+1]) break;
        }
        if(min_heap[2*i] < min_heap[2*i+1]) j = 2*i;
        else j = 2*i+1;
        swap(i, j);
        i = j;
    }
}

int main() {
    int n, num;
    cin >> n;
    min_heap.push_back(-1);
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num == 0) {
            if(min_heap.size() == 1) {
                cout << 0 << endl;
                continue;
            }
            cout << min_heap[1] << endl;
            min_heap.erase(min_heap.begin()+1);
            if(min_heap.size() == 1) continue;
            num = min_heap.back();
            min_heap.pop_back();
            min_heap.push_front(num);
            swap(0, 1);
            setHeapDelete();
        } else {
            min_heap.push_back(num);
            setHeapInsert();
        }
    }
    return 0;
}