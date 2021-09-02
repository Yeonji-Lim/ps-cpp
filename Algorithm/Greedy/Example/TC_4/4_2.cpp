/* 시각 */
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);
    int n, h = 0, m = 0, s = 0, ans = 0;
    cin >> n;
    while( h <= n ){
        if (h/10 == 3 || h%10 == 3){
            ans += 60*60;
            h++;
            continue;
        }
        if (m/10 == 3 || m%10 == 3){
            ans+= 60;
            if(m == 59){
                h++;
                m = 0;
            }
            else m++;
            continue;
        }
        if (s/10 == 3 || s%10 == 3) ans++;

        if(s == 59){
            if(m == 59){
                h++;
                m = 0;
            }
            else m++;
            s = 0;
        }
        else s++;
    }
    /*
    for(int h = 0; h <= n; h++) {
        for(int m = 0; m < 60; m++) {
            for(int s = 0; s < 60; s++) {
                if(h/10 == 3 || h%10 == 3 || m/10 == 3 || m%10 == 3 || s/10 == 3 || s%10 == 3) ans++;
            }
        }
    }
    */
   
    cout << ans << endl;
    return 0;
}