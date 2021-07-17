#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int n, m;
int map[100][100];

int max(int a, int b) { return a > b ? a : b; }
bool isInMap(int i, int j) { return (i > -1 && i < n && j > -1 && j < m); }

int squareSum(int si, int sj, int ei, int ej)
{
    int ret = 0;
    if (isInMap(si, sj) && isInMap(ei, ej))
    {
        for (int i = si; i <= ei; i++)
            for (int j = sj; j <= ej; j++)
                ret += map[i][j];
    }
    else
        return -90;
    return ret;
}

int main()
{
    int ans = INT_MIN;
    string tmp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        int k = 0;
        for (int j = 0; j < m; j++)
        {
            if ('0' <= tmp[k] && tmp[k] <= '9')
                map[i][j] = tmp[j] - 48;
            else
                map[i][j] = (-1) * (tmp[++k] - 48);
            k++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == n - 1 && j == m - 1)
                break;
            int fir = squareSum(0, 0, i, j);
            int sec, thr;
            if (i != n - 1 && j != m - 1)
            {
                sec = squareSum(0, j + 1, i, m - 1);
                thr = squareSum(i + 1, 0, n - 1, m - 1);
                ans = max(ans, fir * sec * thr);
                sec = squareSum(0, j + 1, n - 1, m - 1);
                thr = squareSum(i + 1, 0, n - 1, j);
                ans = max(ans, fir * sec * thr);
            }
            else
            {
                int ni = 0;
                int nj = j + 1;
                if (j == m - 1)
                {
                    ni = i + 1;
                    nj = 0;
                }
                for (int k = 0; k < n - ni - 1; k++)
                {
                    sec = squareSum(ni, nj, ni + k, m - 1);
                    thr = squareSum(ni + k + 1, nj, n - 1, m - 1);
                    ans = max(ans, fir * sec * thr);
                }
                for (int k = 0; k < m - nj - 1; k++)
                {
                    sec = squareSum(ni, nj, n - 1, nj + k);
                    thr = squareSum(ni, nj + k + 1, n - 1, m - 1);
                    ans = max(ans, fir * sec * thr);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}