#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    for(int i = 0; i<3; i++) {
        if(a[i] > b[i]) { cout << a << endl; break; } 
        else if(a[i] < b[i]) { cout << b << endl; break; }
    }
    return 0;
}