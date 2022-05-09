#include <iostream>
using namespace std;
int price[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int priceOf(int length) {
    int ans = 0;
    if(length == 1) { return price[1]; }
    if(length < 11) { ans = price[length]; }
    for(int i = 1; i < length; i++) 
        ans = max(price[i] + priceOf(length-i), ans);
    return ans;
}

int main() {
    for(int length = 1; length < 11; length++) 
        cout << priceOf(length) << " ";
    cout << endl;
    return 0;
}