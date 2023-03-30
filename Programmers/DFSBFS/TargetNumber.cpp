// 43165
#include <string>
#include <vector>

using namespace std;
vector<int> n;
int t;
int s;

int find(int res, int i) {
    int ans = 0;
    if(i == s-1) {
        if(res+n[i] == t) ans++;
        if(res-n[i] == t) ans++;
        return ans;
    }
    ans += find(res+n[i], i+1);
    ans += find(res-n[i], i+1);
    return ans;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    n = numbers;
    t = target;
    s = n.size();
    return find(0, 0);
}