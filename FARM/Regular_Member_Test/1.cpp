/* #1 팩토리얼 구하기 */
#include <iostream>
using namespace std;

int factorial(int n){
    if(n <= 1 ) return 1;
    return n * factorial(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}