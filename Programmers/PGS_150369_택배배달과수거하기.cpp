#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int maxi, maxdi = deliveries.size(), maxpi = pickups.size(), tmp;
    
    for(int i = maxdi-1; i > -1; i--) {
        if(deliveries[i] == 0) maxdi--;
        else break;
    }
    for(int i = maxpi-1; i > -1; i--) {
        if(pickups[i] == 0) maxpi--;
        else break;
    }
    
    while(maxdi > 0 && maxpi > 0) {
        maxi = max(maxdi, maxpi);
        answer += maxi*2;
        tmp = cap;
        for(int i = maxdi-1; i > -1 && tmp > 0; i--) {
            if(deliveries[i] > 0) {
                if(deliveries[i] > tmp) {
                    deliveries[i] -= tmp;
                    break;
                }
                tmp -= deliveries[i];
                deliveries[i] = 0;
            }
            maxdi--;
        }
        tmp = cap;
        for(int i = maxpi-1; i > -1 && tmp > 0; i--) {
            if(pickups[i] > 0) {
                if(pickups[i] > tmp) {
                    pickups[i] -= tmp;
                    break;
                }
                tmp -= pickups[i];
                pickups[i] = 0;
            }
            maxpi--;
        }
    }
    return answer;
}