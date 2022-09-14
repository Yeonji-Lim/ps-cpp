#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tall[9], tot = 0, f1, f2;

    for(int i = 0; i < 9 ; i++) {
        cin >> tall[i];
        tot += tall[i];
    }

    sort(tall, tall + 9);

    for(int i = 8; i > 0; i--) {
        for(int j = i-1; j > -1; j--) {
            if(tot - tall[i] - tall[j] == 100) {
                f1 = j; f2 = i;
            }   
        }
    }

    for(int i = 0; i < 9; i++) {
        if(i == f1 || i == f2) continue;
        cout << tall[i] << endl;
    }

    return 0;
}