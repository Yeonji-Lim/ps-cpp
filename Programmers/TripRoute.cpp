// 43164
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
vector<string> route;
vector<bool> visited;
vector<vector<string>> ts;
bool dfs(string dst) {
    route.push_back(dst);
    if(route.size() == n+1) return true;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && ts[i][0] == dst) {
            visited[i] = true;
            if(dfs(ts[i][1])) return true;
            visited[i] = false;
        }
    }
    route.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    ts = tickets;
    sort(ts.begin(), ts.end());
    n = ts.size();
    visited = vector<bool>(n, false);
    for(int i = 0; i < n; i++) {
        if(ts[i][0] == "ICN") {
            visited[i] = true;
            route.push_back(ts[i][0]);
            if(dfs(ts[i][1])) {
                answer = route;
                break;
            }
            visited[i] = false;
            route.pop_back();
        }
    }
    return answer;
}