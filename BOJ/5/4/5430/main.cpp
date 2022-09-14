#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    string p;
    int n;
    string temp;
    deque<int> DQ;
    bool rev;

    cin >> T;
    while(T--){
        rev = false;
        cin >> p >> n >> temp;
        temp = temp.substr(1, temp.length()-2);
        istringstream listStr(temp); //getline을 하기 위한 큰그림
        for(int i=0; i < n; i++) {
            getline(listStr, temp, ','); // temp 재활용
            DQ.push_back(stoi(temp));
        }
        for(int i=0; i < p.length(); i++) {
            if(p[i] == 'R') rev ? rev = false : rev = true;
            else if(DQ.empty()) {
                n = -1; //n 재활용, error detection
                break;
            }
            else rev? DQ.pop_back() : DQ.pop_front(); // D인 경우, 역방향 : 순방향
        }
        if(n == -1) {
            printf("error\n");
            continue;
        }
        printf("[");
        while(rev && !DQ.empty()) {
            printf("%d", DQ.back());
            DQ.pop_back();
            if(!DQ.empty()) printf(",");
        }
        while(!rev && !DQ.empty()) {
            printf("%d", DQ.front());
            DQ.pop_front();
            if(!DQ.empty()) printf(",");
        }
        printf("]\n");
    }

    return 0;
}
