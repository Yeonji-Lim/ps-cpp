/* Solved - 1984KB 0ms */
//#include <iostream>
//using namespace std;
//
//int Factorial (int num) {
//    if (num == 0) {
//        return 1;
//    }
//    else return Factorial(num-1) * num;
//}
//
//int main() {
//    int num;
//    cin >> num;
//    cout << Factorial(num) << endl;
//    return 0;
//}

/* 2021.3.30 Solved - 1116KB 0ms */
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if(n < 1) { printf("1"); return 0; }
    for(int i = n-1; i > 1 ; i--) { n *= i; }
    printf("%d", n);
    return 0;
}