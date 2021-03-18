#include <iostream>
#include <vector>
using namespace std;
struct data {
    string name;
    int ko;
    int en;
    int ma;
};

int rankName (string name) {
    int ret = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        ret += (int)name[i];
    }
    return ret;
}

vector<data> merge (vector<data> v1, vector<data> v2) {
    vector<data> ret;
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
                    if(rankName(v1[i].name) < rankName(v2[j].name)) {
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

vector<data> customSort (vector<data> v) {
    if(v.size() == 1 || v.empty()) return v;
    vector<data> ret, l, r;
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
    vector<data> v(n);
    for(i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;
    }
    v = customSort(v);
    for(i = 0; i < n; i++) {
        cout << v[i].name << '\n';
    }
    return 0;
}
