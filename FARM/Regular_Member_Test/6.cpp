/* #6 비만도(B) 계산 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    double h, w, sw, b;
    cin >> h >> w;
    sw = (h-100)*0.9;
    b = floor(w/sw*10000)/100;
    cout << sw <<' '<< b << endl;
    return 0;
}