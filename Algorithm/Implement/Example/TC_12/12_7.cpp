#include <iostream>
using namespace std;

bool isLucky(string score) {
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < score.length(); i++) {
        if(i < score.length()/2) {
            sum1 += score[i]-'0';
        } else {
            sum2 += score[i]-'0';
        }
    }
    return sum1 == sum2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string score;
    cin >> score;

    if(isLucky(score)) cout << "LUCKY" << endl;
    else cout << "READY" << endl;

    return 0;
}