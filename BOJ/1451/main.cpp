/* 2021.7.17 Failed */

// #include <iostream>
// #include <climits>
// #include <vector>
// using namespace std;
// int n, m;
// int map[100][100];

// int max(int a, int b) { return a > b ? a : b; }
// bool isInMap(int i, int j) { return (i > -1 && i < n && j > -1 && j < m); }

// int squareSum(int si, int sj, int ei, int ej)
// {
//     int ret = 0;
//     if (isInMap(si, sj) && isInMap(ei, ej))
//     {
//         for (int i = si; i <= ei; i++)
//             for (int j = sj; j <= ej; j++)
//                 ret += map[i][j];
//     }
//     else
//         return -90;
//     return ret;
// }

// int main()
// {
//     int ans = INT_MIN;
//     string tmp;
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> tmp;
//         int k = 0;
//         for (int j = 0; j < m; j++)
//         {
//             if ('0' <= tmp[k] && tmp[k] <= '9')
//                 map[i][j] = tmp[j] - 48;
//             else
//                 map[i][j] = (-1) * (tmp[++k] - 48);
//             k++;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (i == n - 1 && j == m - 1)
//                 break;
//             int fir = squareSum(0, 0, i, j);
//             int sec, thr;
//             if (i != n - 1 && j != m - 1)
//             {
//                 sec = squareSum(0, j + 1, i, m - 1);
//                 thr = squareSum(i + 1, 0, n - 1, m - 1);
//                 ans = max(ans, fir * sec * thr);
//                 sec = squareSum(0, j + 1, n - 1, m - 1);
//                 thr = squareSum(i + 1, 0, n - 1, j);
//                 ans = max(ans, fir * sec * thr);
//             }
//             else
//             {
//                 int ni = 0;
//                 int nj = j + 1;
//                 if (j == m - 1)
//                 {
//                     ni = i + 1;
//                     nj = 0;
//                 }
//                 for (int k = 0; k < n - ni - 1; k++)
//                 {
//                     sec = squareSum(ni, nj, ni + k, m - 1);
//                     thr = squareSum(ni + k + 1, nj, n - 1, m - 1);
//                     ans = max(ans, fir * sec * thr);
//                 }
//                 for (int k = 0; k < m - nj - 1; k++)
//                 {
//                     sec = squareSum(ni, nj, n - 1, nj + k);
//                     thr = squareSum(ni, nj + k + 1, n - 1, m - 1);
//                     ans = max(ans, fir * sec * thr);
//                 }
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

/* 2021.8.7 Failed */
// #include <iostream>
// #include <vector>
// using namespace std;
// int n, m, map[101][101], ans = 0;

// int max(int a, int b) { return a > b ? a : b; }

// int sepHV(bool h) {
//     int ret = 1, tmp = 0, a = n, b = m;
//     vector<int> tmpV;
//     if (!h) { a = m; b = n; }
//     for (int i = 0; i < a; i++) {
//         for (int j = 0; j < b; j++)
//             if (h) tmp += map[i][j];
//             else tmp += map[j][i];
//         tmpV.push_back(tmp);
//         tmp = 0;
//     }
//     int fir = 0, sec = 0, thr = 0, t1 = 1, t2 = 2;
//     while (t1 < a - 1) {
//         for (int i = 0; i < t1; i++) fir += tmpV[i];
//         while (t2 < a) {
//             for (int i = t1; i < t2; i++) sec += tmpV[i];
//             for (int i = t2; i < a; i++) thr += tmpV[i];
//             ret = max(fir * sec * thr, ret);
//             sec = 0;
//             thr = 0;
//             t2++;
//         }
//         fir = 0;
//         t2 = ++t1 + 1;
//     }
//     return ret;
// }

