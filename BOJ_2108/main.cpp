#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void mode (vector<int> &nums) {
    // nums는 정렬된 상태로 들어온다.
    int max = 0;
    int temp = 0;
    vector<int> result = nums;

    // result 원소 삽입 부분 (2번 이상 등장하는 원소에 대해)
    for(int i = 1; i<nums.size(); i++) {

        // 해당 원소가 전의 것과 같다면 빈도 수를 올린다
        if(nums[i] == nums[i-1]) {
            temp++;
        } else {    // 해당 원소가 전의 것과 다르다면, 빈도수를 초기화하고 다음 것을 검사한다
            temp = 0;
            continue;
        }

        // 지금까지 최다 빈도수보다 현재 빈도수가 크다면, 원래 리스트를 비운다 (그리고 최다 빈도수인 원소를 넣는다.)
        if(temp > max) {
            max = temp;
            result.clear();
        } else if(temp < max)
            continue;
        // 현재의 최다 빈도수와 같다면 그냥 push
        result.push_back(nums[i]);
    }

    // 정렬하고 원소가 하나라면 출력, 두 개 이상부터는 뒤에서 두번째로 작은 원소 출력
    sort(result.begin(), result.end());
    if(result.size() == 1) {
        printf("%d\n", result[0]);
    } else {
        printf("%d\n", result[1]);
    }
    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums;
    int num;
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        cin >> num;
        sum += num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());

    printf("%d\n", (int)round(sum/nums.size()));            // 산술평균
    printf("%d\n", nums[nums.size()/2]);                    // 중앙값
    mode(nums);                                         // 최빈값
    printf("%d\n", nums.back() - nums.front());             // 평균
    return 0;
}