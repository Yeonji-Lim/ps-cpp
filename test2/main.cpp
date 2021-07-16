#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> nums;

void makeFriends(vector<pair<int, int>> &v, int mi)
{
    v.push_back(nums[mi]);
    int i = nums[mi].first;
    int d = nums[mi].second;
    nums.erase(nums.begin() + mi);

    if (i + d > n && i < nums[0].first)
        return;

    for (int j = 0; j < nums.size(); j++)
    {
        int fi = nums[j].first;
        int fd = nums[j].second;
        if (fi == i + d || fi + fd == i)
            makeFriends(v, j);
    }
}

int main(int argc, char **argv)
{
    int T, test_case, tmp;

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> n;
        vector<vector<pair<int, int>>> fri;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            nums.emplace_back(i, tmp);
        }
        while (!nums.empty())
        {
            vector<pair<int, int>> v;
            makeFriends(v, 0);
            fri.push_back(v);
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << fri.size() << endl;
    }
    return 0;
}