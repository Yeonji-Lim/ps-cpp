/* Sovled - 6540KB 160ms */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void quickSort(vector<pair<int, int>> &locations) {
//
//    if(locations.size() <= 1) return;
//
//    int pivotInx = locations.size()/2;
//    vector<pair<int, int>> left;
//    vector<pair<int, int>> right;
//
//    for(int i = 0; i < locations.size(); i++) {
//        if(i == pivotInx) continue;
//        if(locations[i].second < locations[pivotInx].second) {
//            left.push_back(locations[i]);
//        }
//        else if (locations[i].second > locations[pivotInx].second) {
//            right.push_back(locations[i]);
//        }
//        else {
//            if(locations[i].first <= locations[pivotInx].first) {
//                left.push_back(locations[i]);
//            } else {
//                right.push_back(locations[i]);
//            }
//        }
//    }
//
//    quickSort(left);
//    quickSort(right);
//
//    left.push_back(locations[pivotInx]);
//    left.insert(left.end(), right.begin(), right.end());
//    locations = left;
//    return;
//}
//
//int main() {
//    int N;
//    cin >> N;
//    vector<pair<int, int>> locations;
//    int a, b;
//    for(int i=0; i<N; i++) {
//        cin >> a >> b;
//        locations.push_back(pair<int, int>(a, b));
//    }
//
//    quickSort(locations);
//
//    for(int i=0; i<N; i++) {
//        printf("%d %d\n", locations[i].first, locations[i].second);
//    }
//
//    return 0;
//}

/* 2021.3.18 */
#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, int>> merge (vector<pair<int, int>> v1, vector<pair<int, int>> v2) {
    vector<pair<int, int>> ret;
    int i = 0, j = 0;
    while(i != v1.size() && j != v2.size()) {
        if(v1[i].second < v2[j].second) {
            ret.push_back(v1[i]);
            i++;
        } else if(v1[i].second > v2[j].second) {
            ret.push_back(v2[j]);
            j++;
        } else {
            if(v1[i].first < v2[j].first) {
                ret.push_back(v1[i]);
                i++;
            } else if(v1[i].first > v2[j].first) {
                ret.push_back(v2[j]);
                j++;
            }
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

vector<pair<int, int>> customSort (vector<pair<int, int>> v) {
    if(v.size() == 1 || v.empty()) return v;
    vector<pair<int, int>> ret, l, r;
    l.insert(l.end(), v.begin(), v.begin()+v.size()/2);
    r.insert(r.end(), v.begin()+v.size()/2, v.end());
    l = customSort(l);
    r = customSort(r);
    ret = merge(l, r);
    return ret;
}

int main() {
    int n, i;
    pair<int, int> p = make_pair(0, 0);
    vector<pair<int, int>> v;
    scanf("%d", &n);
    for(i = 0; i < n; i++ ) {
        scanf("%d %d", p.first, p.second);
        v.push_back(p);
    }
    v = customSort(v);
    for(i = 0; i < n; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    return 0;
}