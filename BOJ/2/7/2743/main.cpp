/* 2021.3.22 Solved - 2016KB 0ms, string 사용 */
//#include <iostream>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    cout << s.length() << endl;
//    return 0;
//}

/* 2021.3.22 Solved - 1116KB 0ms */
#include <cstdio>
#include <cstring>

int main() {
    char s[101];
    scanf("%s", s);
    printf("%d\n", strlen(s));
    return 0;
}