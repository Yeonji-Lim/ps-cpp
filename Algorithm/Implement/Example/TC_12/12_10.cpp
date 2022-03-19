// #include <string>
// #include <vector>

// using namespace std;
// vector<vector<int>> map;
// int zeroCnt = 0;

// bool check(vector<vector<int>> key, int mi, int mj)
// {
//     int M = key.size(), cnt = 0;
//     for (int i = 0; i < M; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             if (key[i][j] == 1)
//             {
//                 if (map[i + mi][j + mj] == 1)
//                     return false;
//                 if (map[i + mi][j + mj] == 0)
//                     cnt++;
//             }
//         }
//     }
//     if (cnt == zeroCnt)
//         return true;
//     return false;
// }

// bool tryAllPosition(vector<vector<int>> key, vector<vector<int>> lock)
// {
//     int N = lock.size(), M = key.size();
//     for (int i = 0; i < N + M - 1; i++)
//     {
//         for (int j = 0; j < N + M - 1; j++)
//         {
//             if (check(key, i, j))
//                 return true;
//         }
//     }
//     return false;
// }

// bool solution(vector<vector<int>> key, vector<vector<int>> lock)
// {
//     int N = lock.size(), M = key.size();
//     map.resize(N + M, vector<int>(N + M, 2));
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             map[i + M - 1][j + M - 1] = lock[i][j];
//             if (lock[i][j] == 0)
//                 zeroCnt++;
//         }
//     }
//     return tryAllPosition(key, lock);
// }