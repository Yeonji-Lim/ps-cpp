#include <iostream>
#include <cmath>

using namespace std;

pair<long long, long long> getCoordinate(int num, int d, pair<long long, long long> p) {
    long long i = p.first; long long j = p.second;
    d -= 1;
    switch (num)
    {
    case 1:
        j += pow(2, d);
        break;
    case 3:
        i += pow(2, d);
        break;
    case 4:
        i += pow(2, d);
        j += pow(2, d);
        break;
    default:
        break;
    }
    return make_pair(i, j);
}

int getNum(long long &i, long long &j, int d) {
    int cal = pow(2, --d);
    if(i >= cal) {
        i -= cal;
        if(j >= cal) {
            j -= cal;
            return 4;
        } else {
            return 3;
        }
    } else {
        if(j >= cal) {
            j -= cal;
            return 1;
        } else {
            return 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d;
    string n;
    cin >> d >> n;
    int x, y;
    cin >> x >> y;
    
    long long i = 0, j = 0;
    int num = 0, td=d;

    for(int k = 0; k < n.length(); k++) {
        num = n[k] - '0';
        pair<long long, long long> p = getCoordinate(num, td, make_pair(i, j));
        i = p.first; j = p.second;
        td--;
    }
    
    j += x;
    i -= y;
    if (i < 0 || i >= pow(2, d) || j < 0 || j >= pow(2, d)) {
        cout << -1 << '\n';
        return 0;
    }

    for(d; d > 0; d--) {
        num = getNum(i, j, d);
        cout << num;
    }
    cout << '\n';
    return 0;
}