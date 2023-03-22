// 42747
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    for(int h = citations.size(); h > -1; h--)
        if(citations[citations.size()-h] >= h) return h;
    return 0;
}