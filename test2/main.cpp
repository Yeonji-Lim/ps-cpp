/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <cstdio>
#include <iostream>
#include <vector>
#define NSIZE 100000

using namespace std;

int n;
int nums[NSIZE + 2];
bool visited[NSIZE + 2];

void makeFriends(vector<int> &v, int mi)
{
    v.push_back(mi);
    if (nums[mi] + mi <= n && !visited[nums[mi] + mi])
    {
        visited[nums[mi] + mi] = true;
        makeFriends(v, nums[mi] + mi);
    }
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] + i == mi && !visited[i])
        {
            visited[i] = true;
            makeFriends(v, i);
        }
    }
}

int main(int argc, char **argv)
{
    int T, test_case;

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> n;
        vector<vector<int>> fri;
        nums[0] = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            visited[i] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                vector<int> v;
                makeFriends(v, i);
                fri.push_back(v);
            }
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << fri.size() << endl;
    }

    return 0;
}