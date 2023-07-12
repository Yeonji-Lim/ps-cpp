#include <string>
#include <vector>

using namespace std;

vector<int> ans = {0, 0}, dis = {10, 20, 30, 40};
vector<vector<int>> u, e;

void update() {
    int price = 0, mem = 0, total = 0;
    bool join = false;
    for(int i = 0; i < u.size(); i++) {
        join = false;
        price = 0;
        for(int j = 0; j < e.size(); j++) {
            if(e[j][0] < u[i][0]) continue;
            price += e[j][1] * (100-e[j][0]) / 100;
            if(price >= u[i][1]) {
                mem++;
                join = true;
                break;
            }
        }
        if(!join) total += price;
    }
    if(mem > ans[0]) {
        ans[0] = mem;
        ans[1] = total;
    } else if(mem == ans[0] && total > ans[1]) {
        ans[1] = total;
    }
}

void doSth(int ei) {
    if(ei == e.size()) {
        update();
        return;
    }
    for(int i = 0; i < dis.size(); i++) {
        e[ei][0] = dis[i];
        doSth(ei+1);
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    u = users;
    for(int i = 0; i < emoticons.size(); i++) {
        e.push_back(vector<int>{10, emoticons[i]});
    }
    doSth(0);
    return ans;
}