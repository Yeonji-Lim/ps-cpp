/*2021.3.24 Solved - 5340KB 68ms */
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    vector<char> n;
    vector<int> rst;
    char c;
    int tmp = 0;
    scanf("%c", &c);
    while(c != '\n') {
        n.push_back(c);
        c = '*';
        scanf("%c", &c);
    }
    while(!n.empty()) {
        tmp = n[n.size()-1]-'0';
        n.pop_back();
        if(!n.empty()) {
            tmp += (n[n.size()-1]-'0')*2;
            n.pop_back();
            if(!n.empty()) {
                tmp += (n[n.size()-1]-'0')*4;
                n.pop_back();
            }
        }
        rst.push_back(tmp);
        tmp = 0;
    }
    while(!rst.empty()) {
        printf("%d", rst[rst.size()-1]);
        rst.pop_back();
    }
    return 0;
}