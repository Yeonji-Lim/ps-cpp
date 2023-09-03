#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

vector<int> solution(int n) {
    vector<int> answer;
    int stat = 0, ci =0, cj=0, br = n, i,j;
    for(i = 1; i <= n; i++) {
        v.push_back({});
        for(j = 0; j < i; j++) {
            v[i-1].push_back(0);
        }
    }
    for(int cv = 1; cv <= n*(n+1)/2; cv++) {
        switch(stat) {
            case 0:
                for(i = ci; i < n; i++) {
                    if(v[i][cj] != 0) break;
                    v[i][cj] = cv;
                    cv++;
                }
                ci = i-1;
                cj++;
                stat++;
            case 1:
                for(j = cj; j < n; j++) {
                    if(v[ci][j] !=0) break;
                    v[ci][j] = cv;
                    cv++;
                }
                cj = j-2;
                ci--;
                stat++;
            case 2:
                while(v[ci][cj] == 0) {
                    v[ci][cj] = cv;
                    ci--;
                    cj--;
                    cv++;
                }
                ci += 2;
                cj++;
                cv--;
                stat = 0;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < i+1; j++) {
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}