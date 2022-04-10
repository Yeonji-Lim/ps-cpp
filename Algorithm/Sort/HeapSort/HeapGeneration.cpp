// 2018112178 임연지
#include <iostream>
using namespace std;

// 배열 출력 함수
void printArray(int A[]) { for(int i = 0; i < 10; i++) { cout << A[i] << " "; } cout << endl; }

// 힙 생성 함수 (2/2 이용)
void makeHeap(int A[], int root, int last_node) { // A[root+1:last_node]는 이미 힙 구조를 가진다.
    int parent, left, right, child, root_value;
    parent = root;          // 부모 노드
    root_value = A[root];   // 부모 노드 값
    left = 2*parent+1;      // 왼쪽 자식 노드
    right = left+1;         // 오른쪽 자식 노드
    while(left <= last_node) {
        if(right <= last_node && A[left] < A[right]) child = right; //left, right 중 큰 걸 child로 선정
        else child = left;
        if(root_value < A[child]) { // 루트노드의 값보다 child노드의 값이 크면
            A[parent] = A[child];   // child를 위로 올림
            parent = child;         // child가 parent로
            left = 2*parent+1;      // left, right 다시 지정
            right = left+1;
        } else break;
    }
    A[parent] = root_value;
}

int main() {
    int A[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for(int i = 10/2; i > -1; i--) {
        makeHeap(A, i, 10-1);
        printArray(A);
    }
    return 0;
}