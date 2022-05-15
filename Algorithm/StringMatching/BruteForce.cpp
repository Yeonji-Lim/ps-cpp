// 2018112178 임연지
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main() {
    time_t start, end;      // 수행시간 저장
    string text, pattern;   // text와 pattern 문자열 저장
    bool find = true;       // 찾았는지 여부 
    vector<int> ans;        // 찾은 결과 목록

    // 문자열 입력
    cout << "Text String : ";
    getline(cin, text, '\n');
    cout << "Pattern String : ";
    getline(cin, pattern, '\n');

    start = clock(); // 시작 시간 기록
    // 0..text.length()-pattern.length()+1 의 범위를 하나씩 인덱스를 옮겨가며 탐색
    for(int i = 0; i < text.length()-pattern.length()+1; i++) { 
        // 해당 인덱스에서 pattern과 같은 부분이 나오는지 확인
        for(int j = 0; j < pattern.length(); j++) {
            // 한글자라도 다르면
            if(pattern[j] != text[i+j]) {
                find = false; // 못찾음
                break; // 반복문 탈출
            }
        }
        // 찾았다면 결과 목록에 시작 인덱스 저장
        if(find) { ans.push_back(i); }
        // 찾음 여부 초기화
        find = true;
    }
    end = clock(); // 종료 시간 기록

    // 결과 출력
    if(ans.size()==0) cout << "해당 패턴은 찾을 수 없습니다. 수행시간은 ";
    else {
        cout << "해당 패턴은 ";
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if(i != ans.size()-1 ) cout << ",";
            cout << " ";
        }
        cout << "인덱스에 있으며, 수행시간은 ";
    }
    cout << (double)end-start << " ms 입니다.\n";
    return 0;
}