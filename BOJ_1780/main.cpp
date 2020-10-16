#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> V;
int a=0, b=0, c=0;

void calculate(int x, int y, int n) {
    bool equal = true;
    for(int i = x; i<n+x; i++) {
        for(int j = y; j<n+y; j++) {
            if(V[i][j] != V[x][y]) equal = false;
        }
    }
    if(equal) {
        if(V[x][y] == -1) a++;
        else if(V[x][y] == 0) b++;
        else c++;
        return;
    }
    n = n/3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            calculate(x+i*n, y+j*n, n);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, data;
    vector<int> smlV;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> data;
            smlV.push_back(data);
        }
        V.push_back(smlV);
        smlV.clear();
    }
    calculate(0,0,N);
    printf("%d\n%d\n%d",a,b,c);
    return 0;
}