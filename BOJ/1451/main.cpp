#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    string tmp;
    int map[100][100];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = tmp[j] - 48;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}