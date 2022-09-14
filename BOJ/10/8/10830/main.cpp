#include <iostream>
#include <vector>
using namespace std;
int N;

vector<vector<int>> squareMod(vector<vector<int>> A, vector<vector<int>> B) {
    int result = 0;
    vector<vector<int>> V(N, vector<int> (N, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                result += (A[i][k] * B[k][j]) ;
            }
            V[i][j] = result % 1000;
            result = 0;
        }
    }
    return V;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long B;
    int data;
    cin >> N >> B;

    vector<int> smlV;
    vector<vector<int>> tempV;
    vector<vector<int>> V(N,vector<int>(N,0));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> data;
            smlV.push_back(data);
            if(i == j) V[i][j] = 1;
        }
        tempV.push_back(smlV);
        smlV.clear();
    }
    while(B) {
        if(B%2) V = squareMod(V, tempV);
        B = B/2;
        tempV = squareMod(tempV, tempV);
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ",V[i][j]);
        }
        printf("\n");
    }
    return 0;
}
