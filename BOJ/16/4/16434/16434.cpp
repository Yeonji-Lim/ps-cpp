#include <iostream>

using namespace std;

int n, atk;
int bang[123456][3];

bool go(long long hp) {
    int tatk = atk;
    long long maxh = hp;
    for(int i = 0; i < n; i++) {
        if(bang[i][0] == 1) { //용
            hp -= bang[i][1]*(bang[i][2]/tatk);
            if(hp <= 0) return false;
        } else { //포션
            tatk += bang[i][1];
            hp += bang[i][2];
            if(hp > maxh) hp = maxh;
        }   
    }
    return true;
}

int main() {
    cin >> n >> atk;
    for(int i = 0; i < n; i++) {
        cin >> bang[i][0] >> bang[i][1] >> bang[i][2];
    }
    long long l = 1, r = 0x3f3f3f3f3f3f3f3f, mid;
    while(l + 1 < r) {
        mid = (l + r)/2;
        if(go(mid)) r = mid;
        else l = mid;
    }
    mid = (l + r)/2;
    if(go(mid)) cout << mid << '\n';
    else cout << r << '\n';
    return 0;
}

/*
3 3
1 1 20  -6
2 3 10  
1 3 100 -48
1 6 61 -60

17  14  11  8   5   2   -1
1   2   3   4   5   6

atk : 6
cur : a - 6 + 10

100 
6 * 16 = 96

a - 6 + 10 - 3 * 16 = a - 44

a + 4 or a

몬스터만 계속 나오면 그냥 공격하는거 다 더해버리고 +1 하면 됨

3 3
1 1 20  -6
2 3 10  
1 3 100 -48
1 6 61 -60

109

3 3
1 1 20  -6
2 3 10  
1 3 100 -48
2 0 48
1 6 61 -60

61

3 3
1 1 20  -6
2 3 10  
1 3 100 -48
1 6 61 -60
2 0 50
이 이후로 51보다 커지면 다시 생각해봐야함

-60
61이었어야함 -> 11이었어야 함 -> max는 121이었어야 함

.. 파라메트릭

llmax-2^20

*/