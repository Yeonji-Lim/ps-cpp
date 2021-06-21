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

#include <cstdio>

int diff(int a, int b) { return a>b? a-b: b-a; }

int main() {
    int n, m, tmp1;
    bool able[10];
    for(int i = 0; i < 10; i++) { able[i] = true; }
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &tmp1);
        able[tmp1] = false;
    }
    if(diff(n, 100) < 3) {
        printf("%d\n", diff(n, 100));
        return 0;
    }
    int tmp2, cur = 0, rst = 0, dig = 100000;
    while(dig != 0) {
        m = n/dig;
        if(m != 0) {
            m %= 10;
            if(!able[m]) {
                for(tmp1 = m+1; tmp1 < 10; tmp1++) { if(able[tmp1]) break; }
                for(tmp2 = m-1; tmp2 > -1; tmp2--) { if(able[tmp2]) break; }
                if(diff(m, tmp1) < diff(m, tmp2)) m = tmp1;
                else m = tmp2;
            }
            cur = cur*10+m;
            rst++;
        }
        dig /= 10;
    }
    rst += diff(n, cur);
    printf("%d\n", rst);
    return 0;
}