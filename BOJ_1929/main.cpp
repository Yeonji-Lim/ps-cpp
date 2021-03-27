#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int m, n, tmp, i, j;
    vector<int> v;
    scanf("%d %d", &m, &n);
    if(n%2 == 1) n++;
    for(i = 2; i <= n/2; i++) {
        v.push_back(2*i-1);
        if(2*i-1 >= m) tmp = v.size()-1;
    }
    for(i = tmp; i < v.size(); i++) {
        for(j = 0; j < i; j++) {
            if(v[i]%v[j] == 0) {
                v.erase(v.begin()+i);
                break;
            }
        }
    }
    for(i = tmp; i < v.size(); i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}
