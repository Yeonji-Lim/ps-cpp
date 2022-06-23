# vector & sort

구조체 가지고 벡터에 정렬해야 할 때

~~~
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int i;
    int j;
    Node* parent = NULL;
    int g = 0;
    int h = 0;
    Node(int _i, int _j, Node* _parent, int _g, int _h) : i(_i), j(_j), parent(_parent), g(_g), h(_h){};
};

bool compare(Node* a, Node* b) {
    return a->g+a->h < b->g+b->h;
}
vector<Node*> open;

int main() {
    open.push_back(new Node(1, 1, NULL, 1, 1));
    open.push_back(new Node(0, 0, NULL, 0, 1));
    sort(open.begin(), open.end(), compare);
    return 0;
}
~~~