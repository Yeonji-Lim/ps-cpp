/* 2021.3.18 Solved - 34544KB 300ms*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Data {
    string name;
    int ko;
    int en;
    int ma;
};

vector<Data> merge (vector<Data> v1, vector<Data> v2) {
    vector<Data> ret;
    int i = 0, j = 0;
    while(i != v1.size() && j != v2.size()) {
        if(v1[i].ko > v2[j].ko) {
            ret.push_back(v1[i]);
            i++;
        } else if(v1[i].ko < v2[j].ko) {
            ret.push_back(v2[j]);
            j++;
        } else {
            if(v1[i].en < v2[j].en) {
                ret.push_back(v1[i]);
                i++;
            } else if(v1[i].en > v2[j].en) {
                ret.push_back(v2[j]);
                j++;
            } else {
                if(v1[i].ma > v2[j].ma) {
                    ret.push_back(v1[i]);
                    i++;
                } else if(v1[i].ma < v2[j].ma) {
                    ret.push_back(v2[j]);
                    j++;
                } else {
                    if(v1[i].name < v2[j].name) {
                        ret.push_back(v1[i]);
                        i++;
                    } else {
                        ret.push_back(v2[j]);
                        j++;
                    }
                }
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

vector<Data> customSort (vector<Data> v) {
    if(v.size() == 1 || v.empty()) return v;
    vector<Data> ret, l, r;
    l.insert(l.end(), v.begin(), v.begin()+v.size()/2);
    r.insert(r.end(), v.begin()+v.size()/2, v.end());
    l = customSort(l);
    r = customSort(r);
    ret = merge(l, r);
    return ret;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i;
    scanf("%d", &n);
    vector<Data> v(n);
    for(i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;
    }
    v = customSort(v);
    for(i = 0; i < n; i++) {
        cout << v[i].name << '\n';
    }
    return 0;
}