// int sepNom(int a, int b) {
//     int ret = 0;
//     int part[4] = {0, 0, 0, 0};
//     for(int i = 0; i < a+1; i++) {
//         for(int j = 0; j < b+1; j++)
//             part[0] += map[i][j];
//         for(int j = b+1; j < m; j++)
//             part[1] += map[i][j];
//     }
//     for(int i = a+1; i < n; i++) {
//         for (int j = 0; j < b+1; j++)
//             part[2] += map[i][j];
//         for (int j = b+1; j < m; j++)
//             part[3] += map[i][j];
//     }

//     ret = max((part[0]+part[1]) * part[2] * part[3], ret);
//     ret = max((part[0]+part[2]) * part[1] * part[3], ret);
//     ret = max((part[2]+part[3]) * part[0] * part[1], ret);
//     ret = max((part[1]+part[3]) * part[0] * part[2], ret);
//     return ret;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> n >> m;
//     string str;
//     for (int i = 0; i < n; i++) {
//         cin >> str;
//         for (int j = 0; j < m; j++) {
//             map[i][j] = str[j] - '0';
//         }
//     }
//     if (n > 2)
//         ans = max(ans, sepHV(true));
//     if (m > 2)
//         ans = max(ans, sepHV(false));
//     if(n > 1 && m >1) {
//         for(int i = 0; i < n-1; i++) 
//             for(int j = 0; j < m-1; j++) 
//                 ans = max(ans, sepNom(i, j));
//     }
//     cout << ans << endl;
//     return 0;
// }

/* 2021.8.7 */
#include <iostream>
using namespace std;

int n, m, ans = 0;
int val[101][101], dp[101][101];
int max (int a, int b) { return a > b? a: b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            val[i][j] = str[j] - '0';
            if(i > 0 && j > 0) dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + val[i][j];
            else if(j > 0) dp[i][j] = dp[i][j-1] + val[i][j];
            else if(i > 0) dp[i][j] = dp[i-1][j] + val[i][j];
            else dp[i][j] = val[i][j];
        }
    }
    int fir, sec, thr, a = 0, b = 1;
    while (a < n - 2) {
        fir = dp[a][m-1];
        while (b < n - 1) {
            sec = dp[b][m-1] - fir;
            thr = dp[n-1][m-1] - dp[b][m-1];
            ans = max(fir * sec * thr, ans);
            b++;
        }
        b = ++a + 1;
    }

    a = 0; b = 1;
    while (a < m - 2) {
        fir = dp[n-1][a];
        while (b < m - 1) {
            sec = dp[n-1][b] - fir;
            thr = dp[n-1][m-1] - dp[n-1][b];
            ans = max(fir * sec * thr, ans);
            b++;
        }
        b = ++a + 1;
    }

    a = 0; b = 0;
    while(a < n - 1) {
        fir = dp[a][m-1];
        while(b < m - 1) {
            sec = dp[n-1][b] - dp[a][b];
            thr = dp[n-1][m-1] - fir - sec;
            ans = max(fir * sec * thr, ans);
            b++;
        }
        b = 0;
        a++;
    }

    a = 0; b = 0;
    while(a < n - 1) {
        while(b < m - 1) {
            fir = dp[a][b];
            sec = dp[a][m-1] - fir;
            thr = dp[n-1][m-1] - fir - sec;
            ans = max(fir * sec * thr, ans);
            b++;
        }
        b = 0;
        a++;
    }

    a = 0; b = 0;
    while(a < m - 1) {
        fir = dp[n-1][a];
        while(b < n - 1) {
            sec = dp[b][m-1] - dp[b][a];
            thr = dp[n-1][m-1] - fir - sec;
            ans = max(fir * sec * thr, ans);
            b++;
        }
        b = 0;
        a++;
    }

    a = 0; b = 0;
    while(a < n - 1) {
        while(b < m - 1) {
            fir = dp[a][b];
            sec = dp[n-1][b] - fir;
            thr = dp[n-1][m-1] - fir - sec;
            ans = max(fir * sec * thr, ans);
            b++;
        }
        b = 0;
        a++;
    }

    cout << ans << endl;
    return 0;
}