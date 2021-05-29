#include <cstdio>
#include <vector>
using namespace std;

int n;
int main() {
    scanf("%d", &n);
    vector<vector<int>> V;
    vector<int> tmpV;
    int data;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            scanf("%d", &data);
            tmpV.push_back(data);
        }
        V.push_back(tmpV);
        tmpV.clear();
    }
    for(int i=n-2; i>-1; i--) {
        for(int j=0; j<i+1; j++) {
            V[i+1][j] > V[i+1][j+1]? V[i][j]+=V[i+1][j]: V[i][j]+=V[i+1][j+1];
        }
    }
    printf("%d", V[0][0]);
    return 0;
}
