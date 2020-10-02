#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    string p;
    int n;
    string listStr;
    int data;
    deque<int> DQ;

    cin >> T;
    for(int j=0; j<T; j++) {
        cin >> p >> n >> listStr;
        // DQ에 원소 삽입
        listStr = listStr.substr(1, listStr.length() - 2) + ","; // []빼고 일관성을 위해 마지막에 , 추가
        while(listStr.length() > 1) { //1인 경우는 ',' 하나 밖에 없다는 거니까 empty라는 거
            data = stoi(listStr.substr(0, listStr.find(',')));
            DQ.push_back(data);
            listStr = listStr.substr(listStr.find(',') + 1);
        }
        // 명령 수행
        data = 0;
        for(int i=0; i<p.length(); i++) {
            if(p[i] == 'R') {   //data 변수 재활용, 0이면 front가 front, 1이면 back이 front
                data == 0? data = 1 : data = 0;
            } else {    // 버리기 명령
                if(DQ.empty()) {
                    n = -1;
                    break;
                }
                data == 0? DQ.pop_front() : DQ.pop_back();
            }
        }
        //프린트
        if(n == -1) {
            cout << "error\n";
            continue;
        }
        cout << "[";
        while(data == 0 && !DQ.empty()) {
            cout << DQ.front();
            DQ.pop_front();
            if(DQ.empty()) break;
            cout << ",";
        }
        while(data == 1 && !DQ.empty()) {
            cout << DQ.back();
            DQ.pop_back();
            if(DQ.empty()) break;
            cout << ",";
        }
        cout << "]\n";
        DQ.clear();
    }
    return 0;
}
