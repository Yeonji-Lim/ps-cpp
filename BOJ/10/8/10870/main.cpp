#include <iostream>
using namespace std;

int Fibonacci(int num) {
    if(num == 0) return 0;
    else if (num == 1) return 1;
    else return Fibonacci(num-1) + Fibonacci(num-2);
}

int main() {
    int num;
    cin >> num;
    cout << Fibonacci(num);
    return 0;
}
