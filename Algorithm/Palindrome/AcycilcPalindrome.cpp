// 2018112178 임연지
#include <iostream>
#include <fstream>
#define PATH "test.txt" // 입력 파일의 경로
using namespace std;

// 문자열에서 공백을 제외한 특수문자를 모두 제거한다.
string goodStr(string S) {
    for(int i = 0; i < S.length(); i++) {
        if(S[i] != ' ' && (S[i] < '0' || ('9' < S[i] && S[i] < 'A') || ('z' < S[i] && S[i] < 'a') || 'z' < S[i]))
            S.erase(i, 1);
    }
    return S;
}

int main() {
    string S;           // 문장
    bool pldrm = true;  // 회문인지 아닌지 여부

    ifstream ifs_c;     // 파일의 크기 체크 용도 
    ifs_c.open(PATH);
    ifs_c.seekg(0, ios::end);
    if (ifs_c.tellg() < 2) { // 만약 파일의 크기가 2 미만이라면 너무 작은 파일임을 알리고 종료한다.
        cout << "Too Small File\n";
        return 0;
    } ifs_c.close();
    
    ifstream ifs;       // 입력 파일
    ifs.open(PATH);
    if(ifs.is_open()) {
        while(!ifs.eof()) { // 파일의 끝에 도달할 떄까지 문장을 입력받는다.
            getline(ifs, S);
            S = goodStr(S); // 특수문자를 삭제한다.
            for (int i = 0; i < S.length()/2; i++) {
                if(S[i] != S[S.length()-1-i]) {     // 차례대로 앞의 문자와 그에 대응하는 뒤의 문자가 같지 않으면
                    pldrm = false; break;           // 회문이 아님을 저장하고, 반복을 마친다.
                }
            }
            if(pldrm) cout << "Palindrome\n";   // 회문인 경우
            else cout << "Not a Palindrome\n";  // 회문이 아닌 경우
            pldrm = true;   //초기화
        }
    } ifs.close();
    return 0;
}