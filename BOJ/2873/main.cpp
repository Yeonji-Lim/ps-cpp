#include <cstdio>
using namespace std;
int r, c;
int map[1001][1001];
bool visited[1001][1001];

bool isInMap(int x, int y) { return x > -1 && y > -1 && x < r && y < c; }

int main() {
    int i, j;
    scanf("%d %d", &r, &c);
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &map[i][j]);
            visited[i][j] = false;
        }
    }

    if(r%2 == 0 && c%2 == 0) {
        // 최소 찾기
        int min = 1000, mi, mj;
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                if((i+j)%2 == 1 && min > map[i][j]) {
                    min = map[i][j];
                    mi = i;
                    mj = j;
                }
            }
        }
        visited[mi][mj] = true;
        bool goR = true;
        i = 0;
        j = 0;
        while(i != r-1 || j != c-1){
            visited[i][j] = true;
            if(goR) {
                if(isInMap(i-1, j) && !visited[i-1][j]) { //위있으면 위로
                    printf("U");
                    i--;
                } else if(isInMap(i, j+1)) { //오른쪽 맵 안에 있음
                    if(!visited[i][j+1]){ //오른쪽으로 갈 수 있음
                        printf("R");
                        j++;
                    } else { //맵 안에서 오른쪽 막힘
                        visited[i+1][j] = true; //아래로 한칸, 오른쪽으로 한칸
                        printf("DR");
                        i++;
                        j++;
                    }
                } else if(!isInMap(i, j+1)) { //맨 끝임
                    printf("D");
                    i++;
                    goR = false; //방향전환
                }
            } else {
                if(isInMap(i-1, j) && !visited[i-1][j]) { //위있으면 위로
                    printf("U");
                    i--;
                } else if(isInMap(i, j-1)) { //왼쪽 맵 안에 있음
                    if(!visited[i][j-1]){ //왼쪽으로 갈 수 있음
                        printf("L");
                        j--;
                    } else { //맵 안에서 왼쪽 막힘
                        visited[i+1][j] = true; //아래로 한칸, 왼쪽으로 한칸
                        printf("DL");
                        i++;
                        j--;
                    }
                } else if(!isInMap(i, j-1)) { //맨 끝임
                    printf("D");
                    i++;
                    goR = true; //방향전환
                }
            }
        }
    } else if(r%2 == 0) {
        for(i = 0; i < r; i++) {
            if(i%2 == 0) for(j = 1; j < c; j++) printf("D");
            else for(j = 1; j < c; j++) printf("U");
            if(i != r-1) printf("R");
        }
    } else if(c%2 == 0) {
        for(i = 0; i < c; i++) {
            if(i%2 == 0) for(j = 1; j < r; j++) printf("R");
            else for(j = 1; j < r; j++) printf("L");
            if(i != c-1) printf("D");
        }
    } else {
        for(i = 0; i < r; i++) {
            if(i%2 == 0) for(j = 1; j < c; j++) printf("D");
            else for(j = 1; j < c; j++) printf("U");
            if(i != r-1) printf("R");
        }
    }
    return 0;
}
