/* Failed */
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void ageSort(vector<tuple<int, int, string>> &people) {
//    int minIdx;
//    for(int i=0; i<people.size(); i++) {
//        minIdx = i;
//        for(int j=i+1; j<people.size(); j++) {
//            if (get<1>(people[i]) > get<1>(people[j]))
//                minIdx = j;
//            else if (get<1>(people[i]) == get<1>(people[j]))
//                if (get<0>(people[i]) > get<0>(people[j]))
//                    minIdx = j;
//        }
//        if(minIdx == i) continue;
//        tuple<int, int, string> temp = people[i];
//        people[i] = people[minIdx];
//        people[minIdx] = temp;
//    }
//}
//
//int main() {
//    int N;
//    cin >> N;
//    if(N<1||N>100000) return 0;
//    vector<tuple<int, int, string>> people;
//    int age;
//    string name;
//
//    for(int i = 0; i < N; i++) {
//        cin >> age >> name;
//        if(age<1||age>200||name.length()>100) return 0;
//        people.push_back(make_tuple(i,age,name));
//    }
//
//    ageSort(people);
//
//    for(int i = 0; i < N; i++) {
//        cout << get<1>(people[i]) << " " << get<2>(people[i]) << endl;
//    }
//    return 0;
//}

#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, char*>> merge (vector<pair<int, char*>> v1, vector<pair<int, char*>> v2) {
    vector<pair<int, char*>> ret;
    int i = 0, j = 0;
    while(i != v1.size() && j != v2.size()) {
        if(v1[i].first < v2[j].first) {
            ret.push_back(v1[i]);
            i++;
        } else if(v1[i].first > v2[j].first) {
            ret.push_back(v2[j]);
            j++;
        } else {
            if(i < j) {
                ret.push_back(v1[i]);
                i++;
            } else {
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

vector<pair<int, char*>> customSort (vector<pair<int, char*>> v) {
    if(v.size() == 1 || v.empty()) return v;
    vector<pair<int, char*>> ret, l, r;
    l.insert(l.end(), v.begin(), v.begin()+v.size()/2);
    r.insert(r.end(), v.begin()+v.size()/2, v.end());
    l = customSort(l);
    r = customSort(r);
    ret = merge(l, r);
    return ret;
}

int main() {
    int n, i, age;
    char name[101];
    vector<pair<int, char*>> v;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %s", &age, name);
        v.push_back(make_pair(age, name));
    }

    v = customSort(v);
    for(i = 0; i < n; i++) {
        printf("%d %s\n", v[i].first, v[i].second);
    }
    return 0;
}