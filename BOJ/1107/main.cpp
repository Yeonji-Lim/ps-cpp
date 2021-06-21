//#include <iostream>
//bool numbers[10];
//using namespace std;
//
//int toI(char c) { return c - '0'; }
//char toC(int i) { return i+'0'; }
//int dif(string a, string b) {
//    int ret = 0;
//    string tmp;
//    for(int i = 0; i < a.length(); i++) {
//        if(a[i] == b[i]) i++;
//        if(b[i] > a[i]) {
//            tmp = b;
//            b = a;
//            a = tmp;
//            break;
//        }
//    }
//
//    return ret;
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//    string n, str = "100";
//    int m, tmp, rst = 0, i;
//    cin >> n;
//    cin >> m;
//    for(i = 0; i < 10; i++) numbers[i] = true;
//    for(i = 0; i < m; i++) {
//        cin >> tmp;
//        numbers[tmp] = false;
//    }
//    i = 0;
//    while(i < n.length()) {
//        if(i < str.length() && str[i] == n[i]) i++;
//        tmp = toI(n[i]);
//        while(!numbers[tmp]) tmp++;
//        if(tmp != toI(n[i])) {
//            m = toI(n[i]);
//            while(!numbers[m]) m--;
//            if(toI(n[i])-m < tmp-toI(n[i])) tmp = m;
//        }
//        if(i < str.length()) str[i] = tmp;
//        else str += toC(tmp);
//        rst++;
//        i++;
//    }
//    rst += dif(str, n);
//    cout << rst;
//    return 0;
//}
