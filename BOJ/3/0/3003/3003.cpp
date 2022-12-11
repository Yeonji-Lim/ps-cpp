#include <iostream>
using namespace std;

int main(){
    int target[6]={1,1,2,2,2,8};
    int n;
    for (int i = 0; i < 6; i++) {
    	cin >> n;
    	cout << target[i]-n << ' ';
    }
}