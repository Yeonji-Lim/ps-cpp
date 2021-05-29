#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &nums) {
    int minIndex;
    int temp;
    for (int i = 0; i<nums.size(); i++) {
        minIndex = i;
        //최소 값, 그 값의 인덱스 찾기
        for(int j = i+1; j<nums.size(); j++) {
            if(nums[j] < nums[minIndex]) minIndex = j;
        }
        //swap
        temp = nums[minIndex];
        nums[minIndex] = nums[i];
        nums[i] = temp;
    }
}

int main() {
    int N;
    cin >> N;
    if(N > 1000 || N < 1) return 0;
    vector<int> nums;
    int num;
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
