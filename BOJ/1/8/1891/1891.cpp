#include <iostream>
#include <cmath>

using namespace std;

// 해당 숫자의 좌표를 반환하는 함수, 현재 자리의 숫자와 d의 값을 보고 판단
void getCoordinate(int num, int d, long long &i, long long &j) {
    long long cal = pow(2, d);
    switch (num) {
        case 1:
            j += cal;
            break;
        case 3:
            i += cal;
            break;
        case 4:
            i += cal;
            j += cal;
            break;
        default:
            break;
    }
}

// 해당 좌표의 숫자를 반환하는 함수, 해당 좌표가 d의 값을 기준으로 어느 사분면인지 판단
int getNum(long long &i, long long &j, int d) {
    long long cal = pow(2, d);
    if(i >= cal) {
        i -= cal;
        if(j >= cal) {
            j -= cal;
            return 4;
        } else return 3;
    } else {
        if(j >= cal) {
            j -= cal;
            return 1;
        } else return 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d;
    string n;
    cin >> d >> n;
    long long x, y;
    cin >> x >> y;
    
    long long i = 0, j = 0;
    int num = 0, td = d-1;

    for(int k = 0; k < n.length(); k++, td--) {
        num = n[k] - '0';
        getCoordinate(num, td, i, j);
    }
    
    j += x;
    i -= y;
    if (i < 0 || i >= pow(2, d) || j < 0 || j >= pow(2, d)) {
        cout << -1 << '\n';
        return 0;
    }

    while(d--) {
        num = getNum(i, j, d);
        cout << num;
    }
    cout << '\n';
    return 0;
}