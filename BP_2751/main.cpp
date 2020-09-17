#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    int i = 0, j = 0;
    while(true) {
        if(i >= nums1.size() && j >= nums2.size()) break;
        else if( i >= nums1.size()) {
            result.insert(result.end(),nums2.begin(),nums2.end());
            break;
        }
        else if( j >= nums2.size()){
            result.insert(result.end(),nums1.begin(),nums1.end());
            break;
        }
        if(nums1[i] < nums2[j]) {
            result.push_back(nums1[i]);
            i++;
        }
        else {
            result.push_back(nums2[j]);
            j++;
        }
    }
    return result;
}

void sort(vector<int> &nums) {
    if(nums.size() == 1) return;

    vector<int> halfNums1;
    halfNums1.reserve(nums.size()/2);
    vector<int> halfNums2;
    halfNums2.reserve(nums.size() - nums.size()/2);

    for(int i = 0; i < nums.size(); i++) {
        if(i < nums.size()/2) halfNums1.push_back(nums[i]);
        else halfNums2.push_back(nums[i]);
    }
    sort(halfNums1);
    sort(halfNums2);
    nums = merge(halfNums1, halfNums2);
    vector<int> tempVector;
    halfNums1.swap(tempVector);
    halfNums2.swap(tempVector);
    return;
}

int main() {
    int N;
    int num;
    vector<int> nums;
    cin >> N;
    if(N<1 || N>1000000) return 0;
    for(int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}
