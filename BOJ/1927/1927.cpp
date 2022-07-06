#include <bits/stdc++.h>
using namespace std;
int min_heap[1024*128*2];
int ti = 1;

void swap(int i, int j) {
    int tmp = min_heap[i];
    min_heap[i] = min_heap[j];
    min_heap[j] = tmp;
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
                cout << "0\n";
                continue;
            }
            cout << min_heap[1] << '\n';
            min_heap[1] = min_heap[--ti];
            if(ti <= 2) continue;
            int c = 1, l, r;
            while(c < ti) {
                l = c*2; r = c*2+1;
                if(l >= ti) break; // 자식 없음
                if(min_heap[c] < min_heap[l]) { // 왼쪽 자식 정상
                    if(r >= ti) break; // 오른쪽 자식 없음
                    if(min_heap[c] < min_heap[r]) break; // 오른쪽 자식 정상
                }
                if(min_heap[l] > min_heap[r]) l++; // 더 작은 자식 선택
                swap(c, l);
                c = l;
            }
        } else {
            min_heap[ti] = num;
            ti++;
            if(ti == 2) continue;
            int c = ti-1, p = (c >> 1);
            while(c > -1) {
                if(min_heap[p] < min_heap[c]) break;
                swap(p, c);
                c = p;
                p = (c >> 1);
            }
        }
    }
    return 0;
}