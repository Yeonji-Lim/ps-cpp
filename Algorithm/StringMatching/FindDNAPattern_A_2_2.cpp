// 20181122178 임연지
#include <iostream>
#include <cstdio>
#include <fstream>
#include <time.h>
using namespace std;

char pattern[1024]; // 최대 길이를 버퍼의 길이로 설정, 실제로는 \n 값이 들어가야 하므로 1023까지 가능
int m;          // 패턴 길이
ofstream fout;  // 출력 파일
char base[4] = {'A', 'C', 'G', 'T'}; // 염기서열 종류 저장

void genPattern() {
    int idx;    // 랜덤 인덱스 저장
    for (int i = 0; i < m; i++) {
        idx = rand() % 4;   // 랜덤 인덱스 생성
        pattern[i] = base[idx];
    }
}

// BruteForce를 사용하여 스트링 매칭 구현
void findBF(char str[], long long size, long long startIdx) {
    int i, j;
    //0..(버퍼의 길이)-pattern.length()+1 의 범위를 하나씩 인덱스를 옮겨가며 탐색
    for(i = 0; i < size-m+1; i++ ) {
        // 해당 인덱스에서 pattern과 같은 부분이 나오는지 확인
        for(j = 0; j < m; j++) {
            // 한글자라도 다르면
            if(pattern[j] != str[i+j]) break; // 반복문 탈출
        }
        if(j == m) fout << startIdx+i << endl; // 실제 파일에서의 인덱스 출력
    }
}

int main() {
    srand((unsigned int)time(NULL)); // 랜덤 시드값 생성

    time_t start, end;
    string tmp = "";

    FILE * inf;         // 입력 파일 
    char str[1024];     // 입력 문자열

    cout << "패턴 문자열의 크기 : ";
    cin >> m;
    genPattern();
    cout << "생성된 패턴 : " << pattern << endl;

    start = clock();

    // 입출력 파일 열기
    inf = fopen("./input.txt", "r");
    fout.open("output.txt", ios_base::out|ios_base::app);

    // 파일 사이즈 측정
    fseek(inf, 0, SEEK_END);
    long long infSize = ftell(inf);
    fseek(inf, 0, SEEK_SET);

    // 파일 포인터가 파일 끝에 위치할 때까지 진행 
    while(ftell(inf) != infSize) {
        long long start = ftell(inf);           // 버퍼의 시작 위치 : 후에 실제 위치를 계산할 때 필요
        fgets(str, 1024, inf);                  // 버퍼에 문자열 저장
        long long size = ftell(inf) - start;    // 문자열의 실제 사이즈
        // 스트링 매칭 진행
        findBF(str, size, start);
        if(ftell(inf) != infSize) fseek(inf, -m, SEEK_CUR); // 파일 끝이 아닐 때만 다음 위치로 이동
        //다음 위치는 마지막에 패턴 검사를 하지 않은 것을 고려하여 이동
    }

    end = clock();

    // 결과 출력
    cout << "BruteForce 완료 n = " << infSize << " m = " << m << endl;
    cout << "실행 시간 : " << (double)end-start << " ms" << endl;
    fclose(inf);
    fout.close();

    return 0;
}