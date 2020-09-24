#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
    Node(int i) {
        this->data = i;
        this->link = NULL;
    }
};

struct List {
    Node *HEAD, *TAIL;
    int size;
    List() {
        this->HEAD = NULL;
        this->TAIL = NULL;
        this->size = 0;
    }
};

void insertNewNode(Node* nodePtr, List &list) {
    if(list.size == 0) {
        list.HEAD = nodePtr;
        list.TAIL = list.HEAD;
    } else {
        nodePtr->link = list.HEAD;
        list.TAIL->link = nodePtr;
        list.TAIL = nodePtr;
    }
    list.size++;
    return;
}

void deleteNode(Node *nodePtr, List &list) {
    printf("%d", nodePtr->data);
    if(nodePtr == list.HEAD) {
        list.TAIL->link = list.HEAD->link;
        list.HEAD = list.HEAD->link;
    } else if(nodePtr == list.TAIL) {
        Node *tempPtr = list.HEAD;
        while(tempPtr->link != list.TAIL) {
            tempPtr = tempPtr->link;
        }
        tempPtr->link = list.HEAD;
        list.TAIL = tempPtr;
    } else {
        Node *tempPtr = list.HEAD;
        while(tempPtr->link != nodePtr) {
            tempPtr = tempPtr->link;
        }
        tempPtr->link = nodePtr->link;
    }
    //free(nodePtr);
    list.size--;
}

int main() {
    int N, K;
    cin >> N >> K;
    List *listPtr = new List();
    for (int i = 0; i < N; i++) {
        Node* nodePtr = new Node(i+1);
        insertNewNode(nodePtr, *listPtr);
    }

    Node *nodePtr = (*listPtr).HEAD;
    Node *tempPtr;

    printf("<");
    while((*listPtr).size > 0) {
        for(int i=1; i<K; i++) {
            nodePtr = nodePtr->link;
        }
        tempPtr = nodePtr;
        nodePtr = nodePtr->link;
        deleteNode(tempPtr,*listPtr);
        if((*listPtr).size) {
            printf(", ");
        } else {
            printf(">\n");
            break;
        }
    }
    return 0;
}
