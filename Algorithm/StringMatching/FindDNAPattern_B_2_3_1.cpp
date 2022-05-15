// 20181122178 임연지
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

char pattern[8] = "ACCGTAT"; // 패턴 고정 ACCGTAT
int m = 7;                   // 패턴 길이
ofstream fout;               // 출력 파일
vector<int> SP(m);

// 패턴 문자열의 최대 접두부 테이블을 생성한다.
void computeSP() {
    int i, j = 0;
    for (i = 1; i < m; i++) {
        // 두 위치의 문자가 같지 않으면
        while(j > 0 && pattern[j] != pattern[i])
            // SP 테이블에서 prefix와 suffix가 일치하는 이전의 최대 길이를 구한다.
            j = SP[j-1]; 

        // 두 위치의 문자가 같으면 다음 j위치의 문자와 비교
        if(pattern[j] == pattern[i]) j++;

        // j를 현재 위치의 SP 테이블에 기록
        SP[i] = j;
    }
}

// KMP를 사용하여 스트링 매칭 구현
void findKMP(char str[], long long size, long long startIdx) {
    int i, j = 0;
    for(i = 0; i < size; i++) {
        while(j > 0 && pattern[j] != str[i])   // 두 문자가 같지 않은 경우,
            j = SP[j-1];    // SP 테이블에서 prefix와 suffix가 일치하는 이전의 최대 길이를 구한다.

        // 두 문자가 같은 경우
        if(pattern[j] == str[i]) {
            // j가 pattern의 마지막 문자의 인덱스라면 일치하는 문자열을 찾은 것
            if(j == m - 1) {
                fout << startIdx + i-m+1 << endl; // 시작하는 인덱스를 결과 목록에 추가
                j = SP[j];
            } else j++; // 아니면 다음 문자 비교
        }
    }
}

int main() {
    time_t start, end;
    string tmp = "";

    FILE *inf;      // 입력 파일
    char str[1024]; // 입력 문자열

    start = clock();

    // 입출력 파일 열기
    inf = fopen("./input.txt", "r");
    fout.open("output.txt", ios_base::out | ios_base::app);

    //최대 접두부 테이블 생성
    computeSP();

    // 파일 사이즈 측정
    fseek(inf, 0, SEEK_END);
    long long infSize = ftell(inf);
    fseek(inf, 0, SEEK_SET);

    // 파일 포인터가 파일 끝에 위치할 때까지 진행
    while (ftell(inf) != infSize) {
        long long start = ftell(inf);        // 버퍼의 시작 위치 : 후에 실제 위치를 계산할 때 필요
        fgets(str, 1024, inf);               // 버퍼에 문자열 저장
        long long size = ftell(inf) - start; // 문자열의 실제 사이즈
        // 스트링 매칭 진행
        findKMP(str, size, start);
        if (ftell(inf) != infSize) fseek(inf, -m, SEEK_CUR); // 파일 끝이 아닐 때만 다음 위치로 이동
        //다음 위치는 마지막에 패턴 검사를 하지 않은 것을 고려하여 이동
    }

    end = clock();

    // 결과 출력
    cout << "KMP 완료 n = " << infSize << " m = " << m << endl;
    cout << "실행 시간 : " << (double)end - start << " ms" << endl;
    fclose(inf);
    fout.close();

    return 0;
}