#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool customSort(string a, string b) {
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

vector<string> v;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    v.resize(N, "0");
    for(int i = 0; i < N; i++) { cin >> v[i]; }

    sort(v.begin(), v.end(), customSort);
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i++) { cout << v[i] << endl; }
    return 0;
}