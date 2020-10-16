//#include <iostream>
//using namespace std;
//
//struct Node {
//    char data;
//    Node *prevN;
//    Node *nextN;
//    Node(char data) {
//        this->data = data;
//        this->prevN = NULL;
//        this->nextN = NULL;
//    }
//};
//
//struct List {
//    Node *HEAD, *TAIL;
//    int size;
//    List() {
//        this->HEAD = new Node('*');
//        this->TAIL = this->HEAD;
//        this->size = 1;
//    }
//};
//
////실제로 커서는 노드의 사이에 있지만 여기서 cursorPtr은 커서의 바로 앞(왼쪽)에 있는 노드를 가리킨다.
//
//void moveLeft(Node **cursorPtr, List &list) {
//    if(*cursorPtr == list.HEAD) return;
//    *cursorPtr = (*cursorPtr)->prevN;
//    return;
//}
//
//void moveRight(Node **cursorPtr, List &list) {
//    if(*cursorPtr == list.TAIL) return;
//    *cursorPtr = (*cursorPtr)->nextN;
//    return;
//}
//
////cursorPtr 뒤에 Node 넣기
//void cursorInsert(char insertData, Node **cursorPtr, List &list) {
//    //새로운 노드 생성
//    Node *nodePtr = new Node(insertData);
//    //커서가 TAIL이었을 경우 새로운 노드가 TAIL이 되어야함
//    // 삽입
//    if(*cursorPtr == list.TAIL) {
//        (*cursorPtr)->nextN = nodePtr;
//        nodePtr->prevN = (*cursorPtr);
//        list.TAIL = nodePtr;
//    } else {
//        (*cursorPtr)->nextN->prevN = nodePtr;
//        nodePtr->nextN = (*cursorPtr)->nextN;
//        (*cursorPtr)->nextN = nodePtr;
//        nodePtr->prevN = (*cursorPtr);
//    }
//    //새로운 노드를 커서로 지정해야함
//    *cursorPtr = nodePtr;
//    list.size++;
//    return;
//}
//
////cursorPtr가 가리키는 Node 삭제
//void cursorDelete(Node **cursorPtr, List &list) {
//    //커서가 HEAD이었을 경우 삭제를 수행하지 않음
//    if(*cursorPtr == list.HEAD) return;
//    (*cursorPtr)->prevN->nextN = (*cursorPtr)->nextN;
//    //커서가 TAIL이었을 경우 앞칸의 노드가 TAIL이 되어야함
//    if(*cursorPtr == list.TAIL) list.TAIL = (*cursorPtr)->prevN;
//    //삭제 후에 커서의 위치를 한칸 앞으로 조정해주어야 함
//    *cursorPtr = (*cursorPtr)->prevN;
//    list.size--;
//    return;
//}
//
//int main() {
//    string testStr;
//    int M;
//    List *listPtr = new List();
//    Node *cursorPtr = (*listPtr).TAIL;
//    char command;
//    char insertData;
//
//    cin >> testStr;
//    cin >> M;
//
//    for(int i = 0; i < testStr.length(); i++) {
//        Node *nodePtr = new Node(testStr[i]);
//        cursorInsert(nodePtr->data, &cursorPtr, *listPtr);
//    }
//
//    for(int i = 0; i < M; i++ ) {
//        cin >> command;
//        switch (command) {
//            case 'P':
//                cin >> insertData;
//                cursorInsert(insertData, &cursorPtr, *listPtr);
////                for(Node *iPtr = (*listPtr).HEAD->link; iPtr != NULL; iPtr = iPtr->link) {
////                    printf("%c", iPtr->data);
////                }
////                printf("\n");
//                break;
//            case 'L':
//                moveLeft(&cursorPtr, *listPtr);
////                printf("%c\n", cursorPtr->data);
//                break;
//            case 'D':
//                moveRight(&cursorPtr, *listPtr);
////                printf("%c\n", cursorPtr->data);
//                break;
//            case 'B':
//                cursorDelete(&cursorPtr, *listPtr);
////                for(Node *iPtr = (*listPtr).HEAD->link; iPtr != NULL; iPtr = iPtr->link) {
////                    printf("%c", iPtr->data);
////                }
////                printf("\n");
//                break;
//            default:
//                break;
//        }
//
//    }
//
//    //출력 부분, HEAD 다음부터 출력한다.
//    for(Node *iPtr = (*listPtr).HEAD->nextN; iPtr != NULL; iPtr = iPtr->nextN) {
//        printf("%c", iPtr->data);
//    }
//    printf("\n");
//    free(listPtr);
//    free(cursorPtr);
//
//    return 0;
//}

#include <iostream>
#include <list>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    list<char> l;
    list<char>::iterator cur;
    int M;
    char command;
    char data;

    cin >> str;
    for(int i=0; i<str.length(); i++) {
        l.push_back(str[i]);
    }
    cur = l.end();
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> command;
        switch (command) {
            case 'L':
                if(cur != l.begin())
                    cur--;
                break;
            case 'D':
                if(cur != l.end())
                    cur++;
                break;
            case 'B':
                if(cur != l.begin()) {
                    cur = l.erase(--cur);
                }
                break;
            case 'P':
                cin >> data;
                l.insert(cur, data);
                break;
        }
    }
    for(cur=l.begin(); cur!=l.end(); cur++) {
        cout << *cur;
    }
    cout << endl;
    return 0;
}