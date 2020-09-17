#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int D (int num) {
    return num + num/1000 + (num - num/1000*1000)/100 + (num - num/100*100)/10 + num%10;
}

int main () {
    vector<int> notResult;
    vector<int> result;
    vector<int>::iterator iter_nr;
    vector<int>::iterator iter_r;
    int dResult;

    for (int num = 1; num <= 10000; num++) {
        iter_nr = find(notResult.begin(), notResult.end(), num);
        if(iter_nr == notResult.end()) //NR에 없는 경우
            result.push_back(num);
        else continue;  //있는 경우 : result가 아니며, 뒤에 것들 다 NR에 있으므로 계산할 필요 없음, 다음 숫자 계산

        dResult = D(num);

        while(dResult <= 10000) {
            iter_nr = find(notResult.begin(), notResult.end(), dResult);
            if(iter_nr == notResult.end()) //NR에 없는 경우
                notResult.push_back(dResult);
            else break;  //있는 경우 : 뒤에 것들 다 NR에 있으므로 계산할 필요 없음
            //while break
            dResult = D(dResult);
        }
    }

    for(iter_r = result.begin(); iter_r < result.end(); iter_r++ ) {
        iter_nr = find(notResult.begin(), notResult.end(), *iter_r);
        if(iter_nr != notResult.end()) {
            result.erase(iter_r);
        }
    }

    for (iter_r = result.begin(); iter_r < result.end(); iter_r++) {
        cout << *iter_r << endl;
    }

    return 0;
}