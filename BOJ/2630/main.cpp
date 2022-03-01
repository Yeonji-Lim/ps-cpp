#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> V;
vector<int> smlV;
int w=0,b=0;

void calculate(int x, int y, int n) {
    bool equal = true;
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(V[i][j] != V[x][y]) equal = false;
        }
    }
    if(equal) {
        V[x][y] == 0? w++: b++;
        return;
    }
    calculate(x,y,n/2);
    calculate(x,y+n/2,n/2);
    calculate(x+n/2,y,n/2);
    calculate(x+n/2,y+n/2,n/2);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, data;
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
    printf("%d\n%d",w,b);
    return 0;
}
