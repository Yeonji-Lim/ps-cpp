#include <iostream>
using namespace std;
int n, l, w, h;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(15);
    
    double s, e, m;
    cin >> n >> l >> w >> h;
    s = 0;
    e = max(l, max(w, h));
    
    while(s < e) {
        m = (s+e)/2;
        if ((long long)(l/m)*(long long)(w/m)*(long long)(h/m) >= n) {
            if(s == m) break;
            s = m;
        }
        else {
            if(e == m) break;
            e = m;
        }
    }
    cout << m << '\n';
}