// 2018112178 임연지
#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
using namespace std;

// D 계산 과정에서 순차적으로 mod 연산을 하여 overflow가 발생하지 않도록 한다.
int calculateD(int d, int q, int m) {
    int D = 1;
    for(int i = 0; i < m-1; i++) {
        D *= d;
        D %= q;
    }
    return D;
}

int main() {
    time_t start, end;      // 수행시간 저장
    string text, pattern;   // text와 pattern 문자열 저장
    vector<int> ans;        // 찾은 결과 목록
    int d = 53;             // 공백 포함 대소문자 알파벳의 수
    int q = 13;             // hash 버킷의 크기
    
    // 문자열 입력
    cout << "Text String : ";
    getline(cin, text, '\n');
    cout << "Pattern String : ";
    getline(cin, pattern, '\n');

    start = clock(); // 시작 시간 기록
    
    // mod 연산을 미리 하여 수의 크기를 줄인다. 
    int D = calculateD(d, q, pattern.length());
    int h = 0, t = 0;
    int tmp, i;
    for(i = 0; i < pattern.length(); i++) {
        h = (d*h + pattern[i]) % q; // 패턴 문자열의 hash값
        t = (d*t + text[i]) % q;    // text 문자열의 처음 hash값
    }
    // 0..text.length()-pattern.length()+1 의 범위를 하나씩 인덱스를 옮겨가며 탐색
    for(int s = 0; s < text.length()-pattern.length()+1; s++) {
        if(h == t) { // 같은 hash 값을 가짐
            for(i = 0; i < pattern.length(); i++) if(pattern[i] != text[s+i]) break; // 실제 값이 같지 않은 경우 반복문 탈출
            if(i == pattern.length()) {
                ans.push_back(s); // 실제 값과 같다면 결과 목록에 추가
            }
        }
        if(s < text.length()-pattern.length()) {
            t = (d*(t - text[s]*D) + text[s+pattern.length()]) % q;
            if(t < 0) t += q;
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
    cout << (double)end-start << " ms 입니다.\n";
    return 0;
}