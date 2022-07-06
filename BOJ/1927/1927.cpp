#include <bits/stdc++.h>
using namespace std;
int min_heap[1024*128*2];
int ti = 1;

void swap(int i, int j) {
    int tmp = min_heap[i];
    min_heap[i] = min_heap[j];
    min_heap[j] = tmp;
}

void setHeapInsert() {
    if(ti == 2) return;
    int i = ti-1, j = (i >> 1);
    while(i > -1) {
        if(min_heap[j] < min_heap[i]) break;
        swap(j, i);
        i = j;
        j = (i >> i);
    }
}

void setHeapDelete() {
    if(ti == 2) return;
    int i = 1, l, r;
    while(i < ti) {
        l = i*2; r = i*2+1;
        if(l >= ti) break;
        if(min_heap[i] < min_heap[l]) {
            if(r >= ti) break;
            if(min_heap[i] < min_heap[r]) break;
        }
        if(min_heap[l] > min_heap[r]) l++;
        swap(i, l);
        i = l;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, num;
    cin >> n;
    min_heap[0] = -1;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(num == 0) {
            if(ti == 1) {
                cout << 0 << endl;
                continue;
            }
            cout << min_heap[1] << endl;
            min_heap[1] = min_heap[--ti];
            if(ti == 1) continue;
            setHeapDelete();
        } else {
            min_heap[ti] = num;
            ti++;
            setHeapInsert();
        }
    }
    return 0;
}