// /* 상하좌우 */
// #include <iostream>
// #include <string>
// #include <queue>
// using namespace std;

// int n, i = 1, j = 1;
// string com_str;
// queue<char> com;

// bool isInMap(int i, int j) {
//     return (i > 0 && i <= n && j > 0 && j <= n);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
    
//     cin >> n;
//     cin.ignore(10, '\n');
//     getline(cin, com_str, '\n');
//     for(int i = 0; i < 101 && com_str[i]; i++) {
//         if(com_str[i] == ' ') continue;
//         com.push(com_str[i]);
//     }
    
//     i = 1;
//     while(!com.empty()){
//         switch (com.front())
//         {
//         case 'U':
//             if(isInMap(i-1, j)) i--;
//             break;
//         case 'D':
//             if(isInMap(i+1, j)) i++;
//             break;
//         case 'L':
//             if(isInMap(i, j-1)) j--;
//             break;
//         case 'R':
//             if(isInMap(i, j+1)) j++;
//             break;
//         default:
//             break;
//         }
//         com.pop();
//     }
//     cout << i << ' ' << j << endl;
//     return 0;
// }

// /* dx dy로 정형화해도 됨 */

#include <iostream>
#include <vector>
using namespace std;

int N, x = 0, y = 0;
int d[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
char cmd[4] = {'L', 'R', 'U', 'D'};
string plan;

bool isInMap(int i, int j) { return i > -1 && i < N && j > -1 && j < N; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin.ignore();
    getline(cin, plan);
    for(int i = 0; i < plan.length(); i++) {
        if(plan[i] == ' ') continue;
        for(int j = 0; j < 4; j++) {
            if(plan[i] == cmd[j] && isInMap(x+d[j][0], y+d[j][1])) {
                x += d[j][0];
                y += d[j][1];
            }
        }
    }
    cout << ++x << " " << ++y << "\n";
}