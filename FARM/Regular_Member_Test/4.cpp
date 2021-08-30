/* #4 계산기 만들기 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int fir, sec;
    char com;
    cin >> fir >> sec >> com;
    switch(com){
        case '+':
            cout << fir + sec << endl;
            break;
        case '-':
            cout << fir - sec << endl;
            break;
        case '*':
            cout << fir * sec << endl;
            break;
        default:
            if(sec == 0) cout << "0으로 나눌 수 없습니다.";
            cout << fir / sec << endl;
            break;
    }
    return 0;
}