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

// 문장이 회문인지 검사한다.
bool checkPldrm(string S) {
    if(S.length() <= 1) return true;                                            // 순환 종료 조건, 문자열의 크기가 1 이하이면 true를 반환한다.
    if(S[0] == S[S.length()-1]) return checkPldrm(S.substr(1, S.length()-2));   // 맨 앞과 맨 뒤 문자가 같으면 맨앞과뒤 문자를 제거한 문자열의 회문여부를 검사한다.
    return false;                                                               // 맨 앞과 맨 뒤 문자가 다르면 false를 반환한다.
}

int main() {
    string S;           // 문장

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
            if(checkPldrm(S)) cout << "Palindrome\n"; // 회문인 경우
            else cout << "Not a Palindrome\n"; // 회문이 아닌 경우
        }
    } ifs.close();
    return 0;
}