// https://programmers.co.kr/learn/courses/30/lessons/60057

// #include <string>
// #include <vector>

// using namespace std;

// int min(int a, int b) { return a < b? a: b; }

// int solution(string s) {
//     int answer, len = s.length(), cnt;
//     string tmp, comps;
    
//     answer = len;
//     for(int u = 1; u <= len/2; u++) {
//         cnt = 1;
//         comps = "";
//         for(int start = 0; start < u; start++) {
//             tmp = s.substr(start, u);
//             for(int i = start+u; i <= len-u; i += u) {
//                 if(s.substr(i, u) == tmp) { cnt++; }
//                 else {
//                     if(cnt != 1) {
//                         comps += to_string(cnt);
//                         cnt = 1;
//                     }
//                     comps += tmp;
//                     tmp = s.substr(i, u);
//                 }
//             }
//         }
//         if(cnt != 1) comps += to_string(cnt);
//         comps += tmp;
//         answer = min(comps.length(), answer);
//     }
    
//     return answer;
// }

// -> "문자열은 제일 앞에서 부터 잘라야 한다" : 예시에 나왔다. 예시까지 꼼꼼히 읽자

// #include <string>
// #include <vector>

// using namespace std;

// int min(int a, int b) { return a < b? a: b; }

// int solution(string s) {
//     int answer, len = s.length(), cnt;
//     string tmp, comps;
    
//     answer = len;
//     for(int u = 1; u <= len/2; u++) {
//         cnt = 1;
//         comps = "";
//         tmp = s.substr(0, u);
//         for(int i = u; i <= len-u; i += u) { // -> 이부분이 틀림
//             if(s.substr(i, u) == tmp) { cnt++; }
//             else {
//                 if(cnt != 1) {
//                     comps += to_string(cnt);
//                     cnt = 1;
//                 }
//                 comps += tmp;
//                 tmp = s.substr(i, u);
//             }
//         }
//         if(cnt != 1) comps += to_string(cnt);
//         comps += tmp;
//         answer = min(comps.length(), answer);
//     }
    
//     return answer;
// }

// u 만큼 계산해서 최대한 갈 수 있는 부분까지 가려고 했던거지만 
// 생각해보면 남는 문자열이 있다면 결과 문자열에 추가가 되어야 한다. 
// 그러므로 i는 끝까지 가야함

#include <string>
#include <vector>

using namespace std;

int min(int a, int b) { return a < b? a: b; }

int solution(string s) {
    int answer, len = s.length(), cnt;
    string tmp, comps;
    
    answer = len;
    for(int u = 1; u <= len/2; u++) {
        cnt = 1;
        comps = "";
        tmp = s.substr(0, u);
        for(int i = u; i < len; i += u) {
            if(s.substr(i, u) == tmp) { cnt++; }
            else {
                if(cnt != 1) {
                    comps += to_string(cnt);
                    cnt = 1;
                }
                comps += tmp;
                tmp = s.substr(i, u);
            }
        }
        if(cnt != 1) comps += to_string(cnt);
        comps += tmp;
        answer = min(comps.length(), answer);
    }
    
    return answer;
}