#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int D (int num) {
    int result = num;
    while(num) {
        result += num%10;
        num = num/10;
    }
    return result;
}

int main () {
    vector<int> notResult;
    vector<int> result;
    vector<int>::iterator iter_nr;
    int dOutput;

    for (int num = 1; num <= 10000; num++) {
        iter_nr = find(notResult.begin(), notResult.end(), num);
        if(iter_nr == notResult.end()) //NR에 없는 경우
            result.push_back(num);
        else continue;  //있는 경우 : result가 아니며, 뒤에 것들 다 NR에 있으므로 계산할 필요 없음, 다음 숫자 계산

        dOutput = D(num);
        while(dOutput <= 10000) {
            iter_nr = find(notResult.begin(), notResult.end(), dOutput);
            if(iter_nr == notResult.end()) //NR에 없는 경우
                notResult.push_back(dOutput);
            else break;  //있는 경우 : 뒤에 것들 다 NR에 있으므로 계산할 필요 없음
            //while break
            dOutput = D(dOutput);
        }
    }

    for (int i = 0; i<(int)result.size(); i++) {
        printf("%d\n",result[i]);
    }

    return 0;
}