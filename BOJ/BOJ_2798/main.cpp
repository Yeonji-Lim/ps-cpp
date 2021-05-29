#include <iostream>
#include <vector>
using namespace std;

int calculate (vector<int> &N, int M) {
    int max = 0;
    for(int i = 0; i < (int)N.size(); i++) {
        for(int j = i + 1; j < (int)N.size(); j++) {
            for(int k = j + 1; k < (int)N.size(); k++) {
                if(M >= N[i] + N[j] + N[k] && max < N[i] + N[j] + N[k]) {
                    max = N[i] + N[j] + N[k];
                    break;
                }
            }
        }
    }
    return max;
}

int main() {
    int N_size, M;
    int input;
    vector<int> N;
    cin >> N_size >> M;
    for(int i = 0; i < N_size; i++) {
        cin >> input;
        N.push_back(input);
    }
    sort(N.rbegin(),N.rend());
    cout << calculate(N,M) << endl;
    return 0;
}

