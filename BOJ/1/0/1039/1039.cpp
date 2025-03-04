#include <bits/stdc++.h>
using namespace std;

string swap(string str, int i, int j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    return str;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int k, len;
    string str;
    cin >> str >> k;
    len = str.length();
    if(len == 1) {
        cout << "-1\n";
        return 0;
    }
    priority_queue<string, vector<string>, less<string>> pq[2];
    int t = 0, nt = 1, cnt = 0;
    pq[t].push(str);
    string prev = "";
    while(cnt < k) {
        while(!pq[t].empty()) {
            str = pq[t].top();
            pq[t].pop();
            if(prev == str) continue;
            prev = str;
            for(int i = 0; i < len; i++) {
                for(int j = i+1; j < len; j++) {
                    if(i == 0 && str[j] == '0') continue;
                    pq[nt].push(swap(str, i, j));
                }
            }
        }
        t = nt;
        nt = (nt + 1) & 1;
        cnt++;
        prev = "";
    }
    if(pq[t].empty()) str = "-1";
    else str = pq[t].top();
    cout << str << '\n';
    return 0;
}