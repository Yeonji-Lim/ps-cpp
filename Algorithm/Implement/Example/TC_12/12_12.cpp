#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool addCheck(vvi ans, vi item) {
    int x = item[0], y = item[1];
    if(item[2] == 0) { //기둥
        return y == 0
            || find(ans.begin(), ans.end(), vi{x, y-1, 0}) != ans.end()
            || find(ans.begin(), ans.end(), vi{x, y, 1}) != ans.end()
            || find(ans.begin(), ans.end(), vi{x-1, y, 1}) != ans.end();
    } else { //보
        return find(ans.begin(), ans.end(), vi{x, y-1, 0}) != ans.end()
            || find(ans.begin(), ans.end(), vi{x+1, y-1, 0}) != ans.end()
            || (find(ans.begin(), ans.end(), vi{x-1, y, 1}) != ans.end()
            && find(ans.begin(), ans.end(), vi{x+1, y, 1}) != ans.end());
    }
}

bool delCheck(vvi ans, vi item) {
    int x = item[0], y = item[1];
    if(item[2] == 0) { //기둥
        ans.erase(find(ans.begin(), ans.end(), vi{x, y, 0}));
        return addCheck(ans, vi{x, y+1, 0})
            && addCheck(ans, vi{x, y+1, 1})
            && addCheck(ans, vi{x-1, y+1, 1});
    } else { //보
        ans.erase(find(ans.begin(), ans.end(), vi{x, y, 1}));
        return addCheck(ans, vi{x, y, 0})
            && addCheck(ans, vi{x+1, y, 0})
            && addCheck(ans, vi{x-1, y, 1})
            && addCheck(ans, vi{x+1, y, 1});
    }
}

bool compare(vi a, vi b) {
    if(a[0] == b[0]) {
        if(a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

vvi solution(int n, vvi build_frame) {
    vvi ans;
    vi item, target;
    for(int i = 0; i < build_frame.size(); i++) {
        item = build_frame[i];
        target = {item[0], item[1], item[2]};
        if(item[3] == 1 && addCheck(ans, item))
            ans.push_back(target);
        else if(item[3] == 0 && delCheck(ans, item))
            ans.erase(find(ans.begin(), ans.end(), target));
    }
    sort(ans.begin(), ans.end(), compare);
    return ans;
}