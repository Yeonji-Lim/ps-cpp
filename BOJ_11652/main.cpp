/* 2021.3.20 Failed - 정수 숫자 범위 고려 안함 */
//#include <cstdio>
//#include <vector>
//using namespace std;
//vector<pair<float, int>> v;
//
//bool findNum (float tmp) {
//    for(int i = 0; i < v.size(); i++) {
//        if(v[i].first == tmp) {
//            v[i].second++;
//            return true;
//        }
//    }
//    return false;
//}
//
//int main() {
//    int n, i;
//    float tmp;
//    scanf("%d", &n);
//    for(i = 0; i < n; i++) {
//        scanf("%f", &tmp);
//        if(!findNum(tmp)) {
//            v.push_back(make_pair(tmp, 1));
//        }
//    }
//    n = 1;
//    for(i = 0; i < v.size(); i++) {
//        if(v[i].second > n) {
//            n = v[i].second;
//            tmp = v[i].first;
//        } else if(v[i].second == n && v[i].first < tmp) {
//            tmp = v[i].first;
//        }
//    }
//    printf("%d\n", tmp);
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;
vector<pair<string, int>> v;

string smallerNum (string a, string b) {
    if(a[0] == '-' && b[0] == '-') {
        if(a.length() > b.length()) { return a; }
        else if(a.length() < b.length()) { return b; }
        else {
            for(int i = 1; i < a.length(); i++) {
                if(a[i] > b[i]) { return a; }
                else if(a[i] < b[i]) { return b; }
            }
        }
    } else if(a[0] == '-') {
        return a;
    } else if(b[0] == '-') {
        return b;
    } else {
        if(a.length() < b.length()) { return a; }
        else if(a.length() > b.length()) { return b; }
        else {
            for(int i = 0; i < a.length(); i++) {
                if(a[i] < b[i]) { return a; }
                else if(a[i] > b[i]) { return b; }
            }
        }
    }
}

bool findNum (string tmp) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first == tmp) {
            v[i].second++;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i;
    string tmp;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> tmp;
        if(!findNum(tmp)) {
            v.push_back(make_pair(tmp, 1));
        }
    }
    n = 1;
    for(i = 0; i < v.size(); i++) {
        if(v[i].second > n) {
            tmp = v[i].first;
            n = v[i].second;
        } else if (v[i].second == n) {
            tmp = smallerNum(tmp, v[i].first);
        }
    }
    cout << tmp << '\n';
    return 0;
}