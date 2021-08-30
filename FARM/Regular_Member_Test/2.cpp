/* #2 리스트의 최대값 삭제 */
#include <iostream>
#include <cstdio>
#include <climits>
#include <string>
#include <vector>
using namespace std;

bool str_to_ili(string str, vector<int>& ili) {
    int tmp = 0, cnt = 0;
    for (int i = 0; cnt < 40 && str[i]; i++) {
        if (str[i] != ' ') {
            tmp = tmp * 10 + str[i] - '0';
        }
        else if (tmp > 0) {
            ili.push_back(tmp);
            tmp = 0;
            cnt++;
        } else { return false; }
    }
    ili.push_back(tmp);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> nums;
    string tmp_str;
    int max_num = INT_MIN, max_idx;

    getline(cin, tmp_str);
    if(str_to_ili(tmp_str, nums)) {

        for(int i = 0; i < nums.size(); i++) {
            if(max_num < nums[i]){
                max_num = nums[i];
                max_idx = i;
            }
        }
        nums.erase(nums.begin()+max_idx);

        for(int i = 0; i < nums.size(); i++) { cout << nums[i] << ' '; }
        cout << endl;
    }
    return 0;
}