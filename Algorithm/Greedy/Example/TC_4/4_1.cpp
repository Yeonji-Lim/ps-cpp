/* 상하좌우 */
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, i = 1, j = 1;
string com_str;
queue<char> com;

bool isInMap(int i, int j) {
    return (i > 0 && i <= n && j > 0 && j <= n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    cin.ignore(10, '\n');
    getline(cin, com_str, '\n');
    for(int i = 0; i < 101 && com_str[i]; i++) {
        if(com_str[i] == ' ') continue;
        com.push(com_str[i]);
    }
    
    i = 1;
    while(!com.empty()){
        switch (com.front())
        {
        case 'U':
            if(isInMap(i-1, j)) i--;
            break;
        case 'D':
            if(isInMap(i+1, j)) i++;
            break;
        case 'L':
            if(isInMap(i, j-1)) j--;
            break;
        case 'R':
            if(isInMap(i, j+1)) j++;
            break;
        default:
            break;
        }
        com.pop();
    }
    cout << i << ' ' << j << endl;
    return 0;
}

/* dx dy로 정형화해도 됨 */