#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> vis;
vector<string> user_id, banned_id;
vector<vector<int>> ansv;

bool checkBad(string user, string ban) {
    if(user.length() != ban.length()) return false;
    for(int i = 0; i < ban.length(); i++) {
        if(ban[i] != '*' && user[i] != ban[i]) return false;
    }
    return true;
}

void dosth(int idx, vector<int> ans) {
    if(idx == banned_id.size()) {
        sort(ans.begin(), ans.end());
        ansv.push_back(ans);
        return;
    }
    for(int i = 0; i < user_id.size(); i++) {
        if(!vis[i] && checkBad(user_id[i], banned_id[idx])) {
            vis[i] = true;
            ans.push_back(i);
            dosth(idx+1, ans);
            ans.pop_back();
            vis[i] = false;
        }
    }
}

int solution(vector<string> u, vector<string> b) {
    user_id = u;
    banned_id = b;
    for(int i = 0; i < user_id.size(); i++) vis.push_back(false);
    vector<int> ans;
    dosth(0, ans);
    sort(ansv.begin(), ansv.end());
    for(int i = 1; i < ansv.size(); i++) {
        if(ansv[i] == ansv[i-1]) {
            ansv.erase(ansv.begin()+i);
            i--;
            continue;
        }
    }
    return (int) ansv.size();
}