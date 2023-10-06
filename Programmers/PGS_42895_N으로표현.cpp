// #include <string>
// #include <vector>
// #include <iostream>
// #define MAXSIZE 32001
// #define MAXANS 64001

// using namespace std;

// int dp[MAXSIZE];
// vector<int> can;

// void init(int N) {
//     string numstr = to_string(N);
//     while(stoi(numstr) < MAXSIZE) {
//         dp[stoi(numstr)] = numstr.length();
//         can.push_back(stoi(numstr));
//         numstr += to_string(N);
//     }
// }

// int findAnswer(int n, int cnt) {
//     if(cnt < 0) return MAXANS;
//     if(dp[n] == 0) {
//         int tmp = 9, bonus;
//         for(int i = 0; i < can.size(); i++) {
//             bonus = to_string(can[i]).length();
//             if(n+can[i] < MAXSIZE) tmp = min(findAnswer(n+can[i], cnt-bonus)+bonus, tmp);
//             if(n-can[i] > -1) tmp = min(findAnswer(n-can[i], cnt-bonus)+bonus, tmp);
//             if(n*can[i] < MAXSIZE) tmp = min(findAnswer(n*can[i], cnt-bonus)+bonus, tmp);
//             if(n%can[i] == 0) tmp = min(findAnswer(n/can[i], cnt-bonus)+bonus, tmp);
//         }
//         dp[n] = tmp;
//     }
//     return dp[n];
// }   

// int solution(int N, int number) {
//     init(N);
//     int answer = findAnswer(number, 8);
//     return answer > 8? -1: answer;
// }

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<int>> dp(9);

void init(int N) {
    int tmp = N;
    for(int i = 1; i < 9; i++) {
        dp[i].insert(tmp);
        for(int j = 1; j < i; j++) {
            for(int iter1 : dp[j]) {
                for(int iter2 : dp[i-j]) {
                    dp[i].insert(iter1 + iter2);
                    if(iter1-iter2 > 0) dp[i].insert(iter1 - iter2);
                    dp[i].insert(iter1 * iter2);
                    if(iter1/iter2 > 0) dp[i].insert(iter1 / iter2);
                }   
            }
        }
        tmp = 10*tmp+N;
    }
}


int solution(int N, int number) {
    init(N);
    for(int i = 1; i < 9; i++) {
        if(dp[i].find(number)!=dp[i].end()) {
            return i;
        }
    }
    return -1;
}
