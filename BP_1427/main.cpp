#include <iostream>
#include <vector>

using namespace std;

void sortInside(int N) {
    vector<int> result;
    while(N) {
        result.push_back(N%10);
        N = N/10;
    }
    sort(result.begin(), result.end());
    for(int i = result.size()-1; i > -1; i--) {
        cout << result[i];
    }
}

int main() {
    int N;
    cin >> N;
    if(N<1||N>1000000000) return 0;
    sortInside(N);
    return 0;
}
