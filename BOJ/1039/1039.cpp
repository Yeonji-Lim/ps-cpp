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
    int k;
    string str;
    cin >> str >> k;
    if(str.length() == 1) {
        cout << "-1\n";
        return 0;
    }
    priority_queue<string, vector<string>, less<string>> pq[2];
    int t = 0, nt = 1, cnt = 0;
    pq[t].push(str);
    string prev = "";
    while(!pq[t].empty()) {
        if(cnt == k) break;
        str = pq[t].top();
        pq[t].pop();
        if(prev == str) continue;
        prev = str;
        for(int i = 0; i < str.length()-1; i++) {
            for(int j = i+1; j < str.length(); j++) {
                if(i == 0 && str[j] == '0') continue;
                pq[nt].push(swap(str, i, j));
            }
        }
        t = nt;
        nt = (nt+1)&1;
        cnt++;
        prev = "";
    }
    if(pq[t].empty()) str = "-1";
    else str = pq[t].top();
    cout << str << '\n';
    return 0;
}