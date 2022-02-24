// #include <iostream>
// using namespace std;

// int max(int a, int b) { return a > b? a: b; }

// bool isDone(string s) {
//     char ch = s[0];
//     for(int i = 1; i < s.length(); i++) {
//         if(s[i] != ch) return false;
//     }
//     return true;
// }

// void change(string s, int start, int end) {
//     for(int i = start; i < end; i++) {
//         if(s[i] == '0') s[i] = '1';
//         else s[i] = '0'
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     string S;
//     cin >> S;

//     int start = 0, end, pre = S[0], cnt = 1, cmp = S.length() - 1;
//     int rs, re, rst = 0;

//     while(!isDone(S)) {
//         for(int i = 0; i < S.length(); i++) {
//             if(S[i] != pre) {
//                 if(cmp < cnt){
//                     cmp = cnt;
//                     rs = start;
//                     re = end;
//                 }
//                 start = i;
//                 end = i+1;
//                 cnt = 1;
//             } else {
//                 end = i+1;
//                 cnt++;
//             }
//         }
//         change(S, rs, re);
//         rst++;
//     }

//     cout << rst << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

bool isDone(string s) {
    char ch = s[0];
    for(int i = 1; i < s.length(); i++) {
        if(s[i] != ch) return false;
    }
    return true;
}

void change(string &s, int start, int end) {
    int c = 1;
    if(s[start] == '1') c = -1;
    for(int i = start; i < end; i++) {
        s[i] += c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string S;
    cin >> S;

    int rst = 0, bet, start, end;

    while(!isDone(S)) {
        rst++;
        start = 0; 
        end = 1;
        bet = 0;
        for(int i = 1; i < S.length(); i++) {
            if(S[i-1] != S[i]) {
                bet++;
                if(bet == 2) break;
                start = i;
                end = i+1;
            } else {
                end++;
            }
        }
        change(S, start, end);
    }

    cout << rst << endl;

    return 0;
}