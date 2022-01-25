// #include <iostream>
// using namespace std;

// int V, E;
// int table[100];

// void unionF(int x, int y) {
//     if(x < y){
//         table[y] = x;
        
//     } else if (x >y) {

//     } else return;
// }

// int findF(int x, int y) {//x <= y
//     if(x == y) return x;
//     return findF(table[y], x);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);



//     cin >> V >> E;
//     for(int i = 1; i <= V; i++) {
//         table[i] = i;
//     }

//     int x, y;
//     for(int i = 0; i < E; i++) {
//         cin >> x >> y;
//         if(x < y) {
//             findF(x, y);
//         } else {
//             table[x] = y;
//         }
//     }



//     return 0;
// }

#include <iostream>
using namespace std;

int V, E;
int parent[100];

int find_parent(int x) {
    //기존 find
    // if (parent[x] != x) return find_parent(parent[x]);
    // return x;

    //개선된 find
    if(parent[x] != x)
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

void union_parent(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if(x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;

    for(int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    int x, y;
    for(int i = 0; i < E; i++) {
        cin >> x >> y;
        union_parent(x, y);
    }

    cout << "각 원소가 속한 집합 : ";
    for(int i = 1; i <= V; i++) {
        cout << find_parent(i) << " ";
    }

    cout << endl << "부모 테이블 : ";
    for(int i = 1; i <= V; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;

    return 0;
}