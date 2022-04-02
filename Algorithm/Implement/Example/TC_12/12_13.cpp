#include <string>
#include <vector>

using namespace std;

vector<int> fixedPoints(int n, vector<int> weak, int start, int dist, bool clkDir)
{
    vector<int> ret;
    if (clkDir)
    {
        if (start + dist < n)
        {
            for (int i = 0; i < weak.size(); i++)
            {
                if (start <= weak[i] && weak[i] <= start + dist)
                    ret.push_back(weak[i]);
            }
        }
        else
        {
            int end = start + dist - n;
            for (int i = 0; i < weak.size(); i++)
            {
                if (weak[i] <= end || start <= weak[i])
                    ret.push_back(weak[i]);
            }
        }
    }
    else
    {
        if (start - dist > -1)
        {
            for (int i = 0; i < weak.size(); i++)
            {
                if (start - dist <= weak[i] && weak[i] <= start)
                    ret.push_back(weak[i]);
            }
        }
        else
        {
            int end = n + start - dist;
            for (int i = 0; i < weak.size(); i++)
            {
                if (weak[i] <= start || end <= weak[i])
                    ret.push_back(weak[i]);
            }
        }
    }
    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 0;
    vector<int> tmp;
    return answer;
}