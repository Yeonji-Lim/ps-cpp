/* 2021.4.2 Solved - 1116KB 64ms */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        int nums[n+1], rst = 0;
        bool visited[n+1];
        fill(visited, visited+n+1, false);
        for(int j = 1; j <= n; j++) {
            scanf("%d", &nums[j]);
        }
        for(int j = 1; j <= n; j++) {
            if(visited[j]) { continue; }
            if(nums[j] == j) {
                ++rst;
                visited[j] = true;
                continue;
            }
            int tmp = nums[j];
            while(tmp != j) {
                visited[tmp] = true;
                tmp = nums[tmp];
            }
            ++rst;
        }
        printf("%d\n", rst);
    }
    return 0;
}
