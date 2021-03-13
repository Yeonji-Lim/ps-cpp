/* Solved - 1988KB 0ms*/
//#include <iostream>
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int T;
//    int cnt = 0;
//    string str;
//
//    cin >> T;
//    for(int i=0; i<T; i++) {
//        cin >> str;
//        for(int j=0; j<str.length() && cnt >= 0; j++) {
//            str[j] == '('? cnt++ : cnt--;
//        }
//        cnt == 0? printf("YES\n") : printf("NO\n");
//        cnt = 0;
//    }
//    return 0;
//}

/* 2021.3.13 Solved - 1228KB 0ms */
#include <cstdio>
#include <stack>
#define LEN 51
using namespace std;

int main() {
    int t;
    char ps[LEN];
    stack<char> st;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%s", ps);
        for(int j = 0; ps[j] != '\0'; j++) {
            if(ps[j] == '(') {
                st.push('(');
            } else if(!st.empty()){
                st.pop();
            } else {
                st.push('0');
                break;
            }
        }
        if(st.empty()) { printf("YES\n"); }
        else { printf("NO\n"); }
        while(!st.empty()) { st.pop(); }
    }
    return 0;
}