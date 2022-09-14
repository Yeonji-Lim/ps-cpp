/* Failed - 메모리 초과*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void countingSort (vector<int> &nums) {
//    vector<int> countResult(1, 0);
//    vector<int> result(nums.size(), 0);
//    int idx;
//    //counting
//    //주의! 최소 숫자가 1
//    for(idx = 0; idx < nums.size(); idx++) {
//        if(countResult.size() < nums[idx]) countResult.resize(nums[idx]);
//        countResult[nums[idx] - 1]++;
//    }
//    for(idx = 1; idx < countResult.size(); idx++) {
//        countResult[idx] += countResult[idx-1];
//    }
//    //print
//    for(idx = 0; idx < countResult.size(); idx++) {
//        cout << idx+1 << " : " << countResult[idx] << endl;
//    }
//    //sort
//    for(idx = 0; idx < nums.size(); idx++) {
//        result[countResult[nums[idx] - 1]-1] = nums[idx];
//        countResult[nums[idx] - 1]--;
//    }
//    for(idx = 0; idx < result.size(); idx++) {
//        cout << result[idx] << endl;
//    }
//    return;
//}
//
//int main() {
//    int N;
//    cin >> N;
//    if(N<1||N>10000000) return 0;
//    vector<int> nums;
//    int num;
//    for (int i = 0; i < N; i++) {
//        cin >> num;
//        if(num<1||num>10000) break;
//        nums.push_back(num);
//    }
//    countingSort(nums);
//    return 0;
//}

/* 2021.3.18 Solved - 1156KB 2708ms */
#include <cstdio>
int numList[10001];

int main() {
    int n, i, tmp, max = 1;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        numList[tmp]++;
        if(max < tmp) max = tmp;
    }
    for(i = 1; i <= max; i++) {
        if(numList[i] != 0) {
            printf("%d\n", i);
            numList[i]--;
            i--;
        }
    }
    return 0;
}