/* Solved - 8140KB 672ms */
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
////    vector<int> result;
////    int i = 0, j = 0;
////    while(true) {
////        if(i >= nums1.size() && j >= nums2.size()) break;
////        else if( i >= nums1.size()) {
////            result.insert(result.end(),nums2.begin(),nums2.end());
////            break;
////        }
////        else if( j >= nums2.size()){
////            result.insert(result.end(),nums1.begin(),nums1.end());
////            break;
////        }
////        if(nums1[i] < nums2[j]) {
////            result.push_back(nums1[i]);
////            i++;
////        }
////        else {
////            result.push_back(nums2[j]);
////            j++;
////        }
////    }
////    return result;
////}
////
////void mergeSort(vector<int> &nums) {
////    if(nums.size() == 1) return;
////
////    vector<int> halfNums1;
////    halfNums1.reserve(nums.size()/2);
////    vector<int> halfNums2;
////    halfNums2.reserve(nums.size() - nums.size()/2);
////
////    for(int i = 0; i < nums.size(); i++) {
////        if(i < nums.size()/2) halfNums1.push_back(nums[i]);
////        else halfNums2.push_back(nums[i]);
////    }
////    mergeSort(halfNums1);
////    mergeSort(halfNums2);
////    nums = merge(halfNums1, halfNums2);
////    vector<int> tempVector;
////    halfNums1.swap(tempVector);
////    halfNums2.swap(tempVector);
////    return;
////}
//
//void quickSort(vector<int> &nums) {
//    int pivotIdx = (int)nums.size()/2;
//    vector<int> left;
//    vector<int> right;
//
//    for(int i=0; i<nums.size(); i++) {
//        if(i == pivotIdx) continue;
//        if(nums[i] < nums[pivotIdx]) {
//            left.push_back(nums[i]);
//        } else if(nums[i] > nums[pivotIdx]) {
//            right.push_back(nums[i]);
//        }
//    }
//
//    quickSort(left);
//    quickSort(right);
//
//    nums = left;
//    nums.push_back(nums[pivotIdx]);
//    nums.insert(nums.end(), right.begin(), right.end());
//    left.~vector<int>();
//    new (&left) vector<int>();
//    right.~vector<int>();
//    new (&right) vector<int>();
//}
//
//int main() {
//    int N;
//    int num;
//    cin >> N;
//    vector<int> nums;
//    for(int i = 0; i < N; i++) {
//        cin >> num;
//        nums.push_back(num);
//    }
//    //mergeSort(nums);
//
//    //quickSort(nums);
//
//    sort(nums.begin(),nums.end());
//    for(int i = 0; i < nums.size(); i++) {
//        printf("%d\n",nums[i]);
//    }
//    return 0;
//}

#include <cstdio>
#include <vector>
using namespace std;

vector<int> customSort(vector<int> list) {
    if(list.size() == 1 || list.empty()) return list;
    int p = list[list.size()/2], i;
    vector<int> left, right;
    for(i = 0; i < list.size(); i++) {
        if(list[i] < p) {
            left.push_back(list[i]);
        } else if(list[i] > p) {
            right.push_back(list[i]);
        }
    }
    right = customSort(right);
    left = customSort(left);
    left.push_back(p);
    left.insert(left.end(), right.begin(), right.end());
    for(i = 0; i < right.size(); i++) { right.erase(right.begin()+i); }
    return left;
}

int main() {
    int n, tmp, i;
    vector<int> nums;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        nums.push_back(tmp);
    }
    nums = customSort(nums);
    for(i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}