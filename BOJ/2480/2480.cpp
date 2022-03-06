#include <iostream>
using namespace std;
int main() {
    int a, b, c, ans;
    cin >> a >> b >> c;
    if(a == b && b == c) {
        ans = 10000 + a*1000;
    }else if(a != b && b != c && a != c){
        ans = a > b? (a > c? a: c): (b > c? b: c);
        ans *= 100;
    }else{
        if(a == b || a == c) ans = 1000 + a*100;
        else ans = 1000 + b*100;
    }
    cout << ans << endl;
    return 0;
}