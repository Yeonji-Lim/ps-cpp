/* #2 리스트의 최대값 삭제 */
#include <iostream>
#include <cstdio>
#include <climits>
#include <string>
#include <vector>
using namespace std;

bool chli_to_ili(char chli[], vector<int>& ili) {
    int tmp = 0, cnt = 0;
    for (int i = 0; cnt < 40 && chli[i]; i++) {
        if (chli[i] != ' ') {
            tmp = tmp * 10 + chli[i] - '0';
        }
        else if (tmp > 0) {
            ili.push_back(tmp);
            tmp = 0;
            cnt++;
        } else { return false; }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> nums;
    char tmp_str[40];
    int max_num = INT_MIN, max_idx;

    cin.getline(tmp_str, 40);
    if(chli_to_ili(tmp_str, nums)) {
        for(int i = 0; i < nums.size(); i++) {
            if(max_num < nums[i]){
                max_num = nums[i];
                max_idx = i;
            }
        }
        nums.erase(nums.begin()+max_idx);
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}