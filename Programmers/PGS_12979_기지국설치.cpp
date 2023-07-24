#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, si=1, ei;
    for(int s : stations) {
        ei = s-w;
        if(ei > si) {
            answer += (ei-si)/(2*w+1);
            if((ei-si)%(2*w+1)) answer++;
        }
        si = s+w+1;
    }
    if(stations[stations.size()-1]+w < n){
        ei = n+1;
        answer += (ei-si)/(2*w+1);
        if((ei-si)%(2*w+1)) answer++;
    }
    return answer;
}