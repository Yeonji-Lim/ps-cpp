/* Solved - 1116KB 0ms */
//#include <cstdio>
//int main() {
//    int n, k, a=0;
//    int A[10];
//    scanf("%d %d",&n,&k);
//    for(int i=0; i<n; i++) {
//        scanf("%d",&A[i]);
//    }
//    for(int j=n-1; j>=0; j--) {
//        a+=k/A[j];
//        k%=A[j];
//    }
//    printf("%d",a);
//    return 0;
//}

/* 2021.5.25 Solved - 1228KB 0ms */
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, k, a, i;
    vector<int> coin;
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%d", &a);
        coin.push_back(a);
    }
    i = coin.size()-1;
    a = 0;
    while(k > 0) {
        a += k/coin[i];
        k -= (k/coin[i])*coin[i];
        i--;
    }
    printf("%d\n", a);
    return 0;
}