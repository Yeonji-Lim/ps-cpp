/* Solved - 1988KB 0ms*/
//#include <iostream>
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int T;
//    int cnt = 0;
//    string str;
//
//    cin >> T;
//    for(int i=0; i<T; i++) {
//        cin >> str;
//        for(int j=0; j<str.length() && cnt >= 0; j++) {
//            str[j] == '('? cnt++ : cnt--;
//        }
//        cnt == 0? printf("YES\n") : printf("NO\n");
//        cnt = 0;
//    }
//    return 0;
//}
