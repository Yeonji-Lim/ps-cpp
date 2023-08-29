#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int maxi, maxdi, maxpi, tmp, i;
    
    i = deliveries.size()-1;
    while(deliveries[i] == 0) i--;
    maxdi = i+1;
    
    i = pickups.size()-1;
    while(pickups[i] == 0) i--;
    maxpi = i+1;
    
    while(maxdi > 0 && maxpi > 0) {
        maxi = max(maxdi, maxpi);
        answer += maxi*2;
        tmp = cap;
        for(i = maxdi-1; i > -1 && tmp > 0; i--) {
            if(deliveries[i] > 0) {
                if(deliveries[i] > tmp) {
                    deliveries[i] -= tmp;
                    break;
                }
                tmp -= deliveries[i];
                deliveries[i] = 0;
            }
            while(deliveries[i] == 0) {
                maxdi--;
                i--;
            }
            i++;
        }
        tmp = cap;
        for(i = maxpi-1; i > -1 && tmp > 0; i--) {
            if(pickups[i] > 0) {
                if(pickups[i] > tmp) {
                    pickups[i] -= tmp;
                    break;
                }
                tmp -= pickups[i];
                pickups[i] = 0;
            }
            while(pickups[i] == 0) {
                maxpi--;
                i--;
            }
            i++;
        }
    }
    return answer;
}

/*

트럭 용량
각 집마다 배달할 상자 수
각 집마다 빈 상자 수

거리로 이분탐색?
알아야 할 것 : 최대 거리, 해당 거리로 가능한지 확인하는 방법
최대 거리 -> 모두 다 한번씩 간 거리
거리가 주어지면.. 가능한지 확인하는 방법 모르겠음

무조건 최대 용량으로 달리면 최소? -> 회수가 충분히 안될 수 있음 -> 엥 근데 최대한 멀리가서 다 털었다 이런 느낌으로 가야 하는거 아닌가?
멀리있는 집부터 배달하고 회수
0이 된 곳은 갈 곳에서 제외
이러면 최소인 것이 확실?
진짜로 이동하는 걸로 구현? -> 최대 (200000+199999+...)*50
먼데서부터 지우기? 상자 떨어지면 거리 늘어나게 하고.. 음?
가고 나서 다시 물류창고 올 때는 회수 하건말건 일단 물류창고로 돌아와야 함
마지막에도 물류창고로 돌아와야 함
근데 회수가 배달보다 멀리 있으면 어쩔? 제일 먼 배달할 집 보다 제일 먼 회수할 집이 더 멀면? 그러면 배달이든 회수든 제일 먼데를 기점으로 오가는 거리를 정하고, 숫자 --되는거는 뒤에서부터 차례로 

구할 것 : 최소 거리

*/