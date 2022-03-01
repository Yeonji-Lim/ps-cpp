/* 2021.3.20 Failed - 정수 숫자 범위 고려했는 데 틀린 거 */
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

/* 2021.3.20 Failed - 시간 초 */
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<pair<string, int>> v;
//
//string smallerNum (string a, string b) {
//    if(a[0] == '-' && b[0] == '-') {
//        if(a.length() > b.length()) { return a; }
//        else if(a.length() < b.length()) { return b; }
//        else {
//            for(int i = 1; i < a.length(); i++) {
//                if(a[i] > b[i]) { return a; }
//                else if(a[i] < b[i]) { return b; }
//            }
//        }
//    } else if(a[0] == '-') {
//        return a;
//    } else if(b[0] == '-') {
//        return b;
//    } else {
//        if(a.length() < b.length()) { return a; }
//        else if(a.length() > b.length()) { return b; }
//        else {
//            for(int i = 0; i < a.length(); i++) {
//                if(a[i] < b[i]) { return a; }
//                else if(a[i] > b[i]) { return b; }
//            }
//        }
//    }
//}
//
//bool findNum (string tmp) {
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
//    ios_base::sync_with_stdio();
//    cin.tie(NULL);
//    cout.tie(NULL);
//    int n, i;
//    string tmp;
//    cin >> n;
//    for(i = 0; i < n; i++) {
//        cin >> tmp;
//        if(!findNum(tmp)) {
//            v.push_back(make_pair(tmp, 1));
//        }
//    }
//    n = 1;
//    for(i = 0; i < v.size(); i++) {
//        if(v[i].second > n) {
//            tmp = v[i].first;
//            n = v[i].second;
//        } else if (v[i].second == n) {
//            tmp = smallerNum(tmp, v[i].first);
//        }
//    }
//    cout << tmp << '\n';
//    return 0;
//}

/* 2021.3.20 */
#include <cstdio>
#include <vector>
using namespace std;

vector<long long int> merge(vector<long long int> v1, vector<long long int> v2) {
    vector<long long int> ret;
    int i = 0, j = 0;
    while( i != v1.size() && j != v2.size()) {
        if(v1[i] < v2[j]) {
            ret.push_back(v1[i]);
            i++;
        } else {
            ret.push_back(v2[j]);
            j++;
        }
    }
    while(i != v1.size()) {
        ret.push_back(v1[i]);
        i++;
    }
    while(j != v2.size()) {
        ret.push_back(v2[j]);
        j++;
    }
    return ret;
}

vector<long long int> customSort(vector<long long int> v) {
    if(v.size() == 1 || v.empty()) { return v; }
    vector<long long int> ret, l, r;
    l.insert(l.end(), v.begin(), v.begin()+v.size()/2);
    r.insert(r.end(), v.begin()+v.size()/2, v.end());
    l = customSort(l);
    r = customSort(r);
    ret = merge(l, r);
    return ret;
}

int main() {
    int n, i, cnt = 1;
    long long int tmp;
    vector<long long int> v;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lld", &tmp);
        v.push_back(tmp);
    }
    v = customSort(v);
    n = 1;
    tmp = v[0];
    for(i = 1; i < v.size(); i++) {
        if(v[i] == v[i-1]) {
            n++;
        } else {
            if(cnt < n) {
                cnt = n;
                tmp = v[i];
            } else if(cnt == n) {
                if (tmp > v[i]) tmp = v[i];
            }
            n = 1;
        }
    }
    printf("%lld", tmp);
    return 0;
}