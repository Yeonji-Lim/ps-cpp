#include <string>
#include <vector>

using namespace std;

vector<vector<int>> arr;

string sss(int ci, int cj, int cn) {
    string ret = "";
    bool dup = true;
    int first_ele = arr[ci][cj];
    if(cn == 2) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(first_ele != arr[ci+i][cj+j]) dup = false;
                ret += to_string(arr[ci+i][cj+j]);
            }
        }
        if(dup) return to_string(first_ele);
        return ret;
    }
    
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ret += sss(ci+cn/2*i, cj+cn/2*j, cn/2);
        }
    }
    if(ret.length() == 4) {
        string tmp = to_string(first_ele);
        for(int i = 0; i < 4 && dup; i++) {
            if(ret[i] != tmp[0]) dup = false;
        }
        if(dup) return tmp;
        return ret;
    }
}

vector<int> solution(vector<vector<int>> a) {
    
    vector<int> answer = {0, 0};
    if(a.size() == 1) {
        answer[a[0][0]]++;
    } else {
        arr = a;
        string tmp = sss(0, 0, a.size());
        for(int i = 0; i < tmp.length(); i++) {
            answer[tmp[i]-'0']++;
        }
    }
    return answer;
}