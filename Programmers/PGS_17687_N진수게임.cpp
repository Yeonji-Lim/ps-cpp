#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
int N;

map<char, int> num = {
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, 
    {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, 
    {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, 
    {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
};

char fun(char tn) {
    int cn = num[tn];
    if(cn+1 == N) return '0';
    if(cn+1 == 10) return 'A';
    return cn+1;
}

string solution(int n, int t, int m, int p) {
    N = n;
    string answer = "";
    string tot = "0";
    string cur = "0";
    char tmp;
    int idx;
    for(int i = 0; i < 1024*8; i++) {
        if(tot.length() > m*t) break;
        idx = cur.length()-1;
        tmp = fun(cur[idx]);
        cur[idx--] = tmp;
        while(tmp == '0') {
            if(idx < 0) {
                cur = "1" + cur;
                idx = 0;
                break;
            }
            tmp = fun(cur[idx]);
            cur[idx--] = tmp;
        }
        tot += cur;
        cout << cur << "\n";
    }
    for(int i = 0; i < t; i++) {
        answer += tot[p+i*p];
    }
    return answer;
}