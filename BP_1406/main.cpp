#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *link;
    Node(char data) {
        this->data = data;
        this->link = NULL;
    }
};

struct List {
    Node *HEAD, *TAIL;
    int size;
    List() {
        this->HEAD = new Node('*');
        this->TAIL = this->HEAD;
        this->size = 1;
    }
};

//실제로 커서는 노드의 사이에 있지만 여기서 cursorPtr은 커서의 바로 앞(왼쪽)에 있는 노드를 가리킨다.

void moveLeft(Node **cursorPtr, List &list) {
    if(*cursorPtr == list.HEAD) return;
    Node *tempPtr;
    for(tempPtr = list.HEAD; tempPtr->link != *cursorPtr; tempPtr = tempPtr->link);
    *cursorPtr = tempPtr;
    return;
}

void moveRight(Node **cursorPtr, List &list) {
    if(*cursorPtr == list.TAIL) return;
    *cursorPtr = (*cursorPtr)->link;
    return;
}

//cursorPtr 뒤에 Node 넣기
void cursorInsert(char insertData, Node **cursorPtr, List &list) {
    //새로운 노드 생성
    Node *nodePtr = new Node(insertData);
    //삽입
    nodePtr->link = (*cursorPtr)->link;
    (*cursorPtr)->link = nodePtr;
    //커서가 TAIL이었을 경우 새로운 노드가 TAIL이 되어야함
    if(*cursorPtr == list.TAIL) list.TAIL = nodePtr;
    //새로운 노드를 커서로 지정해야함
    *cursorPtr = nodePtr;
    list.size++;
    return;
}

//cursorPtr가 가리키는 Node 삭제
void cursorDelete(Node **cursorPtr, List &list) {
    if(*cursorPtr == list.HEAD) return;
    Node *tempPtr;
    for(tempPtr = list.HEAD; tempPtr->link != *cursorPtr; tempPtr = tempPtr->link);
    tempPtr->link = (*cursorPtr)->link;

    //삭제 후에 커서의 위치를 한칸 앞으로 조정해주어야 함
    *cursorPtr = tempPtr;
    list.size--;
    return;
}

int main() {
    string testStr;
    int M;
    List *listPtr = new List();
    Node *cursorPtr = listPtr->TAIL;
    char command;
    char insertData;

    cin >> testStr;
    cin >> M;

    for(int i = 0; i < testStr.length(); i++) {
        Node *nodePtr = new Node(testStr[i]);
        listPtr->TAIL->link = nodePtr;
        listPtr->TAIL = nodePtr;
        (*listPtr).size++;
    }

    for(int i = 0; i < M; i++ ) {
        cin >> command;
        switch (command) {
            case 'P':
                cin >> insertData;
                cursorInsert(insertData, &cursorPtr, *listPtr);
                for(Node *iPtr = (*listPtr).HEAD->link; iPtr != NULL; iPtr = iPtr->link) {
                    printf("%c", iPtr->data);
                }
                printf("\n");
                break;
            case 'L':
                moveLeft(&cursorPtr, *listPtr);
                printf("%c\n", cursorPtr->data);
                break;
            case 'D':
                moveRight(&cursorPtr, *listPtr);
                printf("%c\n", cursorPtr->data);
                break;
            case 'B':
                cursorDelete(&cursorPtr, *listPtr);
                for(Node *iPtr = (*listPtr).HEAD->link; iPtr != NULL; iPtr = iPtr->link) {
                    printf("%c", iPtr->data);
                }
                printf("\n");
                break;
            default:
                break;
        }

    }

    //출력 부분, HEAD 다음부터 출력한다.
    for(Node *iPtr = (*listPtr).HEAD->link; iPtr != NULL; iPtr = iPtr->link) {
        printf("%c", iPtr->data);
    }
    printf("\n");
    free(listPtr);
    free(cursorPtr);

    return 0;
}
