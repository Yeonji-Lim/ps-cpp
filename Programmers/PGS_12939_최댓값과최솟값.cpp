#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> split(string input, char delimiter) {
    vector<int> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(stoi(temp));
    }
    return answer;
}

string solution(string s) {
    vector<int> nums = split(s, ' ');
    int min_num = nums[0], max_num = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(min_num > nums[i]) min_num = nums[i];
        if(max_num < nums[i]) max_num = nums[i];
    }
    return to_string(min_num) + " " + to_string(max_num);
}