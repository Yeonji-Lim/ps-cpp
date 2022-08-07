#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100000

bool isHas666(int num) {
    bool result = false;
//    vector<int> eachNumbers;
//    while(num%10 || num%100 || num % 1000 || num % 10000) {
//        eachNumbers.push_back(num%10);
//        num = num/10;
//    }
//    for(int i=0; i<(int)eachNumbers.size()-2; i++) {
//        if(eachNumbers[i]==6 && eachNumbers[i+1]==6 && eachNumbers[i+2]==6) {
//            result = true;  break;
//        }
//    }
    string testStr = to_string(num);
    if(testStr.find("666") != testStr.npos) result = true;
    return result;
}

int main() {
    int N;
    cin >> N;
    if(N<1 || N>MAX_N) return 0;
    vector<int> numbers;
//    int maxIdx;
//    if(N <= 18) maxIdx = 10;
//    else if(N <= 270 + 18) maxIdx = 100;
//    else if(N <= 3600 + 270 + 18) maxIdx = 1000;
//    else maxIdx = 10000;

//    for(int i = 0; i < maxIdx; i++) {
//        numbers.push_back(i*1000 + 666);
//
//        if(i/10) {  //i가 두자리 수
//            numbers.push_back(i/10*10000 + 666*10 + i%10);
//        } else {    //i가 한자리 수
//            numbers.push_back(666*10 + i);
//            if(i) continue;
//        }
//
//        if(i/100) { //i가 세자리 수
//            numbers.push_back(i/100*100000 + 666*100 + i%100);
//        } else {    //i가 두자리 수
//            numbers.push_back(666*100 + i);
//            if (i) continue;
//        }
//
//        if(i/1000) {
//            numbers.push_back(i/1000*1000000 + 666*1000 + i%1000);
//            numbers.push_back(666*10000 + i);
//        } else {    //i가 세자리 수
//            numbers.push_back(666*1000 + i);
//        }
//    }
//    //중복 제거
//    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
//    sort(numbers.begin(), numbers.end());


    int num = 666;
    while(numbers.size() != N) {
        if(isHas666(num)) numbers.push_back(num);
        num++;
    }
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    printf("%d\n", numbers[N-1]);
//    printf("------------------\n");
//    for(int i = 0; i < numbers.size(); i++) {
//        printf("%d\n", numbers[i]);
//    }
    return 0;
}
