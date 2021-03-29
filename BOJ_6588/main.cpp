#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a, b;
vector<int> p;

bool isPrime(int n) {
    for(int i = 2; i < n; i++) {
        if(n%i == 0) { return false; }
    }
    return true;
}

bool isCorrect(int n) {
    for(int i = 3; i < n/2; i++) {
        if(isPrime(i)){
            p.push_back(i);
            if(isPrime(n-i)) {
                p.push_back(n-i);
                a = i; b = n-i;
                sort(unique(p.begin(), p.end()), p.end());
                return true;
            }
            sort(unique(p.begin(), p.end()), p.end());
        }
    }
    return false;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    while(n != 0) {
        if(isCorrect(n)) {
            printf("%d = %d + %d\n", n, a, b);
        } else {
            printf("Goldbach's conjecture is wrong.\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
