#include <bits/stdc++.h>

int main() {
    int n, tmp;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    tmp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[j] < v[i]) tmp++;
        }
        cout << tmp << " ";
        tmp = 0;
    }
}