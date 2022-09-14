#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    string str; 
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> M >> str;
        for(int j=0; j<str.length(); j++) {
            for(int k=0; k<M; k++) {
                cout << str[j];
            }
        }
        cout << endl;
    }     
    return 0;
} 