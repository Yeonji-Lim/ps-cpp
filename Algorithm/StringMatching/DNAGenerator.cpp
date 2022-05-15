// 2018112178 임연지
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    srand((unsigned int)time(NULL));    // 랜덤 시드값 생성 
    ofstream fout;                      // 출력 파일
    fout.open("input.txt", ios_base::out|ios_base::app); // 출력 파일 설정, 이어쓰기 옵션 사용
    char base[4] = {'A', 'C', 'G', 'T'};                  // 염기서열 종류 저장
    int idx;        // 랜덤 인덱스 저장

    for (int i = 0; i < 1000000; i++) { // DNA 염기서열의 길이 : 1000000
        idx = rand() % 4;   // 랜덤 인덱스 생성
        fout << base[idx];  // 해당 인덱스의 염기를 파일에 출력(이어쓰기)
    }
    fout.close();   // 파일 닫기
    cout << "DNA 염기서열 파일 생성 : input.txt\n";
    return 0;
}