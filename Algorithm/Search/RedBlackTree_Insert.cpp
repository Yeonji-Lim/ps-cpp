// 2018112178 임연지
#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        Node* left = NULL;
        Node* right = NULL;
        Node* parent = NULL;
        int key = 0;
        char color = 'R'; // black은 'B', red는 'R'

        Node() {}
        Node(int k) {
            this->key = k;
        }
        void printInfo() { // Node의 정보 출력
            cout << color << " " << key << " 의 parent는 ";
            if(parent == NULL) cout << "T.nil";
            else cout << parent->key;
            cout <<" 이고, left는 ";
            if(left == NULL) cout << "T.nil";
            else cout << left->key;
            cout <<" 이고, right는 ";
            if(right == NULL) cout << "T.nil";
            else cout << right->key;
            cout <<" 입니다.\n";
        }
};
Node* empty = new Node();

class Tree { // 레드블랙트리 
    public:
        Node* root = NULL;
        Node* nil = NULL;
        Tree() {}
};
Tree T = Tree(); // 트리는 하나만 존재한다.

void printTree() { // 큐를 이용하여 트리의 노드들을 모두 출력합니다.
    queue<Node*> q;
    q.push(T.root);
    while(!q.empty()) { 
        Node* i = q.front();
        q.pop();
        if(i == T.root) cout << i->key << "는 root 노드입니다.\n";
        i->printInfo();
        if(i->left != T.nil) q.push(i->left);
        if(i->right != T.nil) q.push(i->right);
    }
    cout << "--------------------------\n";
}

void insertNode(Node* n) { // 트리에 노드를 삽입한다. 
    if(T.root == NULL) { // 루트가 없을 경우, 해당 노드가 루트가 된다.
        T.root = n;
        n->parent = T.nil;
        return;
    } 
    Node* x = T.root;
    Node* y = T.nil;
    while(x != T.nil) { // 노드가 들어갈 위치를 찾는다.
        y = x;
        if(n->key < x->key) x = x->left;
        else x = x->right;
    }
    // 노드를 삽입한다.
    n->parent = y; 
    if(n->key < y->key) y->left = n;
    else y->right = n;
    // 해당 노드의 자식노드는 T.nil로 설정한다.
    n->left = T.nil;
    n->right = T.nil;
}

void leftRotate(Node* x) { // leftRotate를 진행한다.
    Node* y = x->right; // y 설정
    // y의 왼쪽 서브트리를 x의 오른쪽 서브트리로 옮김
    x->right = y->left; 
    if(y->left != T.nil) y->left->parent = x;
    // x의 부모를 y로 연결
    y->parent = x->parent;
    if (x->parent == T.nil) T.root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    // x를 y의 왼쪽에 놓음
    y->left = x;
    x->parent = y;
}

void rightRotate(Node* x) { // rightRotate를 진행한다
    Node *y = x->left;      // y 설정
    // y의 오른쪽 서브트리를 x의 왼쪽 서브트리로 옮김
    x->left = y->right;
    if(y->right != T.nil) y->right->parent = x;
    // x의 부모를 y로 연결
    y->parent = x->parent;
    if (x->parent == T.nil) T.root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    // x를 y의 오른쪽에 놓음
    y->right = x;
    x->parent = y;
}

void makeValid(Node* n) { // 레드블랙트리의 특성에 맞게 노드들의 위치와 색상을 변경한다.
    if(T.root == n) { // 현재 삽입한 노드가 루트 노드인 경우 색상만 흑색으로 변경
        n->color = 'B';
        return;
    }
    Node* y = NULL;
    // 새로 삽입한 노드는 적색이므로, 부모가 적색이면 특성 4에 어긋난다. 이때에 수정을 진행한다.
    while(n->parent != T.nil && n->parent->color == 'R') {
        if(n->parent == n->parent->parent->left) {
            y = n->parent->parent->right;
            if (y != T.nil && y->color == 'R') { // 경우 1
                n->parent->parent->color = 'R';
                n->parent->color = 'B';
                y->color = 'B';
                n = n->parent->parent;
            } else {
                if(n == n->parent->right) { // 경우 2
                    leftRotate(n->parent); // leftRotate를 진행하여, 경우 3과 동일한 경우로 만든다.
                }
                // 경우 3
                n->parent->color = 'B';
                n->parent->parent->color = 'R';
                rightRotate(n->parent->parent);
            }
        }
    }
    T.root->color = 'B';
}

int main() {
    int A[6] = {20, 15, 14, 12, 13, 1};
    cout << "노드의 색상은 흑색은 B, 적색은 R로 표시했습니다." << endl;
    for(int i = 0; i < 6; i++) { // 반복해서 노드를 생성하여 레드블랙트리에 넣고 트리의 특성을 지키게 수정한다.
        Node* curNode = new Node(A[i]);
        insertNode(curNode);
        makeValid(curNode);
        printTree();
    }
    return 0;
}