// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// int N, all_rst = 0;
// vector<int> cost;
// vector<int> indegree;
// vector<vector<bool>> graph;
// vector<int> rst;
// queue<int> q;

// void push_zero() {
//     for(int x = 1; x <= N; x++) {
//         if(indegree[x] == 0){
//             indegree[x]--;
//             q.push(x);
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N;
//     cost.resize(N+1, 0);
//     indegree.resize(N+1, 0);
//     rst.resize(N+1, 0);
//     graph.push_back(vector<bool>(N+1, false));

//     int i, j, t;
//     for(i = 1; i <= N; i++) {
//         cin >> t;
//         cost[i] = t;
//         vector<bool> tmp(N+1, false);
//         cin >> j;
//         while(j != -1) {
//             indegree[i]++;
//             tmp[j] = true;
//             cin >> j;
//         }
//         graph.push_back(tmp);
//     }

//     push_zero();

//     while(!q.empty()) {
//         i = q.front();
//         q.pop();
//         all_rst += cost[i];
//         cost[i] = all_rst;
//         for(j = 1; j <= N; j++) {
//             if(graph[j][i]){
//                 graph[j][i] = false;
//                 indegree[j]--;
//             }
//         }
//         push_zero();
//     }    

//     for(i = 1; i <= N; i++) {
//         cout << cost[i] << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> indegree;
vector<int> result;
vector<int> cost;
vector<vector<int>> graph;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    indegree.resize(N+1, 0);
    cost.resize(N+1, 0);
    graph.push_back(cost);

    int c, i, j;

    for(int x = 1; x <= N; x++) {
        vector<int> tmp;
        cin >> c;
        cost.push_back(c);
        cin >> i;
        while(i != -1) {
            indegree[x]++;
            tmp.push_back(i);
            cin >> i;
        }
        graph.push_back(tmp);
    }
    
    return 0;
}