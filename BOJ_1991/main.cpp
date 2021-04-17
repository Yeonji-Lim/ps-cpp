/* 2021.4.17 Solved - 1176KB 0ms */
#include <cstdio>
#include <vector>
using namespace std;
vector<pair<char, char>> tree(27);

int indexOf(char a) { return a-'A'; }

void preOrder(char a) {
    if(a == '.') return;
    printf("%c", a);
    a = indexOf(a);
    preOrder(tree[a].first);
    preOrder(tree[a].second);
}

void inOrder(char a) {
    if(a == '.') return;
    a = indexOf(a);
    inOrder(tree[a].first);
    printf("%c", a+'A');
    inOrder(tree[a].second);
}

void postOrder(char a) {
    if(a == '.') return;
    a = indexOf(a);
    postOrder(tree[a].first);
    postOrder(tree[a].second);
    printf("%c", a+'A');
}

int main() {
    int n;
    char a, b, c;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%c", &a);
        scanf("%c %c %c", &a, &b, &c);
        a = indexOf(a);
        tree[a].first = b;
        tree[a].second = c;
    }
    preOrder('A');
    printf("\n");
    inOrder('A');
    printf("\n");
    postOrder('A');
    return 0;
}