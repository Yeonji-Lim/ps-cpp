// 2018112178 임연지
#include <iostream>
#include <vector>
using namespace std;

// 꺾은 선 ABC의 방향을 결정하는 함수
int direction(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
    int dir;
    if((B.second-A.second)*(C.first-A.first) > (C.second-A.second)*(B.first-A.first)) dir = 1;     // 시계 방향
    else if((B.second-A.second)*(C.first-A.first) < (C.second-A.second)*(B.first-A.first)) dir = -1;    // 반시계 방향
    // 일직선 상에 있을 때
    // 점 C가 가운데 있거나 점 A 혹은 점 B와 일치하는 경우
    else if((C.first-A.first)*(C.first-B.first) <= 0 
         || (C.second-A.second)*(C.second-B.second) <= 0) 
        dir = 0;
    // 점 B가 가운데 있는 경우
    else if((B.first-A.first)*(B.first-C.first) < 0 
         || (B.second-A.second)*(B.second-C.second) < 0 ) 
        dir = 1;
    // 점 A가 가운데 있는 경우
    else if((A.first-B.first)*(A.first-C.first) < 0 
         || (A.second-B.second)*(A.second-C.second) < 0 ) 
        dir = -1;
    return dir;
}

// 선분 AB, CD의 교차 여부 확인하는 함수
bool intersection(vector<pair<double, double>> dots) {
    // 각 점을 이해하기 쉽도록 대입
    pair<double, double> A = dots[0]; pair<double, double> B = dots[1];
    pair<double, double> C = dots[2]; pair<double, double> D = dots[3];
    // 각 선분을 기준으로 나머지 점들의 방향이 반대이면 교차임을 이용
    if((direction(A, B, C)*direction(A, B, D) <= 0) 
    && (direction(C, D, A)*direction(C, D, B) <= 0)) 
        return true;
    return false;
}

int main() {
    vector<pair<double, double>> dots; // 차례로 A, B, C, D가 입력됨
    cout << "점 A, B, C, D의 좌표를 차례로 입력\n";
    double i, j;
    for(int k = 0; k < 4; k++) {
        cin >> i >> j;
        dots.emplace_back(i, j);
    }
    // 교차 여부 확인 : 교차하면 O 아니면 X 출력
    if(intersection(dots)) cout << "O\n";
    else cout << "X\n";
    return 0;
}