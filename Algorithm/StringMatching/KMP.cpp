// 2018112178 임연지
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// 패턴 문자열의 최대 접두부 테이블을 생성한다.
vector<int> computeSP(string pattern) {
    vector<int> SP(pattern.length()); // 최대 접두부 테이블
    int i, j = 0;
    for (i = 1; i < pattern.length(); i++) {
        // 두 위치의 문자가 같지 않으면
        while(j > 0 && pattern[j] != pattern[i])
            // SP 테이블에서 prefix와 suffix가 일치하는 이전의 최대 길이를 구한다.
            j = SP[j - 1]; 

        // 두 위치의 문자가 같으면 다음 j위치의 문자와 비교
        if(pattern[j] == pattern[i]) j++;

        // j를 현재 위치의 SP 테이블에 기록
        SP[i] = j;
    }
    return SP;
}

int main() {
    time_t start, end;    // 수행시간 저장
    string text, pattern; // text와 pattern 문자열 저장
    vector<int> ans;      // 찾은 결과 목록

    // 문자열 입력
    cout << "Text String : ";
    getline(cin, text, '\n');
    cout << "Pattern String : ";
    getline(cin, pattern, '\n');

    start = clock(); // 시작 시간 기록

    vector<int> SP = computeSP(pattern);
    int i, j = 0;
    for(i = 0; i < text.length(); i++) {
        while(j > 0 && pattern[j] != text[i])   // 두 문자가 같지 않은 경우,
            j = SP[j-1];    // SP 테이블에서 prefix와 suffix가 일치하는 이전의 최대 길이를 구한다.

        // 두 문자가 같은 경우
        if(pattern[j] == text[i]) {
            // j가 pattern의 마지막 문자의 인덱스라면 일치하는 문자열을 찾은 것
            if(j == pattern.length() - 1) {
                ans.push_back(i-pattern.length()+1); // 시작하는 인덱스를 결과 목록에 추가
                j = SP[j];
            } else j++; // 아니면 다음 문자 비교
        }
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
    cout << (double)end - start << " ms 입니다.\n";
    return 0;
}